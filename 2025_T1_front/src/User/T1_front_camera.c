/*
 * T1_front_camera.c
 *
 *  Created on: 2025年4月20日
 *      Author: NPT_T1.ZenoJ
 */

#include "T1_front_camera.h"

extern unsigned char Image_Go[60][80];
extern int rightline[60],leftline[60],zhong[60],piancha[60];
#define bin_image   Image_Go

void Smaller_Use_Image2(void)
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

void Bin_Image_Filter2 (void)
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

int my_abs(int value)
{
    if(value>=0) return value;
    else return -value;
}

uint8 start_point_l[2] = { 0 };//左边起点的x，y值
uint8 start_point_r[2] = { 0 };//右边起点的x，y值
uint8 get_start_point(uint8 start_row)
{
    uint8 i = 0,l_found = 0,r_found = 0;
//    char txt[32];
    //清零
    start_point_l[0] = 0;//x
    start_point_l[1] = 0;//y

    start_point_r[0] = 0;//x
    start_point_r[1] = 0;//y
    //从中间往左边，先找起点
    for (i = image_w / 2; i > border_min; i--)
    {
        start_point_l[0] = i;//x
        start_point_l[1] = start_row;//y
        if (bin_image[start_row][i] == 255 && bin_image[start_row][i - 1] == 0)
        {
            l_found = 1;
//            LCD_DrawPoint(120,i*2,U16_YELLOW);
//            sprintf(txt, "zuo:%d", i*2);             // 将变量填充到字符串的对应位置，并将字符串存放到txt[]中
//            LCD_ShowStr_24(0, 3, txt, U16_RED, U16_BLUE); // 显示24*12字符串
            break;
        }
    }

    for (i = image_w / 2; i < border_max; i++)
    {
        start_point_r[0] = i;//x
        start_point_r[1] = start_row;//y
        if (bin_image[start_row][i] == 255 && bin_image[start_row][i + 1] == 0)
        {
            r_found = 1;
//            LCD_DrawPoint(120,i*2,U16_YELLOW);
//            sprintf(txt, "you:%d", i*2);             // 将变量填充到字符串的对应位置，并将字符串存放到txt[]中
//            LCD_ShowStr_24(0, 4, txt, U16_RED, U16_BLUE); // 显示24*12字符串
            break;
        }
    }

    if(l_found&&r_found)return 1;
    else {
//        sprintf(txt, "0:%d", 1000);             // 将变量填充到字符串的对应位置，并将字符串存放到txt[]中
//        LCD_ShowStr_24(8, 4, txt, U16_RED, U16_BLUE); // 显示24*12字符串
        return 0;
    }
}

#define USE_num image_h*3   //定义找点的数组成员个数按理说300个点能放下，但是有些特殊情况确实难顶，多定义了一点

 //存放点的x，y坐标
uint16 points_l[(uint16)USE_num][2] = { {  0 } };//左线
uint16 points_r[(uint16)USE_num][2] = { {  0 } };//右线
uint16 dir_r[(uint16)USE_num] = { 0 };//用来存储右边生长方向
uint16 dir_l[(uint16)USE_num] = { 0 };//用来存储左边生长方向
uint16 data_stastics_l = 0;//统计左边找到点的个数
uint16 data_stastics_r = 0;//统计右边找到点的个数
uint8 hightest = 0;//最高点
void search_l_r(uint16 break_flag, uint8(*image)[image_w], uint16 *l_stastic, uint16 *r_stastic, uint8 l_start_x, uint8 l_start_y, uint8 r_start_x, uint8 r_start_y, uint8*hightest)
{

    uint8 i = 0, j = 0;

    //左边变量
    uint8 search_filds_l[8][2] = { {  0 } };
    uint8 index_l = 0;
    uint8 temp_l[8][2] = { {  0 } };
    uint8 center_point_l[2] = {  0 };
    uint16 l_data_statics;//统计左边
    //定义八个邻域
    static sint8 seeds_l[8][2] = {{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},};
    //{-1,-1},{0,-1},{+1,-1},
    //{-1, 0},       {+1, 0},
    //{-1,+1},{0,+1},{+1,+1},
    //这个是顺时针
    //右边变量
    uint8 search_filds_r[8][2] = { { 0 } };
    uint8 center_point_r[2] = { 0 };//中心坐标点
    uint8 index_r = 0;//索引下标
    uint8 temp_r[8][2] = { { 0 } };
    uint16 r_data_statics;//统计右边
    //定义八个邻域
    static sint8 seeds_r[8][2] = { {0,1},{1,1},{1,0}, {1,-1},{0,-1},{-1,-1}, {-1,0},{-1,1},};
    //{-1,-1},{0,-1},{+1,-1},
    //{-1, 0},       {+1, 0},
    //{-1,+1},{0,+1},{+1,+1},
    //这个是逆时针
    l_data_statics = *l_stastic;//统计找到了多少个点，方便后续把点全部画出来
    r_data_statics = *r_stastic;//统计找到了多少个点，方便后续把点全部画出来

    //第一次更新坐标点  将找到的起点值传进来
    center_point_l[0] = l_start_x;//x
    center_point_l[1] = l_start_y;//y
    center_point_r[0] = r_start_x;//x
    center_point_r[1] = r_start_y;//y

        //开启邻域循环
    while (break_flag--)
    {

        //左边
        for (i = 0; i < 8; i++)//传递8F坐标
        {
            search_filds_l[i][0] = center_point_l[0] + seeds_l[i][0];//x
            search_filds_l[i][1] = center_point_l[1] + seeds_l[i][1];//y
        }
        //中心坐标点填充到已经找到的点内
        points_l[l_data_statics][0] = center_point_l[0];//x
        points_l[l_data_statics][1] = center_point_l[1];//y
        l_data_statics++;//索引加一

        //右边
        for (i = 0; i < 8; i++)//传递8F坐标
        {
            search_filds_r[i][0] = center_point_r[0] + seeds_r[i][0];//x
            search_filds_r[i][1] = center_point_r[1] + seeds_r[i][1];//y
        }
        //中心坐标点填充到已经找到的点内
        points_r[r_data_statics][0] = center_point_r[0];//x
        points_r[r_data_statics][1] = center_point_r[1];//y

        index_l = 0;//先清零，后使用
        for (i = 0; i < 8; i++)
        {
            temp_l[i][0] = 0;//先清零，后使用
            temp_l[i][1] = 0;//先清零，后使用
        }

        //左边判断
        for (i = 0; i < 8; i++)
        {
            if (image[search_filds_l[i][1]][search_filds_l[i][0]] == 0
                && image[search_filds_l[(i + 1) & 7][1]][search_filds_l[(i + 1) & 7][0]] == 255)
            {
                temp_l[index_l][0] = search_filds_l[(i)][0];
                temp_l[index_l][1] = search_filds_l[(i)][1];
                index_l++;
                dir_l[l_data_statics - 1] = (i);//记录生长方向
            }

            if (index_l)
            {
                //更新坐标点
                center_point_l[0] = temp_l[0][0];//x
                center_point_l[1] = temp_l[0][1];//y
                for (j = 0; j < index_l; j++)
                {
                    if (center_point_l[1] > temp_l[j][1])
                    {
                        center_point_l[0] = temp_l[j][0];//x
                        center_point_l[1] = temp_l[j][1];//y
                    }
                }
            }

        }
        if ((points_r[r_data_statics][0]== points_r[r_data_statics-1][0]&& points_r[r_data_statics][0] == points_r[r_data_statics - 2][0]
            && points_r[r_data_statics][1] == points_r[r_data_statics - 1][1] && points_r[r_data_statics][1] == points_r[r_data_statics - 2][1])
            ||(points_l[l_data_statics-1][0] == points_l[l_data_statics - 2][0] && points_l[l_data_statics-1][0] == points_l[l_data_statics - 3][0]
                && points_l[l_data_statics-1][1] == points_l[l_data_statics - 2][1] && points_l[l_data_statics-1][1] == points_l[l_data_statics - 3][1]))
        {
            //printf("三次进入同一个点，退出\n");
            break;
        }
        if (my_abs(points_r[r_data_statics][0] - points_l[l_data_statics - 1][0]) < 2
            && my_abs(points_r[r_data_statics][1] - points_l[l_data_statics - 1][1] < 2)
            )
        {
            //printf("\n左右相遇退出\n");
            *hightest = (points_r[r_data_statics][1] + points_l[l_data_statics - 1][1]) >> 1;//取出最高点
            //printf("\n在y=%d处退出\n",*hightest);
            break;
        }
        if ((points_r[r_data_statics][1] < points_l[l_data_statics - 1][1]))
        {
//            printf("\n如果左边比右边高了，左边等待右边\n");
            continue;//如果左边比右边高了，左边等待右边
        }
        if (dir_l[l_data_statics - 1] == 7
            && (points_r[r_data_statics][1] > points_l[l_data_statics - 1][1]))//左边比右边高且已经向下生长了
        {
            //printf("\n左边开始向下了，等待右边，等待中... \n");
            center_point_l[0] = (unsigned char)points_l[l_data_statics - 1][0];//x
            center_point_l[1] = (unsigned char)points_l[l_data_statics - 1][1];//y
            l_data_statics--;
        }
        r_data_statics++;//索引加一

        index_r = 0;//先清零，后使用
        for (i = 0; i < 8; i++)
        {
            temp_r[i][0] = 0;//先清零，后使用
            temp_r[i][1] = 0;//先清零，后使用
        }

        //右边判断
        for (i = 0; i < 8; i++)
        {
            if (image[search_filds_r[i][1]][search_filds_r[i][0]] == 0
                && image[search_filds_r[(i + 1) & 7][1]][search_filds_r[(i + 1) & 7][0]] == 255)
            {
                temp_r[index_r][0] = search_filds_r[(i)][0];
                temp_r[index_r][1] = search_filds_r[(i)][1];
                index_r++;//索引加一
                dir_r[r_data_statics - 1] = (i);//记录生长方向
                //printf("dir[%d]:%d\n", r_data_statics - 1, dir_r[r_data_statics - 1]);
            }
            if (index_r)
            {

                //更新坐标点
                center_point_r[0] = temp_r[0][0];//x
                center_point_r[1] = temp_r[0][1];//y
                for (j = 0; j < index_r; j++)
                {
                    if (center_point_r[1] > temp_r[j][1])
                    {
                        center_point_r[0] = temp_r[j][0];//x
                        center_point_r[1] = temp_r[j][1];//y
                    }
                }
            }
        }
    }


    //取出循环次数
    *l_stastic = l_data_statics;
    *r_stastic = r_data_statics;

}
//功能说明：从八邻域边界里提取需要的边线
//参数说明：
//total_L ：找到的点的总数
//total_R  ：找到的点的总数
uint8 l_border[image_h];//左线数组
uint8 r_border[image_h];//右线数组
uint8 center_line[image_h];//中线数组
void get_left(uint16 total_L)
{
    uint8 i = 0;
    uint16 j = 0;
    uint8 h = 0;
    //初始化
    for (i = 0;i<image_h;i++)
    {
        l_border[i] = border_min;
    }
    h = image_h - 2;
    //左边
    for (j = 0; j < total_L; j++)
    {
        //printf("%d\n", j);
        if (points_l[j][1] == h)
        {
            l_border[h] = points_l[j][0]+1;
        }
        else continue; //每行只取一个点，没到下一行就不记录
        h--;
        if (h == 0)
        {
            break;//到最后一行退出
        }
    }
}

void get_right(uint16 total_R)
{
    uint8 i = 0;
    uint16 j = 0;
    uint8 h = 0;
    for (i = 0; i < image_h; i++)
    {
        r_border[i] = border_max;//右边线初始化放到最右边，左边线放到最左边，这样八邻域闭合区域外的中线就会在中间，不会干扰得到的数据
    }
    h = image_h - 2;
    //右边
    for (j = 0; j < total_R; j++)
    {
        if (points_r[j][1] == h)
        {
            r_border[h] = points_r[j][0] - 1;
        }
        else continue;//每行只取一个点，没到下一行就不记录
        h--;
        if (h == 0)break;//到最后一行退出
    }
}

void image_draw_rectan(uint8(*image)[image_w])
{

    uint8 i = 0;
    for (i = 0; i < image_h; i++)
    {
        image[i][0] = 0;
        image[i][1] = 0;
        image[i][image_w - 1] = 0;
        image[i][image_w - 2] = 0;
    }
    for (i = 0; i < image_w; i++)
    {
        image[0][i] = 0;
        image[1][i] = 0;
    }
}

void image_process(void)
{
    uint16 i;
    uint8 hightest = 0;//定义一个最高行，tip：这里的最高指的是y值的最小
//    image_draw_rectan(bin_image);//预处理画黑框
    //清零
    data_stastics_l = 0;
    data_stastics_r = 0;
    if (get_start_point(image_h - 2))//找到起点了，再执行八领域，没找到就一直找
    {
        search_l_r((uint16)USE_num, bin_image, &data_stastics_l, &data_stastics_r, start_point_l[0], start_point_l[1], start_point_r[0], start_point_r[1], &hightest);
        // 从爬取的边界线内提取边线 ， 这个才是最终有用的边线
        get_left(data_stastics_l);
        get_right(data_stastics_r);
        //处理函数放这里，不要放到if外面去了，不要放到if外面去了，不要放到if外面去了，重要的事说三遍

    }
    for (i = 20; i < 60-2; i+=2)
    {
        center_line[i] = (l_border[i] + r_border[i])/2;//求中线
        LCD_DrawPoint(center_line[i]*2,i*2,U16_RED);
        LCD_DrawPoint(center_line[i]*2,i*2+1,U16_RED);
//        LCD_DrawPoint(l_border[i]*2,i*2,U16_YELLOW);
//        LCD_DrawPoint(l_border[i]*2,i*2+1,U16_YELLOW);
//        LCD_DrawPoint(r_border[i]*2,i*2,U16_GREEN);
//        LCD_DrawPoint(r_border[i]*2,i*2+1,U16_GREEN);
    }
}
