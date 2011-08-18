#include <stdio.h>
#include "various.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BORD 0x000000ff
#define X___ 0x000fffff	
#define T___ 0x00cc9966

#define C_W 10 
#define C_H 17

/***********************************************************
 *定义的鼠标颜色形状的数组用来存放自己定义的鼠标的背景颜色
*************************************************************/


static u32_t cursor_pixel[C_W*C_H]=
{
	BORD,T___,T___,T___,T___,T___,T___,T___,T___,T___,
	BORD,BORD,T___,T___,T___,T___,T___,T___,T___,T___,
	BORD,X___,BORD,T___,T___,T___,T___,T___,T___,T___,
	BORD,X___,X___,BORD,T___,T___,T___,T___,T___,T___,
	BORD,X___,X___,X___,BORD,T___,T___,T___,T___,T___,
	BORD,X___,X___,X___,X___,BORD,T___,T___,T___,T___,
	BORD,X___,X___,X___,X___,X___,BORD,T___,T___,T___,
	BORD,X___,X___,X___,X___,X___,X___,BORD,T___,T___,
	BORD,X___,X___,X___,X___,X___,X___,X___,BORD,T___,
	BORD,X___,X___,X___,X___,X___,X___,X___,X___,BORD,
	BORD,X___,X___,X___,X___,X___,BORD,BORD,BORD,BORD,
	BORD,X___,X___,BORD,X___,X___,BORD,T___,T___,T___,
	BORD,X___,BORD,T___,BORD,X___,X___,BORD,T___,T___,
	BORD,BORD,T___,T___,BORD,X___,X___,BORD,T___,T___,
	T___,T___,T___,T___,T___,BORD,X___,X___,BORD,T___,
	T___,T___,T___,T___,T___,BORD,X___,X___,BORD,T___,
	T___,T___,T___,T___,T___,T___,BORD,BORD,T___,T___,
};

/*******************************************************
 *定义一个新的数组用来存放鼠标的背景颜色
******************************************************/

u32_t bg[C_W*C_H]={0};


/*******************************************************************
 *此函数是划出鼠标点即划出鼠标的型状： 箭头
 *
**********************************************************************/

int draw_cursor(int x,int y)
{
	int i=0;
	int j=0;
	save_bg(x,y);
	for (j = 0; j < C_H;j ++) 
	{
		for (i = 0; i < C_W; i++) 
		{
			fb_one_pixel(x+i,y+j,cursor_pixel[i+j*C_W]);
		}
	}
	return 0;
}
/*****************************************************************
 *此函数是保存鼠标移动之前的背景颜色，并把其颜色存放到新定义的那个数组中
*******************************************************************/
int save_bg(int x,int y)
{
	int i=0;
	int j=0;
	for (j = 0; j < C_H; j++)
	{
		for (i = 0; i < C_W; i++) 
		{
			bg[i+j*C_W]=*((u32_t *)fb_v.memo+x+i+(y+j)*fb_v.w);
		}
	}
	return 0;
}

/****************************************************************
 *这个函数是在鼠标从一个位置移动走以后，恢复那个位置以前的背景颜色
 *从存放背景颜色的数组中取出数据打印到那个位置上
***************************************************/

int restore_bg(int x,int y)
{
	int i=0;
	int j=0;
	for (j = 0; j < C_H;j ++) 
	{
		for (i = 0; i < C_W; i++) 
		{
			fb_one_pixel(x+i,y+j,bg[i+j*C_W]);
		}
	}
	return 0;
}

/********************************************************************
 *这个函数用来从系统设备文件中读取鼠标的信息  在此项目中只需要三个参数即可 2.水平距离 3 .竖直距离 1. 点击鼠标键(左右中中的哪个)的三个信息
*********************************************************************/
int get_mouse_info(int fd,mouse_event *p)
{
	char buf[8];
	int n=0;
	n=read(fd,buf,3);				////////read函数从系统文件中读取信息

	if (n>0) 
	{
		p->dx=buf[1];				/////////将信息赋值到定义的结构体中
		p->dy=-buf[2];				///////////////
		p->buffon=(buf[0] & 0x07);	/////
	}
	return n ;
}

/************************************************
恢复函数：在游戏惊醒完一次后恢复整个程序一边游戏重新开始enter键控制开始
*************************************************/

void reinit(void)
{
	memset(fb_v.memo,0,fb_v.w*fb_v.h*fb_v.bpp/8);///恢复屏幕
	printf_board_bg();							 ///恢复背景
	printf_board();								 ///恢复棋盘					
	memset(chess_board,0,X_NUM*Y_NUM);			 ///恢复数组
	player=1;									 ///
	current_color=BLACK;						 ///
	mx=fb_v.w/2; 								 ///	
	my=fb_v.h/2; 								 ///		
	draw_cursor(mx,my);							 ///打印鼠标	
}




/******************************************************************
 *这个函数时将从系统文件中读取到的信息赋值给定义的结构体中
*******************************************************************/
int mouse_doing(void)
{
	int fb=0;
	char flag;
	mouse_event m_e;

			char press_do=0;
	fb=open("/dev/input/mice",O_RDWR|O_NONBLOCK);
	if (fb==-1)
	{
		perror("/dev/input/mice");
		exit(0);
	}
	
	mx=fb_v.w/2;
	my=fb_v.h/2;
	draw_cursor(mx,my);//////如果没有这句代码在屏幕中间（即鼠标刚开始出现的位置）将不会恢复之前的背景色     之前的会被抹掉
	while(1)
	{
		if (get_mouse_info(fb,&m_e)>0)
		{
			restore_bg(mx,my);/////////移动鼠标之前先恢复背景颜色
			mx+=m_e.dx;
			my+=m_e.dy;
			//draw_cursor(mx,my);////////划出新的鼠标键头
			if (mx<0) 
			{
				mx=0;
			}
			if (mx>(fb_v.w-C_W))
			{
				mx=fb_v.w-C_W;
			}
			if (my<0) 
			{
				my=0;
			}
			if (my>(fb_v.h-C_H))
			{
				my=fb_v.h-C_H;
			}
			switch(m_e.buffon)
			{
				case 0:
				if (press_do==1)
				{
					press_do=0;
					
					flag=chess_doing();/////////flag接收写好的能够在交叉处划出棋子函数中的游戏的胜利者
//					fb_solid_circle(mx,my,13,0x000000ff);
				}
				break;
				case 1:press_do=1;break;
				case 2:
					//	fb_solid_circle(mx,my,13,0x000000ff);	break;
				case 4:break;
				default: break;
			}
			draw_cursor(mx,my);//////如果没有这句代码，划出的棋子会有块区域是之前的背景色
			
			if(flag>0)
			{
				printf("player %d was won\n",flag);
				getchar();
				flag = 0;
				reinit();/////恢复函数：恢复屏幕，棋盘，跟程序刚开始运行一样。可以继续运行整个函数
				///break;//////如果不注释掉break，只可以玩一次正需就会跳出
			}
		}
		usleep(500);
	}
	
	close(fb);
	return 0;
}


















