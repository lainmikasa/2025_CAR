/*LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
@编    写：龙邱科技
@E-mail  ：chiusir@163.com
@编译IDE：AURIX Development Studio1.4及以上版本
@使用平台：北京龙邱智能科技TC297TX核心板和母板
@SYS  PLL：300MHz*3 【Crystal】 20.000Mhz
@最后更新：2023年03月08日，持续更新，请关注最新版！
@功能介绍：
@相关信息参考下列地址
@网    站：http://www.lqist.cn
@淘宝店铺：http://longqiu.taobao.com
@软件版本：V1.0 版权所有，单位使用请先联系授权
@程序配套视频地址：https://space.bilibili.com/95313236
****************************************************************
基于iLLD_1_0_1_11_0底层程序,
使用例程的时候，建议采用没有空格的英文路径，切换workspace到当前工程所放文件夹！
QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ*/
#ifndef _LQ_BD_H_
#define _LQ_BD_H_

typedef enum
{
    N=0,
    S
}lat;
typedef enum
{
    E=0,
    W
}lon;

typedef struct {
        double PX;                 //坐标值
        double PY;
        double Direction;         //车头朝向（方向）
}Position_t;

typedef struct SaveData
{
  char GPS_Buffer[128];         //完整数据
  char isGetData;               //是否获取到GPS数据
  char UTCTime[11];             //UTC时间
  char isParseData;             //是否解析完成
  char latitude[11];            //纬度
  char N_S[2];                  //N/S
  char longitude[12];           //经度
  char E_W[2];                  //E/W
  char isUsefull;               //定位信息是否有效
  char speed[6];                 //速度 单位：节
  char direction[6];             //方向
} _SaveData;

extern _SaveData Save_Data;
extern Position_t point_p;
char Get_DoubleData(_SaveData * data, double* Lon, double* Lat);
char Get_IntData(int* Lon_Z, int* Lon_X, int* Lat_Z, int* Lat_X);
int BD_getdata(Position_t *Current_Point);
void Test_BD1202(void);



#endif
