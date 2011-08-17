#ifndef _FUNC_H_
#define _FUNC_H_


typedef unsigned char u8_t;			////定义u8_t代表char型
typedef unsigned int u32_t;			////


#define ST_X  100                   ///五子棋棋盘左边空出的长度 
#define ST_Y  40					///五子棋棋盘上边空出的长度
#define SPACE 30					///每个小方格的边长

#define X_NUM 29					///横线的点===纵线的个数
#define Y_NUM 24					///纵线的点===横线的个数
typedef struct
{
	int w;
	int h;
	int bpp;

	void *memo;
}fbscr_t;							///////直接定义fbscr_t为结构体类型


int init_data(void);													///声明初始化函数
int fb_one_pixel(int x,int y,u32_t color);								///声明画一个点函数
int fb_line(int x1,int y1,int x2,int y2,u32_t color);					////声明画一条直线的函数
void swap(int *a,int *b);

int fb_hollow_circle(int x0,int y0,int r,u32_t color);
int fb_solid_circle(int x0,int y0,int r,u32_t color);
int fb_chessboard(void);
void printf_board(void);

#endif
