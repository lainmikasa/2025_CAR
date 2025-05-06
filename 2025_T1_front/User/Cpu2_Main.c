/*LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
@编   写：龙邱科技
@邮   箱：chiusir@163.com
@编译IDE：AURIX Development Studio 1.10.2及以上版本
@使用平台：北京龙邱智能科技TC297TX核心板和母板
@相关信息参考下列地址
    网      站：http://www.lqist.cn
    淘 宝 店 铺：http://longqiu.taobao.com
    程序配套视频：https://space.bilibili.com/95313236
@软件版本：V2.2 版权所有，单位使用请先联系授权

@修改日期：2024-11-23
@修改内容：
@注意事项：
   导入工程的时候路径要为纯英文,不要有空格、特殊符合和中文
QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ*/

//================================ 系统代码 ================================//
#include "include.h"                //头文件
extern IfxCpu_syncEvent g_cpuSyncEvent; //核心同步所需要的变量

//================================ 用户代码 ================================//

int core2_main(void)
{
    //================================ 系统代码 ================================//
    IfxCpu_emitEvent(&g_cpuSyncEvent);  // 等待cpu同步
    IfxCpu_waitEvent(&g_cpuSyncEvent, 1);


    /* 主循环 */
    while (1)
    {
        /* 不要在cpu2中放入用户代码，否则会有问题 */

    }
}


