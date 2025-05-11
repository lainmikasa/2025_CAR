#ifndef _CPP_TRANSFORM_H_
#define _CPP_TRANSFORM_H_

#ifndef CPP_WRAPPER_H
#define CPP_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

// 声明C兼容的函数接口
void linearMotor_test(void);     // 对应 linearMotor::test()
void linearMotor_motor(float a); // 对应 linearMotor::motor(float)

#ifdef __cplusplus
}
#endif

#endif


#endif /* _CPP_TRANSFORM_H_ */
