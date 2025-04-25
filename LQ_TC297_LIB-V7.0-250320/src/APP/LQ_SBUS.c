
#include "include.h"


/***********************************************************
*函 数 名:update_sbus
*设计时间: 2022年07月10日
*设计人(开发人)：
*功能说明: 解析SUBS模块信息
***********************************************************/
unsigned int RIGHTH     = 0;    //右手左右
unsigned int LEFTV      = 0;    //左手上下
unsigned int RIGHTV     = 0;    //右手上下
unsigned int LEFTH      = 0;    //左手左右
unsigned int VRH        = 0;    //H开关
unsigned int VRF        = 0;    //F开关
unsigned int SWC        = 0;    //C开关
unsigned int SWD        = 0;    //D开关
unsigned int SWA        = 0;    //A开关
unsigned int SWB        = 0;    //B开关
unsigned int CHDATA[18];
void update_sbus(void)
{
 /*
    CHDATA[0]= ReadBuff3[0];                                                        //帧头 15=0x0F       100%               140%
    RIGHTH=CHDATA[1]=(ReadBuff3[2] & 0X07)<<8  | ReadBuff3[1];                      //右手水平左中右      0314-1005-1694； 0039-1005-1981
    LEFTV =CHDATA[2]=(ReadBuff3[3] & 0X3F)<<5  | ReadBuff3[2]>>3;                   //左手上下上中下      0306-0994-1693； 0008-0975-1949
    RIGHTV=CHDATA[3]=(ReadBuff3[5] & 0X01)<<10 | ReadBuff3[4]<<2 | ReadBuff3[3]>>6; //右手上下上中下      0306-0999-1693；
    LEFTH =CHDATA[4]=(ReadBuff3[6] & 0X0F)<<7  | ReadBuff3[5]>>1;                   //左手水平左中右      0306-1002-1690；
    SWC   =CHDATA[5]=(ReadBuff3[7] & 0X7F)<<4  | ReadBuff3[6]>>4;                   //VrA左旋钮顺时针左右  0074-1925；      0000-2000
    SWD   =CHDATA[6]=(ReadBuff3[9] & 0X03)<<9  | ReadBuff3[8]<<1 | ReadBuff3[7]>>7; //VrB右旋钮顺时针左右  0074-1925；      0000-2000
    VRH   =CHDATA[7]=(ReadBuff3[10] & 0X1F)<<5 | ReadBuff3[9]>>2;                   //C键上中下          0042-0488-0965； 0000-0488-1008
    VRF   =CHDATA[8]= ReadBuff3[11] <<3 | ReadBuff3[10]>>5;                         //D键上下            0074-1925；      0000-2000
    SWB   =CHDATA[9] =(ReadBuff3[13] & 0X07)<<8  | ReadBuff3[12];                   //SWA左拉杆顺时针左右   0074-1925；      0000-2000
    SWA   =CHDATA[10]=(ReadBuff3[14] & 0X3F)<<5  | ReadBuff3[13]>>3;                //SWB左拉杆顺时针左右   0085-1931；      0000-2000
*/
    RIGHTV=((ReadBuff3[1] | ReadBuff3[2] << 8 ) & 0x07FF);                    //右手水平左中右    432---992---1552
    RIGHTH= ((ReadBuff3[2] >> 3 | ReadBuff3[3] << 5 ) & 0x07FF);                  //右手下中上    432---992---1552
    LEFTH = (ReadBuff3[3] >> 6 | ReadBuff3[4] << 2 | ReadBuff3[5] << 10 ) & 0x07FF; //左手左中右      432---992---1552
    LEFTV =(ReadBuff3[5] >> 1 | ReadBuff3[6] << 7 ) & 0x07FF;                           //左手下中上      432---992---1552
    SWA   =(ReadBuff3[6] >> 4 | ReadBuff3[7] << 4 ) & 0x07FF;                        //SWA-5上中下  192---992---1792
    SWB   = (ReadBuff3[7] >> 7 | ReadBuff3[8] << 1 | ReadBuff3[9] << 9 ) & 0x07FF; //SWB-6上下  192---1792
    SWC   = (ReadBuff3[9] >> 2 | ReadBuff3[10]<< 6) & 0x07FF;                        //SWC-7  192---1792
    SWD   =(ReadBuff3[10]>> 5 | ReadBuff3[11]<< 3) & 0x07FF;                         //SWD-8上中下  192---992---1792
    //SWB   =CHDATA[9] =(ReadBuff3[13] & 0X07)<<8  | ReadBuff3[12];                   //SWA左拉杆顺时针左右   0074-1925；      0000-2000

}

void Test_SBUS(void)
{
    char txt[32];
    unsigned char size = 12;
    Display_Init();
    Display_CLS(U16_WHITE);
    //TFT2SPI_Init(1);               // TFT1.8初始化0:横屏  1：竖屏
    //TFT2SPI_CLS(u16BLACK);         // 清屏

//    UART_InitConfig(UART0_RX_P14_1,UART0_TX_P14_0, 115200); //初始化串口1 打印数据信息
//    UART_InitConfig(UART3_RX_P00_1,UART3_TX_P00_0, 115200); //初始化串口3 接收SBUS信号
    UART_InitConfig(UART1_RX_P20_9,UART1_TX_P15_0, 100000);     //初始化串口3 接收SBUS信号
    GPIO_LED_Init();            //LED初始化
    GPIO_KEY_Init();            //按键初始化

    //TFT2SPI_P8X16Str(0,3,"R9DS TEST", u16RED,u16BLACK);
    while(1)
    {
        //串口1打印数据信息
        //printf("RH:%04d LV:%04d RV:%04d LH:%04d VA:%04d VB:%04d SC:%04d SD:%04d SA:%04d SB:%04d\n"\
               ,RIGHTH,LEFTV,RIGHTV,LEFTH,VRH,VRF,SWC,SWD,SWA,SWB);
        Usart3_Rec_Fini_Flag = 1;   //开始接收
       // sprintf(txt, "variate:%05d", count);                  // 将变量填充到字符串的对应位置，并将字符串存放到txt[]中


        sprintf(txt, "RV:%04d RH:%04d",RIGHTV,RIGHTH);
        Display_showString(0, 2, txt, U16_RED, U16_BLUE, size); // 将txt中 内容显示出来
        sprintf(txt, "LH:%04d LV:%04d",LEFTH,LEFTV);
        Display_showString(0, 3, txt, U16_RED, U16_BLUE, size); // 将txt中 内容显示出来
        sprintf(txt, "SWA:%04d SWB:%04d",SWA,SWB);
        Display_showString(0, 4, txt, U16_RED, U16_BLUE, size); // 将txt中 内容显示出来
        sprintf(txt, "SWC:%04d SWD:%04d",SWC,SWD);
        Display_showString(0, 5, txt, U16_RED, U16_BLUE, size); // 将txt中 内容显示出来


//        LED_Ctrl(LED0, RVS);
        Delay_Ms(10);
//        delayms(100);

    }
}

