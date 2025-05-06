#ifndef _LQ_PWM_BLSMOTOR_H_
#define _LQ_PWM_BLSMOTOR_H_


#define Blsmotor_Max 1510  // PWM最大值
#define Blsmotor_Min 510   // PWM最小值
#define Blsmotor_Frequency 50   // PWM频率



#define ATOMBLS1 IfxGtm_ATOM0_5_TOUT15_P00_6_OUT
#define ATOMBLS2 IfxGtm_ATOM1_6_TOUT16_P00_7_OUT

// 定义模块号
typedef enum
{
    BLS1 = 0,  // 舵机1
    BLS2 = 1,  // 舵机2
    BLSALL = 2 // 舵机1&2

} Bls_e;

void BLSmotorInit(void);
void BlsmotorCtrl(Bls_e BLS, uint32 duty);
void TestBlsMotor(void);
#endif
