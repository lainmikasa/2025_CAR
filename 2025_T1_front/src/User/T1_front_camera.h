/*
 * T1_front_camera.h
 *
 *  Created on: 2025年4月20日
 *      Author: NPT_T1.ZenoJ
 */

#ifndef _T1_FRONT_CAMERA_H
#define _T1_FRONT_CAMERA_H
#include "include.h"

#define image_h 60//图像高度
#define image_w 80//图像宽度
#define white_pixel 255
#define black_pixel 0

#define bin_jump_num    1//跳过的点数
#define border_max  image_w-2 //边界最大值
#define border_min  1   //边界最小值

//void eight_neighborhood_search(uint8 start_x,uint8 start_y,uint8 is_left);
//void image_process();
void image_process(void);
uint8 get_start_point(uint8 start_row);
void Smaller_Use_Image2(void);
void Bin_Image_Filter2(void);
void image_draw_rectan(uint8(*image)[image_w]);
#endif /* _T1_FRONT_CAMERA_H */
