#ifndef _1_H_
#define _1_H_

// 确保包含基础类型定义
#include <stdint.h>
#include <Ifx_Types.h>

// 统一C函数声明规范
#ifdef __cplusplus
extern "C" {
#endif

// 包含项目C头文件
#include "LQ_GPIO_LED.h"
#include "LQ_GPIO_KEY.h"
#include "LQ_PWM_Moto.h"
#include "LQ_Display.h"
#include "Cpu/Std/Platform_Types.h"
#include "Stm/Std/IfxStm.h"
#include "stdint.h"
#include <Bsp.h>
#include <CompilerTasking.h>
#include <Ifx_Types.h>
#include <IfxCpu.h>
#include <IfxCpu_IntrinsicsTasking.h>
#include <IfxCpu_Irq.h>
#include <IfxStm_cfg.h>
#include <IfxStm_reg.h>
#include <IfxStm_regdef.h>

void Delay_Ms(uint32 stmms);
void Delay_Us(uint32 stmms);

#ifdef __cplusplus
}
#endif

// 类定义
class linearMotor {
public:
    void test();
    void motor(float a);  // 修正声明
};

#endif /* _1_H_ */
