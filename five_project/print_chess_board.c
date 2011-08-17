/*这是划出五子棋棋盘的函数*/

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
		fb_line(ST_X,ST_Y+i*SPACE,ST_X+(X_NUM-1)*SPACE,ST_Y+i*SPACE,0x00ffffff);
	}
	for (i = 0; i < X_NUM; i++) 
	{
		fb_line(ST_X+i*SPACE,ST_Y,ST_X+i*SPACE,ST_Y+(Y_NUM-1)*SPACE,0X00ffffff);
	}
}
