#include <stdio.h>
#include "various.h"

/*************************************************
 *此函数用来检查是否五子棋游戏的胜利者，从四个方向判断
******************************************/
int check(int x,int y)
{
	int i=0;
	int j=0;
	int counter=1;
	char who=chess_board[x+(y*X_NUM)];///////////把当前坐标(二维数组表示的一位数组)的颜色赋值给who
	if (who==0) 
	{
		return 0;
	}
	/*横向判断*/
	for (i = 1; i < 5; i++) 		
	{		
		if(chess_board[x+i+(y*X_NUM)]==who)
		{
			counter++;
		}
		else
		{
			break;
		}
		if(counter==5)
		{
			return who;
		}
	}
	/*斜上方判断*/
	counter = 1;
	for (i = 1,j = -1; i < 5; i++,j--) 		
	{
		if(chess_board[x+i+((j+y)*X_NUM)]==who)
		{
			counter++;
		}
		else
		{
			break;
		}
		if(counter==5)
		{
			return who;
		}
	}
	/*斜下方判断*/
	counter = 1;
	for (i = 1,j = 1; i < 5; i++,j++) 		
	{
		if(chess_board[x+i+((j+y)*X_NUM)]==who)
		{
			counter++;
		}
		else
		{
			break;
		}
		if(counter==5)
		{
			return who;
		}
	}
	/*纵向判断*/
	counter=1;
	for (j = 1; j < 5; j++) 		
	{
		if(chess_board[x+((j+y)*X_NUM)]==who)
		{
			counter++;
		}
		else
		{
			break;
		}
		if(counter==5)
		{
			return who;
		}
	}
	return 0;
}


/***********************************************************************
 *放棋子的函数
************************************************************************/

int chess_put(int x,int y)
{
	int i=0;
	int j=0;
	int winner=0;
	chess_board[x+(y*X_NUM)]=player;////////将当前坐标的棋子颜色赋值给玩家player
	/*此for循环可以从整个屏幕上任意一点所有的点开始check判断并将结果返回到winner中*/
	for (j = 0; j < Y_NUM; j++) 
	{
		for (i = 0; i < X_NUM; i++) 
		{
			if((winner=check(i,j))>0)
			{
				return winner;
			}
		}
	}
	return 0;
}

/*此函数的功能是能够将打印在屏幕任意坐标的棋子都矫正到里该坐标最近的交叉坐标上，
*/

int chess_doing(void)
{
	int rx=(mx-ST_X)%SPACE;
	int ry=(my-ST_Y)%SPACE;
	int cx=mx-rx;
	int cy=my-ry;
	if ((mx<ST_X)||(mx>(ST_X+(X_NUM-1)*SPACE))) 
	{
		return 0;
	}	
	if ((my<ST_Y)||(my>(ST_Y+(Y_NUM-1)*SPACE))) 
	{
		return 0;
	}
	if (rx>(SPACE/2))
	{
		cx+=SPACE;
	}
	if (ry>(SPACE/2))
	{
		cy+=SPACE;
	}
	char winner = 0;
	fb_solid_circle(cx,cy,13,current_color);
	winner=chess_put((cx-ST_X)/SPACE,(cy-ST_Y)/SPACE);/////winner接收胜利者
	if(winner>0)
	{
		return winner;///继续返回winner供mouse_doing函数中的flag接受
	}
	if (current_color==WRITE) 
	{
		current_color=BLACK;
		player=1;
	}
	else
	{
		current_color=WRITE;
		player=2;
	}
	return 0;
}
