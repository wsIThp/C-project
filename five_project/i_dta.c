/*此函数是初始化函数1.打开文件/dev/fb0从而显示出屏幕的长度宽度和分辨率
					2.建立映射关系（用到系用的接口函数mmap）
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <string.h>
#include <sys/mman.h>
#include "func.h"

fbscr_t fb_v;											//////定义结构体变量
int mx;													//////
int my;													//////
		/*定义的全局变量在用到的时候必须重新定义，这时初始化函数，在以后几乎所有的函数中都会用到这些变量，但是他们都会调用这个初始化函数，相当于调用此函数的时候自己都定义过来，所以在其他的函数中不需要重新定义*/
char player;											//////		
char chess_board[X_NUM*Y_NUM];							//////
u32_t current_color;									//////

int init_data(void)
{
	int fd=0;
	struct fb_var_screeninfo fb_var;						/////定义结构体变量
	fd=open("/dev/fb0",O_RDWR);								//////open函数用O_RDWD的权限打开文件。
	if (fd<0) 
	{
		perror("open fb0");
		exit(0);
	}
	/*ioctl：读设备文件的函数*/
	if (ioctl(fd,FBIOGET_VSCREENINFO,&fb_var)<0)			//////此函数值读屏幕信息并且赋值到fb_var中	
	{
		perror("ioctl");
		exit(0);
	}
	
	fb_v.w=fb_var.xres;                                   	///将屏幕上的信息赋值给结构体。
	fb_v.h=fb_var.yres;
	fb_v.bpp=fb_var.bits_per_pixel;
	
	fb_v.memo=mmap(NULL,fb_v.w*fb_v.h*fb_v.bpp/8,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
/*****************************************************************
 *工具接口函数mmap可以把磁盘文件的一部分直接映射到内存，这样文件中的位置直接就有 *对应的内存地址，对文件的读写可以直接用指针来做
 *********************************************************************/
	

if (fb_v.memo==MAP_FAILED)
	{
		perror("map");
		exit(0);
	}
	
	memset(fb_v.memo,0,fb_v.w*fb_v.h*fb_v.bpp/8);//////这个操作是清屏操作十六进制数表示清屏后显示的颜色
	
	
	/*int i;///////
	u32_t *p=fb_v.memo;
	for (i = 0; i < 1024*100; i++) 
	{
		p[1024*300+i]=0x0000ffff;                     	    /////十六进制表示颜色。八位从前向后，前两位表示灰度一般用不到，接下来两位红色，依次为绿色蓝色。
	}*/

	/**********************************************
	下面的循环函数在屏幕上打印出一条横线
	****************************************/
	int i;
	u32_t *p=fb_v.memo;
		for (i = 0; i < fb_v.w; i++)
		{
			p[i]=0x0000ffff;
		}
	////printf("w=%d\th=%d\tbpp=%d\t",fb_var.xres,fb_var.yres,fb_var.bits_per_pixel);

	memset(chess_board,0,X_NUM*Y_NUM);///////这个函数memset是用0将（X_NUM*Y_NUM）这么大的数组全部用零赋值，从指针chess_board的首地址开始。
	current_color=BLACK;		/////初始化
	player=1;			/////初始化player
	


	return 0;
}
