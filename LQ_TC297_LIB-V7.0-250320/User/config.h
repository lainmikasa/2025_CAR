#ifndef CONFIG_H
#define CONFIG_H

//========================== 关于电机 ==================================//
// 若要使用7843或7971电机驱动，取消下面这行的注释，并注释掉#define USEDRV8701这行
// #define USE7843or7971
#define USEDRV8701

//========================== 关于屏幕 ==================================//
// 屏幕显示方向选择
// 0或1表示竖屏，2或3表示横屏，此处设置为横屏显示（值为2）
#define USE_HORIZONTAL 0

// 屏幕类型选择
// 以下是各种屏幕类型的定义，根据实际需求取消对应屏幕类型的注释，并注释掉其他屏幕类型的定义
//#define IPS114
//#define IPS130
//#define IPS154
#define IPS200
//#define TFT18
//#define TFT20
//#define OLED

#endif
