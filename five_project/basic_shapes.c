/******************************************************************************  *此文件中定义一些基本操作的函数1.画点函数。2.画直线函数。3.划出空心圆的函数.4.  *划出实心圆的函数
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "various.h"
/*1.画点函数*/
int fb_one_pixel(int x,int y,u32_t color)/////////画点的函数  参数是坐标  和颜色
{
	*((u32_t *)fb_v.memo+x+y*fb_v.w)=color;/////////将颜色赋值给指针
	return 0;
}
/*交换函数*/
void swap(int *a,int *b)
{
	int temp=*a;
		*a=*b;
		*b=temp;
}
/*2.画直线函数*/
int fb_line(int x1,int y1,int x2,int y2,u32_t color)/// 此函数功能是从坐标(x1,y1)到坐标(x2,y2)画一条直线
{
	int dx=x2-x1;
	int dy=y2-y1;
	int inc=((dx*dy) > 0 ? 1 : -1 );
	int p=0;//////p是一中被定义好的算法
	if(abs(dx)>abs(dy))
	{
		if(dx<0)
			{
				swap(&x1,&x2);
				swap(&y1,&y2);
				dx=-dx;
				dy=-dy;
			}
			dy=abs(dy);
		p=2*dy-dx;
		while(x1<=x2)
		{
			fb_one_pixel(x1,y1,color);//////在(x1,y1)处画一个点
			x1++;
			if(p<0)
			{
				p+=2*dy;
			}
			else
			{
				y1+=inc;////////y的坐标加一
				p+=2*(dy-dx);
			}
		}
	}
	else
	{
		if(dy<0)
		{
			swap(&x1,&x2);
			swap(&y1,&y2);
			dx=-dx;
			dy=-dy;
		}
		dx=abs(dx);
		p=2*dx-dy;
		while(y1<=y2)
		{
			fb_one_pixel(x1,y1,color);
			y1++;
			if(p<0)
			{
				p+=2*dx;
			}
			else
			{
				x1+=inc;
				p+=2*(dx-dy);
			}
		}
	}
	return 0;
}
/*3.划出一个空心圆*/
int fb_hollow_circle(int x0,int y0,int r,u32_t color)
{
	int x=0;
	int y=r;
	int p=3-2*r;
	while(x<=y)
	{
		fb_one_pixel(x0+x,y0+y,color);
		fb_one_pixel(x0+y,y0+x,color);
		fb_one_pixel(x0+x,y0-y,color);
		fb_one_pixel(x0+y,y0-x,color);
		fb_one_pixel(x0-x,y0+y,color);
		fb_one_pixel(x0-y,y0+x,color);
		fb_one_pixel(x0-x,y0-y,color);
		fb_one_pixel(x0-y,y0-x,color);

		if(p<0)
		{
			p+=4*x+6;
		}
		else
		{
			p+=4*(x-y)+10;
			y--;
		}
		x++;
	}
	return 0;
}
/*4.划出一个实心圆*/
int fb_solid_circle(int x0,int y0,int r,u32_t color)
{
	int x=0;
	int y=r;
	int p=3-2*r;
	while(x<=y)
	{
		fb_line(x0+x,y0+y,x0-x,y0+y,color);
		fb_line(x0+y,y0+x,x0-y,y0+x,color);
		fb_line(x0+x,y0-y,x0-x,y0-y,color);
		fb_line(x0+y,y0-x,x0-y,y0-x,color);
		if(p<0)
		{
			p+=4*x+6;
		}
		else
		{
			p+=4*(x-y)+10;
			y--;
		}
		x++;
	}
	return 0;
}
/*自己写的划出棋盘函数*/
int fb_chessboard(void)
{
	int i;
	int j;
	for (i = 120; i < 1024; i++)
	{
		for (j = 0; j < 768; j++) 
		{
			if(j%30==0)
			{
				fb_line(120,j,i,j,0x0000ff00);
			}
		}
	}
	for (i = 0; i < 768; i++) 
	{
		for (j = 0; j < 1024; j++) 
		{
			if((j%30==0)&&(j>100))
			{
				fb_line(j,0,j,i,0x0000ff00);
			}
		}
	}
	return 0;
}



