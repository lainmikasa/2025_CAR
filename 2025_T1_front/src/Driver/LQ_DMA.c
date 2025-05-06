#include "LQ_DMA.h"
#include <IfxCpu_Irq.h>
#include <IfxCpu.h>
#include <IfxDma.h>
#include <IfxDma_Dma.h>
#include <IfxDma_reg.h>
#include <Platform_Types.h>
#include "include.h"

// 安装中断服务函数，向量号和优先级
IFX_INTERRUPT(DMA_IRQHandler, DMA_VECTABNUM, DMA_PRIORITY);
// 安装中断服务函数
void DMA_IRQHandler(void)
{
    /* 开启CPU中断  否则中断不可嵌套 */
    //    IfxCpu_enableInterrupts();
    DMA_CameraIRQ(PIN_INT2_PRIORITY);
}
/**
 * 摄像头 DMA 配置结构体
 */
Dma_Camera_t g_DmaCameraLinkedList;
/** 摄像头 数据采集完成标志位 */
unsigned char Camera_Flag = 0;

/*LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
@函数名称：void DMA_CameraInitConfig(DMA_Channel_TypeDef* dma_ch,u32 srcStartAddr, u32 dstStartAddr, u32 lqsize)
@功能说明：摄像头DMA传输初始化
@参数说明：srcStartAddr：源地址 IO地址  dstStartAddr：目的地址 摄像头数据缓冲区channel：DMA传输通道 0-12   lqsize：数据长度
@调用方法：DMA_CameraInitConfig(MT9V034_DMA_CH,(u32)GPIOF_BYTE0, (u32)Image_Data, IMAGEH*IMAGEW);
@备    注：注意 DMA传输通道需要和PIX像素中断优先级保持一致（内部调用）
QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ*/
void DMA_CameraInitConfig(unsigned long srcStartAddr, unsigned long dstStartAddr, unsigned long channel)
{
    /* 关闭中断 */
    boolean interruptState = IfxCpu_disableInterrupts();

    /* create module config */
    IfxDma_Dma_Config dmaConfig;
    IfxDma_Dma_initModuleConfig(&dmaConfig, &MODULE_DMA);
    /* initialize module */
    IfxDma_Dma dma;
    IfxDma_Dma_initModule(&dma, &dmaConfig);
    /* initial configuration for all channels */
    IfxDma_Dma_ChannelConfig cfg;
    IfxDma_Dma_initChannelConfig(&cfg, &dma);

    //    cfg.busPriority   = IfxDma_ChannelBusPriority_high;                    //优先级最高
    cfg.requestMode = IfxDma_ChannelRequestMode_oneTransferPerRequest;          // 请求启动一次传输
    cfg.moveSize = IfxDma_ChannelMoveSize_8bit;                                 // 一次move 8bit
    cfg.shadowControl = IfxDma_ChannelShadow_none;                              // 单次模式
    cfg.operationMode = IfxDma_ChannelOperationMode_continuous;                 // 传输完成继续传输
    cfg.hardwareRequestEnabled = TRUE;                                          // 使能硬件触发传输
    cfg.sourceAddress = IFXCPU_GLB_ADDR_DSPR(IfxCpu_getCoreId(), srcStartAddr); // 设置源地址
    cfg.sourceCircularBufferEnabled = TRUE;                                     // 保持源地址不变
    cfg.sourceAddressCircularRange = IfxDma_ChannelIncrementCircular_none;
    cfg.channelId = channel;                     // 设置DMA通道
    cfg.channelInterruptEnabled = TRUE;          // 使能通道中断
    cfg.channelInterruptPriority = DMA_PRIORITY; // DMA中断优先级
    cfg.channelInterruptTypeOfService = DMA_VECTABNUM;
    /* 设置传输表述符 */
    cfg.destinationAddress = IFXCPU_GLB_ADDR_DSPR(IfxCpu_getCoreId(), dstStartAddr);
    /* address to next transaction set */
    cfg.shadowAddress = 0;
    cfg.transferCount = IMAGEH*IMAGEW/2;
    /* transfer first transaction set into DMA channel */
    IfxDma_Dma_initChannel(&g_DmaCameraLinkedList.chn, &cfg);
    /* transfer into linked list storage */
    IfxDma_Dma_initLinkedListEntry((void *)&g_DmaCameraLinkedList.linkedList[0], &cfg);
    IfxCpu_Irq_installInterruptHandler((void *)DMA_IRQHandler, DMA_PRIORITY);
    /* clear service request flag */
    (IfxDma_Dma_getSrcPointer(&g_DmaCameraLinkedList.chn))->B.CLRR = 1;
    IfxDma_clearChannelInterrupt(&MODULE_DMA, channel);
    IfxDma_disableChannelTransaction(&MODULE_DMA, channel);
    IFX_INTERRUPT(DMA_IRQHandler, DMA_VECTABNUM, DMA_PRIORITY);

    /* 开启中断 */
    IfxCpu_restoreInterrupts(interruptState);
}

/* 摄像头DMA传输开启 */
void DMA_CameraStart(unsigned long channel)
{
    if (Camera_Flag == 0) // 检测标志位是否清除   如果没有清除则不进行新的数据采集  避免覆盖未使用数据
    {
        /* DMA 设置传输目的地址  */
        IfxDma_setChannelDestinationAddress(&MODULE_DMA, channel,
                                            (void *)IFXCPU_GLB_ADDR_DSPR(IfxCpu_getCoreId(), &Image_Data[0][0]));
        /* 开启DMA传输  */
        IfxDma_enableChannelTransaction(&MODULE_DMA, channel);
    }
}

/*  DMA传输停止 */
void DMA_CameraStop(unsigned long channel)
{
    /* 开启DMA传输 清除标志位 */
    IfxDma_disableChannelTransaction(&MODULE_DMA, channel);
    Camera_Flag = 0;
}

/* 摄像头DMA传输中断处理函数 */
void DMA_CameraIRQ(unsigned long channel)
{
    /* DMA 摄像头 中断服务函数 */
    Camera_Flag++;
    if (Camera_Flag == 2)
    {
        /* 摄像头一帧数据传输结束 停止dma传输  在场中断中再次开启DMA传输 */
        IfxDma_disableChannelTransaction(&MODULE_DMA, channel);
    }
    else
    {
        /* 清理dma传输请求  */
        (IfxDma_Dma_getSrcPointer(&g_DmaCameraLinkedList.chn))->B.CLRR = 1;

        /* 设置DMA传输源地址 */
        IfxDma_setChannelDestinationAddress(&MODULE_DMA, channel,
                                            (void *)IFXCPU_GLB_ADDR_DSPR(IfxCpu_getCoreId(), &Image_Data[IMAGEH/2][0]));
    }
}
