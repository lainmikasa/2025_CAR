/*
 * T1_front.c
 *
 *  Created on: 2025年4月9日
 *      Author: NPT_T1.ZenoJ
 */

#include "T1_front.h"

#define KP           3.5f    // 比例系数（根据赛道调整）
#define KP2          3.7f    // 比例系数2（根据赛道调整）
#define BASE_DUTY   875    // 基准占空比
#define MAX_DELTA   800      // 最大占空比变化量

/** 屏幕显示数据再次操作的行驶依赖图像  */
unsigned char Image_Go[60][80];
#define image   Image_Go
unsigned int line,list,actual;
int rightline[60],leftline[60],middleline[60],zhong[60],piancha[60],pian[60];
unsigned int motor_button = 0;//0:待命 1：直线
int delta_duty = 0;
sint16 ECPULSE1 = 0;
sint16 ECPULSE2 = 0;
int duty_right = 0;
int duty_left = 0;
int roundabout_flag = 0;   // 0:无环岛 1:右环岛 2:左环岛 3:十字
int roundabout_counter = 0;
unsigned int jishu_button = 0;
int jishu = 0;
// 加权偏差数组 (i=35~58, 共24个元素)
//const float piancha_weighted[24] = {
//    0.1, 0.1, 0.2, 0.2, 0.3, 0.3,  // i=35~40
//    0.5, 0.6, 0.7, 0.8, 0.9, 1.0,  // i=41~46
//    1.2, 1.4, 1.6, 1.8, 2.0, 2.2,  // i=47~52
//    2.5, 2.8, 3.1, 3.4, 3.7, 4.0   // i=53~58
//};

const float piancha_weighted[36] = {
    0.6, 1.5, 2.3, 2.6, 3.1, 3.8,
    4.2, 4.4, 4.6, 5.0, 5.2, 5.5,
    6.0, 5.7, 5.4, 5.1, 4.8, 4.5,
    4.2, 4.0, 3.8, 3.6, 3.4, 3.2,
    2.2, 2.0, 1.8, 1.6, 1.4, 0.5,
    0.3, 0.3, 0.2, 0.2, 0.1, 0.1
};

typedef struct {
    float target;       // 目标速度（脉冲增量/周期）
    float kp;           // 比例系数
    float ki;           // 积分系数
    float integral;     // 积分项
    int base_duty;      // 基准占空比
} SpeedController;

SpeedController ctrl_left = {
    .target = 62.0f,    // 5ms目标70脉冲（对应50ms 700）
    .kp = 0.9f,
    .ki = 0.01f,
    .base_duty = 825
};

SpeedController ctrl_right = {
    .target = 62.0f,   // 右电机方向相反
    .kp = 0.9f,
    .ki = 0.01f,
    .base_duty = 825
};

void chushihua()
{
    char txt[16];
    GPIO_LED_Init();        //LED初始化
    LED_Ctrl(LEDALL, OFF);  //关闭所有的LED
    GPIO_KEY_Init();        //按键初始化
    GPIO_BEEP_Init();       //蜂鸣器初始化
    LCD_Init();             // LCD初始化  0:横屏  1：竖屏
    LCD_CLS(U16_GRAY);
    sprintf(txt, "Initiating!");             // 将变量填充到字符串的对应位置，并将字符串存放到txt[]中
    LCD_ShowStr_24(3, 11, txt, U16_BLUE, U16_RED); // 显示24*12字符串
    CAMERA_Init(50);
    MotorInit();
    EncInit();
    Delay_Ms(50);
    LCD_CLS(U16_GRAY);
    STM_InitConfig(STM0, STM_Channel_0, 20000); // STM初始化
    STM_InitConfig(STM0, STM_Channel_1, 30000); // STM初始化
    STM_InitConfig(STM1, STM_Channel_0, 200000); // STM初始化

    Delay_Ms(50);
}

void fache()
{
    STM_EnableInterrupt(STM0, STM_Channel_0);//开启1级电机控制中断
    STM_EnableInterrupt(STM0, STM_Channel_1);//开启2级图像处理中断
    STM_EnableInterrupt(STM1, STM_Channel_0);//开启3级图像绘制处理中断
    while(KEY_Read(KEY2) == 1);
    PIN_Write(Beep, 1);
    forward();
    Delay_Ms(500);
    PIN_Write(Beep, 0);
    STM_DisableInterrupt(STM1, STM_Channel_0);
    motor_button = 1;
    while (1)
    {
        if(roundabout_flag == 1 && roundabout_flag == 2) PIN_Write(Beep, 1);
        Delay_Ms(500);
        PIN_Write(Beep, 0);
    }
}

void Smaller_Use_Image()
{
    short i = 0, j = 0, row = 0, line = 0;

    for (i = 0; i < 120; i+=2)
    {
        for (j = 0; j <= 160; j+=2)
        {
            Image_Go[row][line] = Pixle[i][j];
            line++;
        }
        line = 0;
        row++;
    }
}

void Bin_Image_Filter (void)
{
    sint16 nr; //行
    sint16 nc; //列

    for (nr = 22; nr < 60; nr++)
    {
        for (nc = 0; nc < 80; nc++)
        {
            if ((Image_Go[nr][nc] == 0)//判断黑点上下左右是否有超过2个以上白点
                    && (Image_Go[nr - 1][nc] + Image_Go[nr + 1][nc] + Image_Go[nr][nc + 1] + Image_Go[nr][nc - 1] > (2*255)))
            {
                Image_Go[nr][nc] = 255;
            }
            else if ((Image_Go[nr][nc] == 255)//判断白点上下左右是否有超过2个以上黑点
                    && (Image_Go[nr - 1][nc] + Image_Go[nr + 1][nc] + Image_Go[nr][nc + 1] + Image_Go[nr][nc - 1] < (2*255)))
            {
                Image_Go[nr][nc] = 0;
            }
        }
    }
}

//史上最伟大的补线
void draw_guide_line(int start_row, int end_row, int start_col, float slope) {
    for(int line = start_row; line >= end_row; line--) {
        int guide_col = start_col + (int)(slope * (line - start_row));

        // 限制列坐标在有效范围内
        guide_col = (guide_col < 0) ? 0 : (guide_col > 79) ? 79 : guide_col;

        // 左环岛补右边界，右环岛补左边界
        if(roundabout_flag == 2) { // 左环岛
            rightline[line] = 79;  // 强制右边界到最右
            leftline[line] = (guide_col > leftline[line]) ? guide_col : leftline[line];
        }
        else if(roundabout_flag == 1) { // 右环岛
            leftline[line] = 0;    // 强制左边界到最左
            rightline[line] = (guide_col < rightline[line]) ? guide_col : rightline[line];
        }

        // 边界冲突处理
        if(leftline[line] >= rightline[line]) {
            leftline[line] = rightline[line] - 5; // 保持5列宽度
        }
    }
}

void saoxian()//原始扫线，直赛道
{
    unsigned int i = 0;
    for( line=35;line<=58;line++)
             {
                 for( list=40;list<=78;list++)        ////////扫右线
                 {
                    if(image[line][list]==255&&image[line][list+1]==0)
                      {
                          rightline[line]=list;
                          break;
                      }
                    if(list==79)
                      {
                        rightline[line]=79;
                      }
                 }

                 for( list=39;list>=1;list--)       ///////////////扫左线
                 {
                    if(image[line][list]==255&&image[line][list-1]==0)
                      {
                          leftline[line]=list;
                          break;
                      }
                    if(list==0)
                      {
                        leftline[line]=0;
                      }
                 }

                if(leftline[line]>=rightline[line])
                {
                    leftline[line]=0;
                    rightline[line]=79;
                }

             }
    for(i=35;i<=58;i++){
        zhong[i]=(rightline[i]+leftline[i])/2;
        piancha[i]=zhong[i]-40;
    }
}

/**
 * @brief 在Image_Use的60-110行绘制放大后的中线（原图30-55行的zhong[i]坐标放大2倍）
 */
void Draw_Center_Line_Zoom() {
    for (int i = 23; i <= 58; i++) {  // 原图30-55行对应放大后的60-110行
        // 计算放大后的坐标
        int orig_row = 2 * i;         // 放大后的行号（原图行i → 放大后行2i）
        int orig_col = 2 * zhong[i];  // 放大后的列号（原图列zhong[i] → 放大后列2*zhong[i]）

        // 边界检查
        if (orig_row < 46 || orig_row + 1 > 120) continue; // 确保行在58-120范围内
        if (orig_col < 0  || orig_col >= 160) continue;     // 确保列不越界

        // 在放大后的两行绘制垂直线（保持原粗细）
        for (int r = 0; r < 2; r++) {     // 放大后的两行（2i和2i+1）
            int target_row = orig_row + r;
            if (target_row > 110) break;  // 防止行越界
            Image_Use[target_row][orig_col] = 0; // 绘制中线为黑色
        }
    }
}

//图像还原
void Reverse_And_Enlarge_Image() {
    int row, line;
    for (row = 0; row < 60; row++) {
        for (line = 0; line < 80; line++) {
            // 计算原图起始坐标（放大两倍）
            int orig_row = 2 * row;
            int orig_col = 2 * line;

            // 将 Image_Go 的像素值填充到 Image_Use 的 2x2 区域
            Image_Use[orig_row][orig_col] = Image_Go[row][line];
            Image_Use[orig_row][orig_col + 1] = Image_Go[row][line];
            Image_Use[orig_row + 1][orig_col] = Image_Go[row][line];
            Image_Use[orig_row + 1][orig_col + 1] = Image_Go[row][line];
        }
    }
}

// 弯道扫线函数（动态起点+误差抑制）
void saoxian2() {
    // 初始化底行（假设图像高度为59行，从下往上扫）
    const int BOTTOM_ROW = 58;
    const int IMG_CENTER = 40;  // 图像中心列（假设图像宽度为80列，0~79）
    int right_white_count = 0;
    int left_white_count = 0;

    // 步骤1：动态初始化底行边界
    //----------------------------------------------------------------
    // 检测底行中心点是否在路径上（白点）
    if (image[BOTTOM_ROW][IMG_CENTER] == 255) {
        // 情况1：中线有路径，从中心向两侧扫
        // 右边界：从中心向右找白→黑跳变
        for (int col = IMG_CENTER; col <= 78; col++) {
            if (image[BOTTOM_ROW][col] == 255 && image[BOTTOM_ROW][col+1] == 0) {
                rightline[BOTTOM_ROW] = col;
                break;
            }
            if (col == 78) rightline[BOTTOM_ROW] = 78; // 触右边缘
        }
        // 左边界：从中心向左找白→黑跳变
        for (int col = IMG_CENTER; col >= 1; col--) {
            if (image[BOTTOM_ROW][col] == 255 && image[BOTTOM_ROW][col-1] == 0) {
                leftline[BOTTOM_ROW] = col;
                break;
            }
            if (col == 1) leftline[BOTTOM_ROW] = 1; // 触左边缘
        }
    } else {
        // 情况2：中线无路径，扩大搜索范围（应对急弯）
        // 右边界：从右侧80%位置向左扫（优先捕捉右弯）
        for (int col = 64; col >= 16; col--) { // 64=80%*80
            if (image[BOTTOM_ROW][col] == 255 && image[BOTTOM_ROW][col+1] == 0) {
                rightline[BOTTOM_ROW] = col;
                break;
            }
            if (col == 16) rightline[BOTTOM_ROW] = 78; // 保底值
        }
        // 左边界：从左侧20%位置向右扫（优先捕捉左弯）
        for (int col = 16; col <= 64; col++) { // 16=20%*80
            if (image[BOTTOM_ROW][col] == 255 && image[BOTTOM_ROW][col-1] == 0) {
                leftline[BOTTOM_ROW] = col;
                break;
            }
            if (col == 64) leftline[BOTTOM_ROW] = 1; // 保底值
        }
    }

    // 步骤2：从底行向上逐行扫描（58行 到 23行）
    //----------------------------------------------------------------
    for (int line = BOTTOM_ROW-1 ; line >= 23; line--) {
        // 动态起点 = 上一行中心 ± 弯道补偿（防止突然转向）
        int predicted_center = (leftline[line+1] + rightline[line+1]) / 2;
        int search_start = predicted_center;

        // 动态扫描右边界（允许弯道连续变化）
        // 搜索范围：预测中心向右扩展20列，限制在[0,78]（防越界）
        int right_start = (search_start < 58) ? search_start : 58;
        for (int col = right_start; col <= 78; col++) {
            if (image[line][col] == 255 && image[line][col+1] == 0) {
                rightline[line] = col;
                break;
            }
            if (col == 75 && line <=35 ){
                right_white_count++;
            }
            if (col == 78) { // 未找到时的误差抑制
                // 与上一行位置比较，突变过大则用历史值
                rightline[line] = (abs(rightline[line+1] - 78) < 30) ? 78 : rightline[line+1];
            }
        }

        // 动态扫描左边界（同理，向左扩展20列）
        int left_start = (search_start > 20) ? search_start : 20;
        for (int col = left_start; col >= 1; col--) {
            if (image[line][col] == 255 && image[line][col-1] == 0) {
                leftline[line] = col;
                break;
            }
            if (col == 5 && line <=35 ){
                left_white_count++;
            }
            if (col == 1) { // 误差抑制
                leftline[line] = (abs(leftline[line+1] - 1) < 15) ? 1 : leftline[line+1];
            }

        }

        // 冲突处理与平滑（防止左右交叉）
        if (leftline[line] >= rightline[line]) {
            // 使用上一行数据 + 横向插值
            leftline[line] = leftline[line+1] - 2;  // 弯道趋势补偿
            rightline[line] = rightline[line+1] + 2;
            if (leftline[line] < 1) leftline[line] = 1;
            if (rightline[line] > 78) rightline[line] = 78;
        }

        if(roundabout_counter <-1)
        {
            jishu_button = 1;
            if (jishu >= 8000)
            {
                if (roundabout_flag == 2) { // 左环岛
                    // 从(58,79)到(30,34)的引导线，斜率-1.5
                    draw_guide_line(58, 30, 79, -1.5);
                }
                else if (roundabout_flag == 1) { // 右环岛
                    // 从(58,0)到(30,45)的引导线，斜率+1.5
                    draw_guide_line(58, 30, 0, +1.5);
                }
                if(jishu >= 13000) {
                    roundabout_flag = 0;
                    roundabout_counter = 0;
                    jishu = 0;
                    jishu_button = 0;
                }
            }
        }
        // 计算中心与偏移（可加入低通滤波）
        zhong[line] = (leftline[line] + rightline[line]) / 2;
        piancha[line] = zhong[line] - IMG_CENTER;

        // 弯道趋势预测（为下一行补偿）
        if (piancha[line] > 10) {  // 右弯趋势，下一行右边界起点左移
            right_start -= 2;
        } else if (piancha[line] < -10) {  // 左弯趋势，左边界起点右移
            left_start += 2;
        }
        if(roundabout_flag == 0)
        {
            if(right_white_count >= 5 && left_white_count < 5)
            {
                roundabout_flag = 1;
                roundabout_counter++;
            }
            else if(left_white_count >= 5 && right_white_count < 5)
            {
                roundabout_flag = 2;
                roundabout_counter++;
            }
            else if(right_white_count >= 5 && left_white_count >= 5) roundabout_flag = 3;
            else
            {
                roundabout_flag = 0;
                roundabout_counter = 0;
            }
        }
    }
}

void stop()
{
    MotorCtrL(Motor3, 0);
    MotorCtrL(Motor4, 0);
}

void forward()
{
    short duty = 1000;
    MotorCtrL(Motor3, duty);//右电机
    MotorCtrL(Motor4, duty);//左电机
}

// 电机控制函数（根据加权偏差调整占空比）
void motor_control_by_piancha() {
    float total_piancha = 0.0;

    float wanqu = 0.0;
    // 计算加权总偏差（i=23~58对应数组索引0~30）
    for(int i=0; i<36; i++) {
        // 当前行的偏差值 * 权重
        total_piancha += piancha[i+35] * piancha_weighted[i];
        wanqu+=abs(piancha[i+35]);
    }

    // 计算占空比变化量（带方向）
    delta_duty = (int)(KP * total_piancha);

    // 限制变化量范围
    delta_duty = (delta_duty > MAX_DELTA) ? MAX_DELTA :
                 (delta_duty < -MAX_DELTA) ? -MAX_DELTA : delta_duty;

    // 更新电机占空比
    if(total_piancha >= 0) {  // 中线偏右，左转
        MotorCtrL(Motor3, BASE_DUTY - delta_duty); // 右电机减速
        MotorCtrL(Motor4, BASE_DUTY + delta_duty); // 左电机加速
    }
    else if(total_piancha < 0) {  // 中线偏左，右转
        MotorCtrL(Motor3, BASE_DUTY - delta_duty); // 右电机加速
        MotorCtrL(Motor4, BASE_DUTY + delta_duty); // 左电机减速
    }
    else {  // 直行
        forward();
    }
}

int speed_pid_control(SpeedController *ctrl, float actual) {
    float error = ctrl->target - actual;

    // 积分抗饱和
    ctrl->integral += error;
    if(fabs(ctrl->integral) > 1000) ctrl->integral *= 0.8f;

    // PID计算
    float output = ctrl->kp * error +
                  ctrl->ki * ctrl->integral;

    return ctrl->base_duty + (int)output;
}

void super_motor_control()
{
    static sint16 last_left = 0, last_right = 0;
    float total_piancha = 0.0;

    // 计算加权总偏差（i=29~58对应数组索引0~23）
    for(int i=0; i<36; i++) {
    // 当前行的偏差值 * 权重
       total_piancha += piancha[i+35] * piancha_weighted[i];
    }

    // 获取编码器增量
    ECPULSE1 = ENC_GetCounter(ENC1_InPut_P33_7);
    ECPULSE2 = ENC_GetCounter(ENC2_InPut_P02_8);
    last_left  = ECPULSE1;
    last_right = ECPULSE2;
    if(jishu_button == 1)
    {
        jishu += ECPULSE1;
    }
    // 视觉控制动态调整基准速度
    float speed_adjust = KP2 * total_piancha; // 使用原有视觉偏差计算
    if(speed_adjust>=0)
    {
        ctrl_left.target  = 46.0f + speed_adjust*0.9;
        ctrl_right.target = 46.0f - speed_adjust*1.5;
    }
    else
    {
        ctrl_left.target  = 46.0f + speed_adjust*1.5;
        ctrl_right.target = 46.0f - speed_adjust*0.9;
    }
    // 执行PID控制
    duty_left  =  speed_pid_control(&ctrl_left  , ECPULSE1);
    duty_right =  speed_pid_control(&ctrl_right , ECPULSE2); // 右电机取反
    if(duty_left >=1500) duty_left = 1500;
    if(duty_left <=400) duty_left = 400;
    if(duty_right >=1500) duty_right = 1500;
    if(duty_right <=400) duty_right = 400;
//    if(zhong[55]-zhong[25]>=20 && duty_left>duty_right)
//    {
//        duty_right=1000;
//        duty_left = 400;
//    }
//    if(zhong[55]-zhong[25]<=-20 && duty_left<duty_right)
//    {
//        duty_left=1000;
//        duty_right= 400;
//    }
    // 更新电机输出
    MotorCtrL(Motor3, duty_right);
    MotorCtrL(Motor4, duty_left);
}

void super_motor_control2()
{
    float total_piancha = 0.0;
    float wanqu = 0.0;
    // 计算加权总偏差（i=29~58对应数组索引0~23）
    for(int i=0; i<36; i++) {
    // 当前行的偏差值 * 权重
       total_piancha += piancha[i+35] * piancha_weighted[i];
       wanqu+=abs(piancha[i+35]);
    }

    if(jishu_button == 1)
    {
        // 获取编码器增量
        ECPULSE1 = ENC_GetCounter(ENC1_InPut_P33_7);
        jishu += ECPULSE1;
    }
    // 视觉控制动态调整基准速度
    float speed_adjust = KP2 * total_piancha; // 使用原有视觉偏差计算
    if(speed_adjust>=0)
    {
        duty_left = BASE_DUTY+ speed_adjust*0.25;
        duty_right = BASE_DUTY - speed_adjust*0.25;
    }
    else
    {
        duty_left = BASE_DUTY + speed_adjust*0.25;
        duty_right = BASE_DUTY- speed_adjust*0.25;
    }
    if(duty_left >=3000) duty_left = 3000;
    if(duty_left <=-800) duty_left = -800;
    if(duty_right >=3000) duty_right = 3000;
    if(duty_right <=-800) duty_right = -800;
    if(wanqu>300)
    {
        MotorCtrL(Motor3, duty_right);
        MotorCtrL(Motor4, duty_left);
    }
    else if(wanqu>150)
    {
        MotorCtrL(Motor3, duty_right+175);
        MotorCtrL(Motor4, duty_left+175);
    }
    else
    {
        MotorCtrL(Motor3, duty_right+350);
        MotorCtrL(Motor4, duty_left+350);
    }
}
