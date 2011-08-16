#include <stdio.h>
#include "func.h"
#include "various.h"

/*int main(int argc, const char *argv[])
{
	init_data();
	int i,j;
	for (i = 0; i < 100; i++) 
	{
		for (j = 0; j < 100; j++) 
		{
			fb_one_pixel(j+500,i+300,0x00ff0000);//////利用二维实现此函数并把点打印在屏幕中间
		}
	}
	return 0;
}*/

int main(int argc, const char *argv[])
{
	init_data();
	fb_line(0,0,fb_v.w-1,fb_v.h-1,0x0000ff00);

	fb_line(fb_v.w-1,0,0,fb_v.h-1,0x0000ff00);
	return 0;
}
