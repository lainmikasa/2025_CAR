#include "1.h"
#include <cstdio>    // 使用C++标准IO
#include <cstdlib>   // 避免C与C++库冲突

void linearMotor::test() {
    GPIO_LED_Init();
}

void linearMotor::motor(float a) {
    short duty = static_cast<short>(a);  // C++风格类型转换
    char txt[16];
    GPIO_LED_Init();
    GPIO_KEY_Init();
    MotorInit();
    Display_Init();
    Display_CLS(U16_BLACK);
    char msg[] = "Zeno Motor Test";
    Display_showString(0, 0, msg, U16_WHITE, U16_BLACK, 16);

    while (1) {
        // 按键逻辑保持不变
        sprintf(txt, "PWM: %05d", duty);
        Display_showString(0, 5, txt, U16_WHITE, U16_BLACK, 16);
        MotorCtrL(Motor3, duty);
        MotorCtrL(Motor4, duty);
        // LED控制逻辑
    }
}
