/*这个文件中专门存放变量的声明

*/


#ifndef _VAR_H_
#define _VAR_H_

#include "func.h"



extern  fbscr_t fb_v;//////定义全局变量（结构体型的变量fb_v）


extern  int mx;      /////////定义全局变量（整形）
extern  int my;        ///////


extern  char chess_board[X_NUM*X_NUM];	/////定义全局变量char型的二维模拟移位数组
extern	u32_t current_color;			/////定义全局整形颜色
extern  char player;					/////定义全局char型玩家

#endif
