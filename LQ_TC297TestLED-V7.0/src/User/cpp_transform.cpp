#include "cpp_transform.h"
#include "1.h"  // 包含原C++类的定义

// 创建全局对象实例（或通过其他方式管理生命周期）
static linearMotor motorInstance;

// 实现包装函数
#ifdef __cplusplus
extern "C" {
#endif

void linearMotor_test(void) {
    motorInstance.test();
}

void linearMotor_motor(float a) {
    motorInstance.motor(a);
}

#ifdef __cplusplus
}
#endif
