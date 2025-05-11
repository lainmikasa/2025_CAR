#ifndef _LQ_PWM_SERRVO_H_
#define _LQ_PWM_SERRVO_H_

#define Servo_Delta 100                                  // 舵机左右转动的差值，与舵机型号，拉杆和舵机臂长有关
#define Servo_Center_Mid 1420*3                             // 舵机直行中值， 710
#define Servo_Left_Max (Servo_Center_Mid + Servo_Delta)  // 舵机左转极限值
#define Servo_Right_Min (Servo_Center_Mid - Servo_Delta) // 舵机右转极限值，此值跟舵机放置方式有关，立式
#define Servo_Frequency 300                               // 舵机PWM频率

#define ATOMSERVO1 IfxGtm_ATOM2_0_TOUT32_P33_10_OUT
#define ATOMSERVO2 IfxGtm_ATOM2_5_TOUT35_P33_13_OUT

#define ATOMSERVO3 IfxGtm_ATOM0_5_TOUT15_P00_6_OUT
#define ATOMSERVO4 IfxGtm_ATOM1_6_TOUT16_P00_7_OUT

// 定义模块号
typedef enum
{
    Servo1 = 0,  // 舵机1
    Servo2 = 1,  // 舵机2
    Servo3 = 2, // 舵机1&2
    Servo4 = 3, // 舵机1&2
    ServoALL = 4 // 舵机1&2

} Servo_e;

void ServoInit(void);
void ServoCtrl(Servo_e Servo, uint32 duty);
void TestServo(void);
#endif
