/*LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
@编   写：龙邱科技
@邮   箱：chiusir@163.com
@编译IDE：AURIX Development Studio 1.9.2及以上版本
@使用平台：北京龙邱智能科技TC297TX核心板和V7母板
@相关信息参考下列地址
    网      站：http://www.lqist.cn
    淘 宝 店 铺：http://longqiu.taobao.com
    程序配套视频：https://space.bilibili.com/95313236
@软件版本：V7.0 版权所有，单位使用请先联系授权

@修改日期：2024-11-23
@修改内容：
@注意事项：
    导入工程的时候路径要为纯英文,不要有空格、特殊符合和中文
QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ*/

//================================ 系统代码 ================================//
#include "include.h"
#include "LQ_PWM_BLDC.h"//头文件
IfxCpu_syncEvent g_cpuSyncEvent = 0; //核心同步所需要的变量

//================================ 用户代码 ================================//

int core0_main(void)
{
    //================================ 系统代码 ================================//
    cpu_init();                         // 等待cpu初始化
    IfxCpu_emitEvent(&g_cpuSyncEvent);  // 等待cpu同步
    IfxCpu_waitEvent(&g_cpuSyncEvent, 1);
    UART_InitConfig(UART0_RX_P14_1, UART0_TX_P14_0, 115200);// 初始化上位机串口
    //UART_InitConfig(UART3_RX_P00_1,UART3_TX_P00_0, 115200); //初始化串口3 接收串口信号
    //UART_InitConfig(UART1_RX_P20_9,UART1_TX_P15_0, 100000); //初始化串口1 接收SBUS信号

    //================================ 用户代码 ================================//
    Tset_GPIO_OUT();       //PASS,测试GPIO，P10.6和P10.5闪灯
    //Test_ADC();            //PASS,测试ADC采样时间 屏幕上显示 ADC采样10K次时间
    //TestMotor();           //PASS,测试4路电机PWM控制
    //Test_GPIO_Extern_Int();//PASS,测试外部第1组中断P15.8，P10.6和P10.5闪灯
    //Test_GPIO_KEY();       //PASS,测试外部按键输入，P22.0--2   按下按键   LED亮
    //LQ_STM_Timer();        //PASS,测试定时中断、闪灯
    //Test_Bluetooth();      //PASS,测试UART0(P14.0RX/P14.1TX)，
    //Test_EEPROM();         //PASS,测试内部EEPROM擦写功能  OLED提示是否写入成功
    //Test_LQ6050_DMP();     //PASS,测试6050DMP,IIC接线   P13_1接SCL  P13_2接SDA
    //Test_CAMERA();         //PASS,测试龙邱神眼摄像头并在屏幕上显示  LQ_CAMERA.h 中选择屏幕
    //Test_SoftFft();        //PASS,测试ILLD库的软件FFT函数
    //TestServo();           //PASS,测试两路舵机
    //TestEncoder();         //PASS,测试编码器，兼容正交解码以及带方向龙邱编码器
    //Test_IIC_Gyro();       //PASS,测试陀螺仪模块,包括MPU6050 9250或者ICM20602 20689 IIC接线   P13_1接SCL  P13_2接SDA
    //Test_SPI_Gyro();       //PASS,测试陀螺仪模块,SPI接线，可直接插到母板陀螺仪接口
    //Test_BD1202();         //PASS,测试GPS模块。 注意，测试的时候一定要把对应串口中断里面加入读取程序，要不然不能正常收到GPS信号, 一定要看一下函数说明
    //Test_IPSLCD();         //PASS,测试龙邱LQ-IPS1.14  135*240屏幕显示，使用P20.14--10，显示字符串、汉字、图片及动态数据
    //TestMotorBLDC();       //PASS,测试2134无刷驱动，接线说明在例程测试函数下
    //Test_SBUS();           //PASS,测试遥控器接收数据
    //TestBlsMotor();        //PASS,测试无感无刷电机驱动
    /* 主循环 */
    while (1)
    {
        Delay_Ms(1000);
    }
}
