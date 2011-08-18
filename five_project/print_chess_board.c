/*这是划出五子棋棋盘和画背景颜色的函数*/

#include <stdio.h>
#include "various.h"
/************************************************
 *利用画直线的函数划出棋盘
****************************************************/

void printf_board(void)
{
	int i=0;
	for (i = 0; i < Y_NUM; i++)
	{
		fb_line(ST_X,ST_Y+i*SPACE,ST_X+(X_NUM-1)*SPACE,ST_Y+i*SPACE,0x00000000);
	}
	for (i = 0; i < X_NUM; i++) 
	{
		fb_line(ST_X+i*SPACE,ST_Y,ST_X+i*SPACE,ST_Y+(Y_NUM-1)*SPACE,0X00000000);
	}
}


/****************************************************
 *用画点函数在将整个背景画成自己定义好的颜色
********************************************************/

int printf_board_bg(void)
{
	int i;
	int j;
	for (i = 0; i < fb_v.h; i++)
	{
		for (j = 0; j < fb_v.w; j++) 
		{
			fb_one_pixel(j,i,0x00cc9966);
		}
	}
	return 0;
}
