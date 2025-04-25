/*********************************************************************************************************************
* TC264 Opensourec Library 即（TC264 开源库）是一个基于官方 SDK 接口的第三方开源库
* Copyright (c) 2022 SEEKFREE 逐飞科技
*
* 本文件是 TC264 开源库的一部分
*
* TC264 开源库 是免费软件
* 您可以根据自由软件基金会发布的 GPL（GNU General Public License，即 GNU通用公共许可证）的条款
* 即 GPL 的第3版（即 GPL3.0）或（您选择的）任何后来的版本，重新发布和/或修改它
*
* 本开源库的发布是希望它能发挥作用，但并未对其作任何的保证
* 甚至没有隐含的适销性或适合特定用途的保证
* 更多细节请参见 GPL
*
* 您应该在收到本开源库的同时收到一份 GPL 的副本
* 如果没有，请参阅<https://www.gnu.org/licenses/>
*
* 额外注明：
* 本开源库使用 GPL3.0 开源许可证协议 以上许可申明为译文版本
* 许可申明英文版在 libraries/doc 文件夹下的 GPL3_permission_statement.txt 文件中
* 许可证副本在 libraries 文件夹下 即该文件夹下的 LICENSE 文件
* 欢迎各位使用并传播本程序 但修改内容时必须保留逐飞科技的版权声明（即本声明）
*
* 文件名称          cpu0_main
* 公司名称          成都逐飞科技有限公司
* 版本信息          查看 libraries/doc 文件夹内 version 文件 版本说明
* 开发环境          ADS v1.9.4
* 适用平台          TC264D
* 店铺链接          https://seekfree.taobao.com/
*
* 修改记录
* 日期              作者                备注
* 2022-09-15       pudding            first version
********************************************************************************************************************/
#include "zf_common_headfile.h"
#pragma section all "cpu0_dsram"
// 将本语句与#pragma section all restore语句之间的全局变量都放在CPU0的RAM中

// **************************** 代码区域 ****************************
#define IPS200_TYPE     (IPS200_TYPE_PARALLEL8)                                 // 双排排针 并口两寸屏 这里宏定义填写 IPS200_TYPE_PARALLEL8
#define LED1                    (P20_9)

#define BUZZER_PIN              (P33_10)

#define SERVO_MOTOR_DUTY(x)         ((float)PWM_DUTY_MAX/(1000.0/(float)SERVO_MOTOR_FREQ)*(0.5+(float)(x)/90.0))                                                                         // 单排排针 SPI 两寸屏 这里宏定义填写 IPS200_TYPE_SPI
#define SERVO_MOTOR_PWM             (ATOM1_CH1_P33_9)                           // 定义主板上舵机对应引脚
#define SERVO_MOTOR_FREQ            (300)                                       // 定义主板上舵机频率  请务必注意范围 50-300

#define SERVO_MOTOR_L_MAX           (50 )                                       // 定义主板上舵机活动范围 角度
#define SERVO_MOTOR_R_MAX           (150)                                       // 定义主板上舵机活动范围 角度
#define image      Image_Use

#define MAX_DUTY            (10 )                                               // 最大 MAX_DUTY% 占空比
#define DIR_R1              (P02_4)
#define PWM_R1              (ATOM0_CH5_P02_5)
#define DIR_L1              (P02_6)
#define PWM_L1              (ATOM0_CH7_P02_7)

#define DIR_R2              (P21_2)
#define PWM_R2              (ATOM0_CH1_P21_3)
#define DIR_L2              (P21_4)
#define PWM_L2              (ATOM0_CH3_P21_5)


#define KEY1                    (P11_3)
#define KEY2                    (P11_2)
#define KEY3                    (P20_7)
#define KEY4                    (P20_6)

#define ENCODER_1                   (TIM6_ENCODER)
#define ENCODER_1_A                 (TIM6_ENCODER_CH1_P20_3)
#define ENCODER_1_B                 (TIM6_ENCODER_CH2_P20_0)

#define ENCODER_2                   (TIM5_ENCODER)
#define ENCODER_2_A                 (TIM5_ENCODER_CH1_P10_3)
#define ENCODER_2_B                 (TIM5_ENCODER_CH2_P10_1)
int encoder_data_1 = 0;
int encoder_data_2 = 0;


uint16 delay_time = 0;
uint8 led_state = 0;
int a=0;
int jisu;

int8 duty = 0;
bool dir = true;
int button_z=1;
int button_x=1;

int sumx,sumy,sumz;
int x_m=0,y_m=0,z_m=0;

int count_bao;
int baohupandin=0;
int podaopandin=0;

int Image_Use[60][90];

int Threshold;

float P_duo=1.24,P2_duo=0.04,D_duo=0.55,D2_duo=0.39;   //1.24  0.04  0.55  0.39
int limit_duo;
float duty_duo;
int error_duo=0,lasterror_duo=0;

int i,j;
int line,list,actual;
int zhong[60],piancha[60],pian[60];
int rightline[60];
int leftline[60];
int middleline[60];
int middleline_chushihua=0;
int mubiao1,mubiao2,mubiao3,mubiao4,mubiao5,mubiao6;
float piancha_z=0.0,lastpiancha_z=0.0;
float piancha_jia;

int encoder_data_R=0;
int encoder_data_L=0;
int sum1=0,sum2=0,sum3=0;
int input_speed_R,input_speed_L;
int pwmout_R=0,last_error_R=0,last_last_error_R=0;
int pwmout_L=0,last_error_L=0,last_last_error_L=0;
int error_R,d_error_R,dd_error_R;
int error_L,d_error_L,dd_error_L;
int P_dian=50;
float I_dian=0.12;
int D_dian=0;
float D2_dian=0;
int set_speedr=100,set_speedl=100;
int dutyr,dutyl;

int point_shi1,point_shi2,shizipandin;
int m1,m2,m3,m4,n1,n2,n3,n4;

int s;
double k;
int bu[100];

float acman;

int White_Column[90],Longest_White_Column;
int Longest_White_Column_Left,Longest_White_Column_Right;
int Longest_White_Column_Left_x,Longest_White_Column_Right_x,Longest_White_Column_x;

int point_1;
int point_2;
int point_3;
int point_4;
int point_5;
int yuanhuan_1=1;
int yuanhuan_2=1;
int yuanhuan=0;
int yuanhuanr=0;
int a,a1,a2,a3,a4;
int b,b1,b2,b3,b4;
int c,c1,c2,c3,c4;
int d,d1,d2,d3,d4;
int e,e1,e2,e3,e4;

int weight_count;
const uint8 Weight[60]=
{
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,              //图像最远端00 ——09 行权重
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,              //图像最远端10 ——19 行权重
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,              //图像最远端20 ——29 行权重
        3, 3, 4,5,6,7,8,10,15,20,              //图像最远端30 ——39 行权重
       21,23,18,15,15, 11, 11, 10,9, 8,              //图像最远端40 ——49 行权重
        7, 3, 1, 1, 1, 1, 1, 1, 1, 1,              //图像最远端50 ——59 行权重
};


int isu=0;
int xline=41;
int shizi_flag;
int piany=0;

void chushihua()
{
     gpio_init(BUZZER_PIN, GPO, GPIO_LOW, GPO_PUSH_PULL);                        // 初始化 BUZZER_PIN 输出 默认低电平 推挽输出模式
     gpio_init(LED1, GPO, GPIO_HIGH, GPO_PUSH_PULL);

    ips200_init(IPS200_TYPE);
       ips200_show_string(0, 0, "mt9v03x init.");

       encoder_dir_init(ENCODER_1, ENCODER_1_A, ENCODER_1_B);                      // 初始化编码器模块与引脚 方向解码编码器模式
         encoder_dir_init(ENCODER_2, ENCODER_2_A, ENCODER_2_B);                      // 初始化编码器模块与引脚 方向解码编码器模式

       gpio_init(KEY1, GPI, GPIO_HIGH, GPI_PULL_UP);           // 初始化 KEY1 输入 默认高电平 上拉输入
          gpio_init(KEY2, GPI, GPIO_HIGH, GPI_PULL_UP);           // 初始化 KEY2 输入 默认高电平 上拉输入
          gpio_init(KEY3, GPI, GPIO_HIGH, GPI_PULL_UP);           // 初始化 KEY3 输入 默认高电平 上拉输入
          gpio_init(KEY4, GPI, GPIO_HIGH, GPI_PULL_UP);           // 初始化 KEY4 输入 默认高电平 上拉输入

       pwm_init(SERVO_MOTOR_PWM, SERVO_MOTOR_FREQ, 300);
    //   gpio_init(SERVO_MOTOR_PWM, GPO, 1, GPO_PUSH_PULL);
       gpio_init(DIR_R1, GPO, GPIO_HIGH, GPO_PUSH_PULL);                           // GPIO 初始化为输出 默认上拉输出高
         pwm_init(PWM_R1, 17000, 0);                                                 // PWM 通道初始化频率 17KHz 占空比初始为 0
         gpio_init(DIR_L1, GPO, GPIO_HIGH, GPO_PUSH_PULL);                           // GPIO 初始化为输出 默认上拉输出高
         pwm_init(PWM_L1, 17000, 0);                                                 // PWM 通道初始化频率 17KHz 占空比初始为 0

         gpio_init(DIR_R2, GPO, GPIO_HIGH, GPO_PUSH_PULL);                           // GPIO 初始化为输出 默认上拉输出高
         pwm_init(PWM_R2, 17000, 0);                                                 // PWM 通道初始化频率 17KHz 占空比初始为 0
         gpio_init(DIR_L2, GPO, GPIO_HIGH, GPO_PUSH_PULL);                           // GPIO 初始化为输出 默认上拉输出高
         pwm_init(PWM_L2, 17000, 0);                                                 // PWM 通道初始化频率 17KHz 占空比初始为 0


       while(1)
         {
             if(mt9v03x_init())
               ips200_show_string(0, 80, "mt9v03x reinit.");
             else
               break;
             system_delay_ms(500);// 短延时快速闪灯表示异常
         }
       while(1)
        {
           if(imu660ra_init())
               ips200_show_string(50, 80, "IMU660RA init error.") ;                                // IMU660RA 初始化失败
           else
               break;
           gpio_toggle_level(LED1);                                                 // 翻转 LED 引脚输出电平 控制 LED 亮灭 初始化出错这个灯会闪的很慢
        }
        pit_ms_init(CCU60_CH0, 5);
        pit_ms_init(CCU60_CH1, 5);

         ips200_show_string(0, 16, "init success.");
}

 void buxian(int x1, int y1, int x2, int y2)//补线
 {

//     x1*=2;
//     y1*=2;
//     x2*=2;
//     y2*=2;
     k=(float)(y2-y1)/(x2-x1);
     if((y2-y1)>=(x2-x1))
     {
     for(i=y2;i>y1;i--)
              {
                 bu[i]=x2-(1/k)*(y2-i);
              }
              for(i=y2;i>y1;i--)
              {
                  image[i][bu[i]]=0;
                  image[i][bu[i]-1]=0;
       //           ips200_draw_point     (bu[i], i ,RGB565_BLACK);
              }
     }
     if((y2-y1)<(x2-x1))
       {
       for(i=x2;i>x1;i--)
                {
                   bu[i]=y2-k*(x2-i);
                }
                for(i=x2;i>x1;i--)
                {
                    image[bu[i]][i]=0;
                    image[bu[i]][i-1]=0;
           //         ips200_draw_point    (i, bu[i] ,RGB565_BLACK);
                }
       }
     //////////////////////////////////////
//          x1*=2;
//          y1*=2;
//          x2*=2;
//          y2*=2;
//     k=(float)(y2-y1)/(x2-x1);
//         if((y2-y1)>=(x2-x1))
//         {
//         for(i=y2;i>y1;i--)
//                  {
//                     bu[i]=x2-(1/k)*(y2-i);
//                  }
//                  for(i=y2;i>y1;i--)
//                  {
//                      ips200_draw_point     (bu[i], i ,RGB565_BLACK);
//                  }
//         }
//         if((y2-y1)<(x2-x1))
//           {
//           for(i=x2;i>x1;i--)
//                    {
//                       bu[i]=y2-k*(x2-i);
//                    }
//                    for(i=x2;i>x1;i--)
//                    {
//                        ips200_draw_point    (i, bu[i] ,RGB565_BLACK);
//                    }
//           }
 }


void dajinfa()//大津法
{
    int GrayScale=256;
              uint16 Image_Width  =188;
              uint16 Image_Height =120;
              int X;
              uint16 Y;
              uint8* data = mt9v03x_image;
              int HistGram[GrayScale];

              for (Y = 0; Y < GrayScale; Y++)
               {
                   HistGram[Y] = 0;
               }
               for (Y = 40; Y <Image_Height; Y+=2)
               {

                   for (X = 0; X < Image_Width; X+=2)
                   {
                   HistGram[(int)data[Y*Image_Width + X]]++;
                   }
               }

               uint32 Amount = 0;
               uint32 PixelBack = 0;
               uint32 PixelIntegralBack = 0;
               uint32 PixelIntegral = 0;
               int32 PixelIntegralFore = 0;
               int32 PixelFore = 0;
               double OmegaBack=0, OmegaFore=0, MicroBack=0, MicroFore=0, SigmaB=0, Sigma=0;
               int16 MinValue=0, MaxValue=0;


               for (MinValue = 0; MinValue < 256 && HistGram[MinValue] == 0; MinValue++) ;
               for (MaxValue = 255; MaxValue > MinValue && HistGram[MinValue] == 0; MaxValue--) ;


               for (Y = MinValue; Y <= MaxValue; Y++)
                {
                    Amount += HistGram[Y];
                }

                PixelIntegral = 0;
                for (Y = MinValue; Y <= MaxValue; Y++)
                {
                    PixelIntegral += HistGram[Y] * Y;
                }
                SigmaB = -1;
                for (Y = MinValue; Y < MaxValue; Y++)
                {
                      PixelBack = PixelBack + HistGram[Y];
                      PixelFore = Amount - PixelBack;
                      OmegaBack = (double)PixelBack / Amount;
                      OmegaFore = (double)PixelFore / Amount;
                      PixelIntegralBack += HistGram[Y] * Y;
                      PixelIntegralFore = PixelIntegral - PixelIntegralBack;
                      MicroBack = (double)PixelIntegralBack / PixelBack;
                      MicroFore = (double)PixelIntegralFore / PixelFore;
                      Sigma = OmegaBack * OmegaFore * (MicroBack - MicroFore) * (MicroBack - MicroFore);
                      if (Sigma > SigmaB)
                      {
                          SigmaB = Sigma;
                          Threshold = Y+7;
                          if(Threshold<140){
                              Threshold=140;
                          }
//                          if(Threshold>150){
//                         Threshold=150;
//                                    }
                      }
                }
}
void Get_Use_Image()
{
    short i = 0, j = 0, row = 0, line = 0;

    for (i = 0; i < MT9V03X_H; i+=2)
    {
        for (j = 0; j <= MT9V03X_W; j+=2)
        {
            Image_Use[row][line] = mt9v03x_image[i][j];
            line++;
        }
        line = 0;
        row++;
    }
}
void erzhihua()//二值化
{
   // int Threshold=140;
    for(i=20;i<=59;i++)
                 {
                    for(j=0;j<=89;j++)
                    {
                       if(Image_Use[i][j]<=Threshold)
                       {
                           Image_Use[i][j]=0;//黑色
                       }
                       if(Image_Use[i][j]>Threshold)
                       {
                          Image_Use[i][j]=255;//白色
                       }
                    }
                 }
}


void Bin_Image_Filter (void)
{
    sint16 nr; //行
    sint16 nc; //列

    for (nr = 28; nr < 59; nr++)
    {
        for (nc = 0; nc < 89; nc = nc + 1)
        {
            if ((Image_Use[nr][nc] == 0)//判断黑点上下左右是否有超过2个以上白点
                    && (Image_Use[nr - 1][nc] + Image_Use[nr + 1][nc] + Image_Use[nr][nc + 1] + Image_Use[nr][nc - 1] > (2*255)))
            {
                Image_Use[nr][nc] = 255;
            }
            else if ((Image_Use[nr][nc] == 255)//判断白点上下左右是否有超过2个以上黑点
                    && (Image_Use[nr - 1][nc] + Image_Use[nr + 1][nc] + Image_Use[nr][nc + 1] + Image_Use[nr][nc - 1] < (2*255)))
            {
                Image_Use[nr][nc] = 0;
            }
        }
    }
}
void saoxian6()//扫线
{
//middleline[line]初始赋值
    if(middleline_chushihua==0)
    {
        for(line=20;line<=58;line++)
        {
            middleline[line]=45;
        }
        middleline_chushihua=1;
    }

    for( line=20;line<=58;line++)
             {
                 for( list=middleline[line];list<=89;list++)
                 {
                    if(image[line][list]==255&&image[line][list+1]==0)
                      {
                          rightline[line]=list;
                          break;
                      }
                    if(list==89)
                      {
                          rightline[line]=89;
                      }
                 }
                 for( list=middleline[line];list>=2;list--)
                 {
                    if(image[line][list]==255&&image[line][list-1]==0)
                      {
                          leftline[line]=list;
                          middleline[line]=(rightline[line]+leftline[line])/2;
                          break;
                      }
                    if(list==2)
                      {
                          leftline[line]=0;
                          middleline[line]=(rightline[line]+leftline[line])/2;
                      }
                 }
             }

}
void saoxian()//扫线
{
    for(line=20;line<=58;line++){
     //   image[line][88]=0;
        image[line][89]=0;
        image[line][0]=0;
     //   image[line][2]=0;
    }



    for( line=20;line<=50;line++)
             {
                 for( list=43;list<=88;list++)        ////////扫右线
                 {
                    if(image[line][list]==255&&image[line][list+1]==0)
                      {
                          rightline[line]=list;
                          break;
                      }
                    if(list==88)
                      {
                        rightline[line]=88;
//                        for(i=20;i>=1;i--){
//                            if(image[line][i]==255&&image[line][i+1]==0){
//                                    rightline[line]=i;
//                                     break;
//                            }
//                            if(i==1){
//                                rightline[line]=1;
//                            }
//                        }
                      }
                 }

                 for( list=48;list>=1;list--)       ///////////////扫左线
                 {
                    if(image[line][list]==255&&image[line][list-1]==0)
                      {
                          leftline[line]=list;
                          break;
                      }
                    if(list==1)
                      {
              leftline[line]=1;
//                        for(i=70;i<=89;i++){
//                            if(image[line][i]==255&&image[line][i-1]==0)
//                               {
//                                    leftline[line]=i;
//                                    break;
//                               }
//                            if(i==89){
//                                leftline[line]=89;
//                            }
//                        }
                      }
                 }

                if(leftline[line]>=rightline[line])
                {
                    leftline[line]=1;
                    rightline[line]=88;
                }

             }




    for(i=0;i<=59;i++){
        zhong[i]=(rightline[i]+leftline[i])/2;
    }
    for(i=0;i<=59;i++){
      piancha[i]=zhong[i]-45;
    }

}

void saoxian2()
{
    if(image[58][45]==255){                      //底边中点为白
        for( list=45;list>=1;list--) {
            if(image[58][list]==255&&image[58][list-1]==0)
                                {
                                    leftline[58]=list;
                                    break;
                                }
                              if(list==1)
                                {
                        leftline[58]=1;
                                }
        }
        for( list=45;list<=88;list++)
                       {
                          if(image[58][list]==255&&image[58][list+1]==0)
                            {
                                rightline[58]=list;
                                break;
                            }
                          if(list==88)
                            {
                              rightline[58]=88;
                            }
                       }
    }
    else{
        for( list=80;list>=1;list--) {
                 if(image[58][list]==255&&image[58][list-1]==0)
                                     {
                                         leftline[58]=list;
                                         break;
                                     }
                                   if(list==1)
                                     {
                             leftline[58]=1;
                                     }
             }
             for( list=10;list<=88;list++)
                            {
                               if(image[58][list]==255&&image[58][list+1]==0)
                                 {
                                     rightline[58]=list;
                                     break;
                                 }
                               if(list==88)
                                 {
                                   rightline[58]=88;
                                 }
                            }
    }
   //////////////////////////////////////////////////////////////////////////////////////

    zhong[58]=(leftline[58]+rightline[58])/2;

    for( line=57;line>=25;line--){
        for( list=zhong[line+1];list>=1;list--) {                    ////////////扫左线
            if(image[line][list]==255&&image[line][list-1]==0)
                               {
                        leftline[line]=list;
                         break;
                                }
                        if(list==1)
                          {
                        leftline[line]=1;
                            }
                 }

    for( list=zhong[line+1];list<=88;list++)                            ///////////扫右线
                         {
                            if(image[line][list]==255&&image[line][list+1]==0)
                              {
                                  rightline[line]=list;
                                  break;
                              }
                            if(list==88)
                              {
                                rightline[line]=88;
                              }
                         }
    zhong[line]=(leftline[line]+rightline[line])/2;
    pian[line]=zhong[line]-45;
    }

}

void piancha_zhong()
{
//    mubiao1=(rightline[30]+leftline[30])/2;
//       mubiao2=(rightline[35]+leftline[35])/2;
//       mubiao3=(rightline[40]+leftline[40])/2;
//       mubiao4=(rightline[45]+leftline[45])/2;
//       mubiao5=(rightline[50]+leftline[50])/2;
//       mubiao6=(rightline[55]+leftline[55])/2;
           mubiao1=zhong[30]-45;
           mubiao2=zhong[35]-45;
           mubiao3=zhong[42]-45;
           mubiao4=zhong[45]-45;
           mubiao5=zhong[50]-45;
           mubiao6=zhong[55]-45;
       actual=45;
       if(yuanhuan==0){
       piancha_z=(float)(4*mubiao3+4*mubiao4+4*mubiao5+2*mubiao6+45*0)/11;
       }
       else {
                  piancha_z=(float)(6*mubiao4+8*mubiao5+2*mubiao6+45*0)/10;
       }
if(yuanhuan==5){
    piancha_z=(float)(2*mubiao4+11*mubiao5+3*mubiao6+45*0)/9;
}
       if(piancha_z>40){
              piancha_z=40;
          }
          if(piancha_z<-40){
                piancha_z=-40;
              }
}

void piancha2()
{
//    piancha_z=0;
//    weight_count=0;
//    for(i=58;i>=25;i--)
//     {
//         piancha_z+=(zhong[i]-45)*Weight[i];
//         weight_count+=Weight[i];
//     }
//     piancha_z=piancha_z/weight_count;
    for(line=45;line>=32;line--){
    zhong[line]=(leftline[line]+rightline[line])/2;
        pian[line]=zhong[line]-45;

        if(yuanhuanr>2&&yuanhuanr<6){
            pian[line]=zhong[line]-47;
        }


    }
     piancha_z=(pian[40]+pian[41]+pian[42])/3;
     if(shizi_flag==1){
         piancha_z=pian[xline];
     }

     if(yuanhuan>2&&yuanhuan<6){
         if(piancha_z>-3){
             piancha_z=-3;
         }
     }



     if(piancha_z>40){
               piancha_z=40;
           }
           if(piancha_z<-40){
                 piancha_z=-40;
               }


}

void buxian_shizi()
{
    shizipandin=0;
    if(shizipandin==0&&yuanhuan==0){
    for(point_shi1=55;point_shi1>=25;point_shi1--)
               {
               m1=rightline[point_shi1+3]-rightline[point_shi1];
               m2=rightline[point_shi1+2]-rightline[point_shi1];
               m3=rightline[point_shi1]-rightline[point_shi1-2];
               m4=rightline[point_shi1]-rightline[point_shi1-1];
                   if(m1>5&&m2>2&&m3<5&&m4<4&&rightline[point_shi1+5]>70&&rightline[point_shi1+6]>70&&image[point_shi1+5][75]==255&&image[point_shi1+6][76]==255)
                   {
                       shizipandin=1;
                       break;
                   }
               }
    }
    if(shizipandin==1&&rightline[50]>84&&leftline[50]>10){
        shizipandin=0;
    }
    if(shizipandin==1){
        for(point_shi2=55;point_shi2>=25;point_shi2--)
                  {
                  n1=leftline[point_shi2]-leftline[point_shi2+3];
                  n2=leftline[point_shi2]-leftline[point_shi2+2];
                  n3=leftline[point_shi2-2]-leftline[point_shi2];
                  n4=leftline[point_shi2-1]-leftline[point_shi2];

                      if(n1>7&&n2>2&&n3<5&&n4<4&&leftline[point_shi2+6]<20&&leftline[point_shi2+7]<20&&image[point_shi1+5][15]==255&&image[point_shi1+6][14]==255)
                      {
                          shizipandin=2;
                          break;
                      }
                    }
                   }
    if(shizipandin==1){
        shizipandin=0;
    }
    if(shizipandin==2){

//        if(rightline[point_shi1]<40){
//            rightline[point_shi1]=40;
//        }
//        if(leftline[point_shi2]>50){
//            leftline[point_shi2]=50;
//           }
    //   gpio_set_level(BUZZER_PIN,GPIO_HIGH);
    buxian(leftline[point_shi2],point_shi2,5,55);
    buxian(rightline[point_shi1],point_shi1,86,55);
    saoxian2();
    }
    else{
   //   gpio_set_level(BUZZER_PIN,GPIO_LOW);
    }

}

void shizi_panduan()
{
    if(yuanhuan==0&&yuanhuanr==0)
    {
        if(leftline[xline-2]<3&&leftline[xline-3]<3&&leftline[xline-4]<3&&
           rightline[xline-2]>85&&rightline[xline-3]>85&&rightline[xline-4]>85)
        {
            shizi_flag=1;
        }
    }else{
        shizi_flag=0;
    }
    if((leftline[xline]>4&&leftline[xline-1]>4)||
       (rightline[xline]<84&&rightline[xline-1]<84))
    {
        shizi_flag=0;
    }

    if(shizi_flag==1){
        for(line=45;line>=20;line--)
        {
            if(leftline[line]>10)
            {
                leftline[xline]=leftline[line];
                break;
            }
        }
        for(line=45;line>=20;line--)
        {
            if(rightline[line]<80)
            {
                rightline[xline]=rightline[line];
                break;
            }
        }
    }
}


//void yuanhuanpanduan_zuo()//圆环判断
//{
//
//    if(yuanhuan_1==1&&yuanhuan==0&&shizipandin==0)
//    {
//        for(point_1=56;point_1>=33;point_1--)
//        {
//            a=leftline[point_1+1]-leftline[point_1+3];
//            b=leftline[point_1]-leftline[point_1+2];
//            c=leftline[point_1-3]-leftline[point_1];
//            d=leftline[point_1-4];
//            e=leftline[point_1-5];
//
//            a1=rightline[point_1+4]-rightline[point_1+2];
//            b1=rightline[point_1+2]-rightline[point_1];
//            c1=rightline[point_1]-rightline[point_1-2];
//            d1=rightline[point_1-2]-rightline[point_1-4];
//            if(a>0&&b>0&&c<-7&&d<4&&e<4&&rightline[point_1+1]<88&&rightline[point_1]<88&&rightline[point_1-3]<86&&rightline[point_1-5]<84&&rightline[point_1-7]<81)//&&leftline[point_1-3]<5&&leftline[point_1-4]<5&&leftline[point_1-5]<5&&b1-c1<3&&b1-c1>-3&&c1-d1<3&&c1-d1>-3&&image[point_1][4]==255)
//            {
//                yuanhuan_1=2;
//                break;
//            }
//        }
//    }
//if(yuanhuan_1==2){
//    saoxian();
//}
//
//        if(yuanhuan_1==2&&yuanhuan==0)
//        {
//            for(point_2=point_1;point_2>=15;point_2--)
//            {
//                a=leftline[point_2+2]-leftline[point_2+4];
//                b=leftline[point_2]-leftline[point_2+4];
//                c=leftline[point_2-3]-leftline[point_2];
//
//                a1=rightline[point_2+4]-rightline[point_2+2];
//                b1=rightline[point_2+2]-rightline[point_2];
//                c1=rightline[point_2]-rightline[point_2-2];
//                d1=rightline[point_2-2]-rightline[point_2-4];
//
//                if(b>3&&c<-1&&image[point_2+2][leftline[point_2]]==255&&image[point_2+3][leftline[point_2]]==255)//&&b1-c1<3&&b1-c1>-3&&c1-d1<3&&c1-d1>-3&&image[point_2+3][leftline[point_2]]==255&&image[point_2+4][leftline[point_2]]==255&&rightline[40]<80&&rightline[35]<80)
//                {
//                    yuanhuan=2;
//                    yuanhuan_1=1;
//
//                    sum1=0;
//                    break;
//                }
////                else
////                {
////                    yuanhuan_1=1;
////
////                }
//            }
//            if(yuanhuan!=2){
//                yuanhuan_1=1;
//            }
//        }
//        if(yuanhuan==2&&sum1<=7500)
//        {
//            for(point_2=48;point_2>=27;point_2--)
//            {
//                a2=leftline[point_2+3]-leftline[point_2+6];
//                b2=leftline[point_2]-leftline[point_2+3];
//                c2=leftline[point_2-2]-leftline[point_2];
//                if(b2>0&&c2<0&&image[point_2+2][leftline[point_2]]==255&&image[point_2+3][leftline[point_2]]==255)
//                {
//                    break;
//                }
//            }
//
//            buxian(leftline[point_2],point_2+3,3,55);
//                      saoxian();
//
//        }
//
//           if(yuanhuan==2&&sum1>7500)     ///&&yuanhuan_2==1)
//           {
//               for(point_4=50;point_4>=20;point_4--)
//               {
//                   b=leftline[point_4]-leftline[point_4+2];
//                   c=leftline[point_4-2]-leftline[point_4];
//
//                   if(b>10&&c>0&&image[point_4][45]==255&&image[point_4+2][leftline[point_4]-6]==255)//&&sum1>12000)
//                   {
//                       yuanhuan=3;
//                  //     buxian(leftline[point_4],point_4,75,57);
//                       sum1=0;
//                       break;
//                   }
//               }
//           }
//           if(yuanhuan==2&&sum1>30000&&yuanhuan!=3)
//           {
//               yuanhuan=0;
//           }
//           if(yuanhuan==3)
//             {
//               for(point_4=51;point_4>=30; point_4--)
//               {
//                   b2=leftline[point_4]-leftline[point_4+4];
//                   c2=leftline[point_4-2]-leftline[point_4];
//                   d2=leftline[point_4-3]-leftline[point_4];
//                   e2=leftline[point_4-4]-leftline[point_4];
//                   if(b2>9&&leftline[point_4+2]<5)
//                   {
//                       break;
//                   }
//               }
//               buxian(leftline[point_4],point_4,80,57);
//               saoxian2();
//
//             }
//          if(sum1>11000&&yuanhuan==3)
//          {
//              yuanhuan=4;
//              sum1=0;
//          }
////          if(yuanhuan==4)
////          {
////              saoxian2();
////          }
//          if(yuanhuan==4&&leftline[47]<=13&&leftline[48]<=13&&rightline[47]>=76&&rightline[48]>=76)//&&rightline[86]==186&&rightline[90]==186)//&&image[90][90]==0&&image[90][100]==0)
//          {
//              yuanhuan=5;
//              sum1=0;
//          }
//          if(yuanhuan==5)
//            {
//            buxian(14,37,85,58);
//                     saoxian2();
//
//            }
//          if(yuanhuan==5&&sum1>6600)
//          {
//              sum1=0;
//              yuanhuan=6;
//
//          }
//          if(yuanhuan==6)
//          {
////              for(point_5=50;point_5>=32;point_5--)
////              {
////                  a=leftline[point_5+4]-leftline[point_5+6];
////                  b=leftline[point_5]-leftline[point_5+3];
////                  c=leftline[point_5-2]-leftline[point_5];
////                  d=leftline[point_5-4]-leftline[point_5-2];
////                  if(b>5&&leftline[point_5+3]<4&&c>0)
////                  {
////                      break;
////                  }
////              }
//
//              buxian(40,30,4,55);
//                              saoxian2();
//          }
//          if(yuanhuan==6&&sum1>=10000)
//          {
//              yuanhuan=0;
//          }
////          if(yuanhuan!=0||shizipandin==2){
////              gpio_set_level(BUZZER_PIN,GPIO_HIGH);
////          } else{
////              gpio_set_level(BUZZER_PIN,GPIO_LOW);
////          }
//
//}

void yuanhuanpanduan_zuo2()//圆环判断
{

    if(yuanhuan==0&&yuanhuanr==0&&shizi_flag==0)
    {
        for(point_1=56;point_1>=35;point_1--)
        {
            a=leftline[point_1+1]-leftline[point_1+3];
            b=leftline[point_1]-leftline[point_1+2];
            c=leftline[point_1-2]-leftline[point_1];
            d=leftline[point_1-4];
            e=leftline[point_1-5];


            if(a>0&&b>0&&c<-8&&d<2&&e<2&&rightline[point_1+1]<87&&rightline[point_1]<87
              &&rightline[point_1-2]<87&&rightline[point_1-3]<87)//&&leftline[point_1-3]<5&&leftline[point_1-4]<5&&leftline[point_1-5]<5&&b1-c1<3&&b1-c1>-3&&c1-d1<3&&c1-d1>-3&&image[point_1][4]==255)
            {
                yuanhuan=1;
                sum1=0;
                sum2=0;
                sum3=0;
                sumz=0;
                break;
            }
        }
    }

    if(yuanhuan==1){
        if(rightline[32]>86||rightline[30]>86||rightline[28]>86||rightline[26]>86){
            yuanhuan=0;
        }
    }


        if(yuanhuan==1){   //&&sum3<=17000)

            leftline[40]=11;
            leftline[41]=12;
            leftline[42]=13;

        }

           if(yuanhuan==1&&sum3>20000)     ///&&yuanhuan_2==1)
           {
                   if(leftline[39]<2&&leftline[43]<2&&leftline[47]<2&&
                      leftline[49]<2&&leftline[51]<2&&leftline[53]<2)
                   {
                       yuanhuan=2;
                  //     buxian(leftline[point_4],point_4,75,57);
                       sum1=0;
                       sum2=0;
                       sum3=0;
                   }

           }
           if(yuanhuan==1&&sum3>39000&&yuanhuan!=2)
           {
               yuanhuan=0;
           }
           if(yuanhuan==2)
             {

//               buxian(leftline[point_4],point_4,80,57);
//               saoxian2();
               rightline[40]=64;
               rightline[41]=64;
               rightline[42]=64;



             }
          if(yuanhuan==2&&sum3>10000&&sumz>2000)
          {
              yuanhuan=3;
              sum1=0;
              sum2=0;
              sum3=0;
          }
//          if(yuanhuan==4)
//          {
//              saoxian2();
//          }
          if(yuanhuan==3&&sum3>18000){
              yuanhuan=4;
          }


          if(yuanhuan==4&&sum3>22000&&(rightline[39]>=85&&rightline[43]>=85
           &&rightline[46]>=85&&leftline[43]<3)&&sumz>14000)//&&rightline[86]==186&&rightline[90]==186)//&&image[90][90]==0&&image[90][100]==0)
          {
              yuanhuan=5;
              sum1=0;
              sum2=0;
              sum3=0;
          }
          if(yuanhuan==5)
            {
              rightline[40]=52;
              rightline[41]=52;
              rightline[42]=52;

            }
          if((yuanhuan==5&&(sum3>17000||sumz>21000)))//||(yuanhuan==4&&sumz>20400))
          {
              yuanhuan=6;
              sum1=0;
              sum2=0;
              sum3=0;

          }
          if(yuanhuan==6)
          {
              leftline[xline-1]=rightline[xline-1]-58;
              leftline[xline]=rightline[xline]-58;
              leftline[xline+1]=rightline[xline+1]-58;
          }
          if(yuanhuan==6&&sum3>=20000&&leftline[38]>2&&leftline[45]>2&&leftline[46]>2)
          {
              yuanhuan=0;
          }



//          if(yuanhuan!=0||shizipandin==2){
//              gpio_set_level(BUZZER_PIN,GPIO_HIGH);
//          } else{
//              gpio_set_level(BUZZER_PIN,GPIO_LOW);
//          }

}

void yuanhuanpanduan_you()//圆环判断
{

    if(yuanhuanr==0&&yuanhuan==0&&shizi_flag==0)
    {
        for(point_1=56;point_1>=35;point_1--)
        {
            a=rightline[point_1+1]-rightline[point_1+3];
            b=rightline[point_1]-rightline[point_1+2];
            c=rightline[point_1-2]-rightline[point_1];
            d=rightline[point_1-4];
            e=rightline[point_1-5];


            if(a<0&&b<0&&c>8&&d>86&&e>86&&leftline[point_1+1]>2&&leftline[point_1]>2
              &&leftline[point_1-2]>2&&leftline[point_1-3]>2)//&&leftline[point_1-3]<5&&leftline[point_1-4]<5&&leftline[point_1-5]<5&&b1-c1<3&&b1-c1>-3&&c1-d1<3&&c1-d1>-3&&image[point_1][4]==255)
            {
                yuanhuanr=1;
                sum1=0;
                sum2=0;
                sum3=0;
                sumz=0;
                break;
            }
        }
    }

    if(yuanhuanr==1){
        if(leftline[32]<3||leftline[30]<3||leftline[28]<3||leftline[26]<3){
            yuanhuanr=0;
        }
    }


        if(yuanhuanr==1){   //&&sum3<=17000)

            rightline[40]=76;
            rightline[41]=77;
            rightline[42]=78;

        }

           if(yuanhuanr==1&&sum3>20000)     ///&&yuanhuan_2==1)
           {
                   if(rightline[39]>86&&rightline[43]>86&&rightline[47]>86&&
                      rightline[49]>86&&rightline[51]>86&&rightline[53]>86)
                   {
                       yuanhuanr=2;
                       sum1=0;
                       sum2=0;
                       sum3=0;
                   }

           }
           if(yuanhuanr==1&&sum3>39000&&yuanhuanr!=2)
           {
               yuanhuanr=0;
           }
           if(yuanhuanr==2)
             {


               leftline[40]=29;
               leftline[41]=29;
               leftline[42]=29;



             }
          if(yuanhuanr==2&&sum3>10000&&sumz<-3100)
          {
              yuanhuanr=3;
              sum1=0;
              sum2=0;
              sum3=0;
          }

          if(yuanhuanr==3&&sum3>18000){
              yuanhuanr=4;
          }


          if(yuanhuanr==4&&((sum3>22000&&leftline[38]<3&&leftline[40]<3
           &&leftline[43]<3&&leftline[46]<3&&leftline[50]<3)||sumz<-19000))//&&rightline[86]==186&&rightline[90]==186)//&&image[90][90]==0&&image[90][100]==0)
          {
              yuanhuanr=5;
              sum1=0;
              sum2=0;
              sum3=0;
          }
          if(yuanhuanr==5)
            {
              leftline[40]=41;
              leftline[41]=41;
              leftline[42]=41;

            }
          if((yuanhuanr==5&&sum3>11000)||(yuanhuanr==5&&sumz<-21000))
          {
              yuanhuanr=6;
              sum1=0;
              sum2=0;
              sum3=0;

          }
          if(yuanhuanr==6)
          {
              rightline[40]=leftline[xline-1]+58;
              rightline[41]=leftline[xline]+58;
              rightline[42]=leftline[xline+1]+58;
          }
          if(yuanhuanr==6&&sum3>=20000&&rightline[45]<87&&rightline[46]<87)
          {
              yuanhuanr=0;
          }



//          if(yuanhuan!=0||shizipandin==2){
//              gpio_set_level(BUZZER_PIN,GPIO_HIGH);
//          } else{
//              gpio_set_level(BUZZER_PIN,GPIO_LOW);
//          }

}




void podao()
{
    if(imu660ra_gyro_y>1000&&podaopandin==0){
        podaopandin=1;
        sum1=0;
    }
    if(sum1>11000&&podaopandin==1){
        podaopandin=0;
    }
}

void baohu(){
    count_bao=0;
    for(i=1;i<88;i++){
        if(image[58][i]==0){
            count_bao++;
        }
    }
    for(i=1;i<88;i++){
            if(image[57][i]==0){
                count_bao++;
            }
        }
    if(count_bao>168){
        baohupandin=1;
    }else{
        baohupandin=0;
    }
}


void duoji()
{
    limit_duo=68;
//    P_duo=3.2;
//    D_duo=0.4;

    error_duo=piancha_z;
    duty_duo=P_duo*error_duo+abs(error_duo)*error_duo*P2_duo+D_duo*( error_duo-lasterror_duo)-imu660ra_gyro_z*D2_duo;
    lasterror_duo=error_duo;
    if( duty_duo>limit_duo){
        duty_duo=limit_duo;
          }
         if( duty_duo<-limit_duo){
             duty_duo=-limit_duo;
             }
      //   duty_duo=60;
         pwm_set_duty(SERVO_MOTOR_PWM,775-duty_duo);      //775-duty_duo);   //775  730
}
void button()
{
                   delay_time = 100;

//                   if( !gpio_get_level(KEY4))         // 获取 KEYx 电平为低
//                   {
//
//                       P_duo+=0.05;
//                       system_delay_ms(delay_time);
//                   }
//                   if( !gpio_get_level(KEY3))
//                   {
//                       P_duo-=0.05;
//                            system_delay_ms(delay_time);
//                           }
//                   if( !gpio_get_level(KEY2))
//                         {
//                               D_duo+=0.05;
//                                  system_delay_ms(delay_time);
//                                 }
//                   if( !gpio_get_level(KEY1))
//                     {
//                          D_duo-=0.05;
//                          system_delay_ms(delay_time);
//                             }
                   if( !gpio_get_level(KEY4)&&!gpio_get_level(KEY3)){
                             button_z=1;
                             system_delay_ms(delay_time+60);
                         }
            if(button_z==1){
                             if( !gpio_get_level(KEY4))
                             {

                                 P_duo+=0.05;
                                 system_delay_ms(delay_time);
                             }
                             if( !gpio_get_level(KEY3)&&gpio_get_level(KEY2))
                             {
                                 P_duo-=0.05;
                                      system_delay_ms(delay_time);
                                     }
                             if( !gpio_get_level(KEY2)&&gpio_get_level(KEY1)&&gpio_get_level(KEY3))
                                   {
                                         P2_duo+=0.005;
                                            system_delay_ms(delay_time);
                                           }
                             if( !gpio_get_level(KEY1)&&gpio_get_level(KEY2))
                               {
                                    P2_duo-=0.005;
                                    system_delay_ms(delay_time);
                                       }
                         }
                     if( !gpio_get_level(KEY2)&&!gpio_get_level(KEY1)){
                              button_z=2;
                              system_delay_ms(delay_time+60);
                          }
          if(button_z==2){
                             if( !gpio_get_level(KEY4)&&gpio_get_level(KEY3))
                             {

                                 D_duo+=0.05;
                                 system_delay_ms(delay_time);
                             }
                             if( !gpio_get_level(KEY3)&&gpio_get_level(KEY4))
                             {
                                 D_duo-=0.05;
                                      system_delay_ms(delay_time);
                                     }
                             if( !gpio_get_level(KEY2))
                                   {
                                         D2_duo+=0.04;
                                            system_delay_ms(delay_time);
                                           }
                             if( !gpio_get_level(KEY1))
                               {
                                    D2_duo-=0.04;
                                    system_delay_ms(delay_time);
                                       }
                         }
}

void jiasu()
{
//    if(piancha_z>=0){
//        piancha_jia=piancha_z;
//    }
//    if(piancha_z<0){
//           piancha_jia=-piancha_z;
//       }
//    if(baohupandin==0){
//if(podaopandin==0){
//    if(yuanhuan==0||yuanhuan==6){
//           set_speedr=50-piancha_jia*0.2;
//           set_speedl=50-piancha_jia*0.2;
//       }
//    if(yuanhuan==2||yuanhuan==3){
//        set_speedr=50-piancha_jia*0.2;     //-piancha_jia*54;
//        set_speedl=50-piancha_jia*0.2;       //-piancha_jia*54;
//    }
//    if(yuanhuan==4){
//         set_speedr=50-piancha_jia*0.2;
//         set_speedl=50-piancha_jia*0.2;
//     }
//    if(yuanhuan==5){
//           set_speedr=50-piancha_jia*0.2;
//           set_speedl=50-piancha_jia*0.2;
//       }
//}
//if(podaopandin==1){
//    set_speedr=100;
//    set_speedl=100;
//}
//    }else{
//        set_speedr=0;
//        set_speedl=0;
//    }
//
//    acman=0.41;
//   set_speedr*=(1+acman*tan(0.62*duty_duo*3.1416/180));
//
//    set_speedl*=(1-acman*tan(0.62*duty_duo*3.1416/180));


piany=(pian[xline-5]+pian[xline-6]+pian[xline-7])/3;



isu=130;

//isu=150-abs(piany)*5;
//if(isu<133){
//    isu=133;
//}
//
//if(yuanhuan!=0||yuanhuanr!=0){
//    isu=120;
//}




    if(piancha_z<=0){
    set_speedl=isu+isu*0.7*piancha_z/10;
    set_speedr=isu;
    }
    if(piancha_z>0){
    set_speedl=isu;
    set_speedr=isu-isu*0.7*piancha_z/10;
    }


//if(piancha_z<=2&&piancha_z>=-2){
//        set_speedl=0;
//        set_speedr=0;
//}
//if(piancha_z<-2){
//set_speedl=isu;
//set_speedr=isu-160*0.7*piancha_z/10;
//}
//if(piancha_z>2){
//set_speedl=isu+160*0.7*piancha_z/10;
//set_speedr=isu;
//}


//if(piancha_z<=0){
//set_speedl=isu+isu*0.7*piancha_z/10;
//set_speedr=isu;
//}
//if(piancha_z>0){
//set_speedl=isu;
//set_speedr=isu-isu*0.7*piancha_z/10;
//}


//    set_speedl=40;
//    set_speedr=40;

}

void dianji()
{
              input_speed_R=encoder_data_R;
              input_speed_L=encoder_data_L;
  ///////////////////   右电机    //////////////////
              error_R =set_speedr - input_speed_R;
              d_error_R=error_R-last_error_R;
              dd_error_R = -2*last_error_R+error_R+last_last_error_R;

              pwmout_R+=P_dian*d_error_R +I_dian*error_R+D_dian*dd_error_R-D2_dian*imu660ra_gyro_z;
              last_last_error_R=last_error_R;
              last_error_R = error_R;

//              if(piancha_z<0){
//                       pwmout_R=1200-piancha_z*100;
//                       }else{
//                           pwmout_R=700;
//                       }
//              if(piancha_z<=1&&piancha_z>=-1){
//                  pwmout_R=1200;
//              }


              if(pwmout_R>6000){
                  pwmout_R=6000;
              }
              if(pwmout_R<-6000){
                               pwmout_R=-6000;
                           }

                  if(pwmout_R>=0)
                         {
                           dutyr=pwmout_R;
                         gpio_set_level(DIR_R1, GPIO_LOW);                                  // DIR输出高电平
                         pwm_set_duty(PWM_R1, dutyr* (PWM_DUTY_MAX / 10000));                  // 计算占空比
                         }
                  if(pwmout_R<0)
                       {
                         dutyr=-pwmout_R;
                        gpio_set_level(DIR_R1, GPIO_HIGH);                                  // DIR输出高电平
                    pwm_set_duty(PWM_R1, dutyr* (PWM_DUTY_MAX / 10000));                  // 计算占空比
                           }

    ///////////////////   左电机    //////////////////
                    error_L =set_speedl - input_speed_L;
                     d_error_L=error_L-last_error_L;
                     dd_error_L= -2*last_error_L+error_L+last_last_error_L;

                          pwmout_L+=P_dian*d_error_L +I_dian*error_L+D_dian*dd_error_L+D2_dian*imu660ra_gyro_z;
                       last_last_error_L=last_error_L;
                            last_error_L = error_L;



//                    if(piancha_z>=0){
//                    pwmout_L=1200+piancha_z*100;
//                    }else{
//                        pwmout_L=700;
//                    }
//                    if(piancha_z<=1&&piancha_z>=-1){
//                        pwmout_L=1200;
//                    }


                      if(pwmout_L>6000){
                          pwmout_L=6000;
                       }
                        if(pwmout_L<-6000){
                                      pwmout_L=-6000;
                                    }

                          if(pwmout_L>=0)
                                  {
                                 dutyl=pwmout_L;
                                 gpio_set_level(DIR_L1, GPIO_LOW);                                  // DIR输出高电平
                                 pwm_set_duty(PWM_L1, dutyl* (PWM_DUTY_MAX / 10000));                  // 计算占空比
                                   }
                            if(pwmout_L<0)
                                  {
                                 dutyl=-pwmout_L;
                                 gpio_set_level(DIR_L1, GPIO_HIGH);                                  // DIR输出高电平
                            pwm_set_duty(PWM_L1, dutyl* (PWM_DUTY_MAX / 10000));                  // 计算占空比
                                      }


}



void max_white()
{
    for (j =0; j<=89; j++)
    {
        for (i = 59; i >= 0; i--)
        {
            if(image[i][j]==0)
                break;
            else
                White_Column[j]++;
        }
    }
    Longest_White_Column_Left=0;
    Longest_White_Column_Right=0;
    for(i=0;i<=89;i++)
        {
            if (Longest_White_Column_Left< White_Column[i])
            {
                Longest_White_Column_Left= White_Column[i];
                Longest_White_Column_Left_x= i;
            }
        }
    for(i=89;i>=0;i--)
        {
            if (Longest_White_Column_Right< White_Column[i])
            {
                Longest_White_Column_Right= White_Column[i];
                Longest_White_Column_Right_x= i;
            }
        }
    Longest_White_Column_x=(Longest_White_Column_Left_x+Longest_White_Column_Right_x)/2;
    Longest_White_Column=Longest_White_Column_Left;
}




int core0_main(void)
{
    clock_init();                   // 获取时钟频率<务必保留>
    debug_init();                   // 初始化默认调试串口
    // 此处编写用户代码 例如外设初始化代码等

    chushihua();


    // 此处编写用户代码 例如外设初始化代码等
	cpu_wait_event_ready();         // 等待所有核心初始化完毕

	while (TRUE)
	{
        // 此处编写需要循环执行的代码
	    if(mt9v03x_finish_flag)
	        {
	        button();

//	        dajinfa();
//	        Get_Use_Image();
//	        erzhihua();
//	        Bin_Image_Filter();
//	//        podao();
////	   //     baohu();
//	        saoxian2();
////	        buxian_shizi();
////	    //    yuanhuanpanduan_zuo();
//	        piancha_zhong();
//	        piancha2();
////	        duoji();
//	        jiasu();











	           if( !gpio_get_level(KEY3)&&!gpio_get_level(KEY2)&&button_x==1){
	                                        button_x=2;
	                                        system_delay_ms(300);
	                                    }
	            if( !gpio_get_level(KEY3)&&!gpio_get_level(KEY2)&&button_x==2){
	                                               button_x=1;
	                                               system_delay_ms(300);
	                                           }
	if(button_x==1){
//	    ips200_show_int (0,140,button_x,8);  ips200_show_int (30,140,jisu,8);
	     ips200_show_int (0,160,shizi_flag,8);  ips200_show_int (50,160,yuanhuan,8);  ips200_show_int (100,160, yuanhuanr,8);
	     ips200_show_float(0,180,duty_duo,2,3);   ips200_show_int (80,180,Threshold,8);
	     ips200_show_float(0,200,piancha_z,2,3);
	     ips200_show_int (0,220,leftline[40],8);    ips200_show_int (35,220,zhong[40],8);     ips200_show_int (70,220,rightline[40],8);
//	     ips200_show_float (0,240,P_duo,2,2);   ips200_show_int (70,240,encoder_data_1,8);     ips200_show_int (100,240,sum1,8);     ips200_show_int (160,240,imu660ra_gyro_y,8);
	     ips200_show_float (0,260,P2_duo,2,3);   ips200_show_int (70,260,encoder_data_2,8);     ips200_show_int (100,260,sum2,8);      ips200_show_int (160,260,imu660ra_gyro_z,8);
	     ips200_show_float (0,280,D_duo,2,2);        ips200_show_int (80,280,sum3,8);   ips200_show_int (140,280,sumz,8);
//	     ips200_show_float (0,300,D2_duo,2,2);




	         //            ips200_show_gray_image(0, 0, (const uint8 *)mt9v03x_image, MT9V03X_W, MT9V03X_H, 188, 120, Threshold);

	            //            ips200_show_gray_image(0, 0, (const uint8 *)mt9v03x_image, MT9V03X_W, MT9V03X_H, 188, 120,0);


	}

	if(button_x==2){
	ips200_show_int (30,140,jisu,8);
	}



//	jisu++;
//	if(jisu>10000){
//	    jisu=0;
//	}

	        mt9v03x_finish_flag=0;
	         }

        // 此处编写需要循环执行的代码
	}
}

IFX_INTERRUPT(cc60_pit_ch0_isr, 0, CCU6_0_CH0_ISR_PRIORITY)
{
    interrupt_global_enable(0);                     // 开启中断嵌套
    pit_clear_flag(CCU60_CH0);

    encoder_data_1 = encoder_get_count(ENCODER_1);                              // 获取编码器计数
    encoder_data_R=encoder_data_1;
    encoder_clear_count(ENCODER_1);                                             // 清空编码器计数

    encoder_data_2 = -encoder_get_count(ENCODER_2);                              // 获取编码器计数
    encoder_data_L=encoder_data_2;
    encoder_clear_count(ENCODER_2);                                             // 清空编码器计数

    sum1+=encoder_data_R;
    sum2+=encoder_data_L;
    sum3=sum1+sum2;
    if(sum1>=40000)
          {
             sum1=0;
          }
          if(sum2>=40000)
          {
             sum2=0;
          }
          if(sum3>=80000)
        {
                sum3=0;
            }

          imu660ra_get_gyro();                                                        // 获取 IMU660RA 的角速度测量数值
          if(imu660ra_gyro_x<10&&imu660ra_gyro_x>-10){
              imu660ra_gyro_x=0;
          }
          if(imu660ra_gyro_y<20&&imu660ra_gyro_y>-20){
                  imu660ra_gyro_y=0;
              }
          if(imu660ra_gyro_z<15&&imu660ra_gyro_z>-15){
                  imu660ra_gyro_z=0;
              }


          imu660ra_gyro_z/=50;

          if(imu660ra_gyro_z>z_m){
                 z_m=imu660ra_gyro_z;
             }

      sumz+=imu660ra_gyro_z;


////      dajinfa();
        Get_Use_Image();
        erzhihua();
        Bin_Image_Filter();

        if(shizi_flag==1){
            saoxian();
        }else{
        saoxian2();
        }

//          buxian_shizi();
        shizi_panduan();
    yuanhuanpanduan_zuo2();
    yuanhuanpanduan_you();
//        piancha_zhong();



        piancha2();
        jiasu();

        if(yuanhuan!=0||yuanhuanr!=0||shizi_flag!=0){
   //     if(shizi_flag!=0){
        gpio_set_level(BUZZER_PIN,GPIO_HIGH);
        }else{
        gpio_set_level(BUZZER_PIN,GPIO_LOW);
        }

          dianji();



}



#pragma section all restore
// **************************** 代码区域 ****************************

