/*比较字符窜是否完全相等的函数*/


#include <stdio.h>
#include <string.h>
#define n 10

/*int main(int argc, const char *argv[])			//////这个函数调用库函数strcmp进行比较两个字符窜
{
	char a[n];
	char b[n];
	int i=0;
	printf("please input str1  :\n");
	scanf("%s",a);
	printf("please input str2  :\n");
	scanf("%s",b);
	
	i=strcmp(a,b);
	printf("%d\n",i);
	return 0;
}*/


int strcmp_my(char *a,char *b)				///////自己写的比较函数
{
	while(*a!='\0') 						//////只要a不为空就和b开始比较
	{
		if(*a==*b)
		{
			a++;
			b++;
		}
		else
		{
			break;
		}
	}
	if((*a=='\0')&&(*b=='\0'))				//////比较完a和b相等，还要看结束标志全部是‘\0’时才完全相等，返回1.
	{
		return 1;
	}
	else									///////其余所有情况均不相等
	{
		return 0;
	}
}

int main(int argc, const char *argv[])
{
	int i;
	char a[100]	;
	char b[100] ;
	printf("please input the a :\n");
	scanf("%s",a);
	printf("please input the b :\n");
	scanf("%s",b);
	i=strcmp_my(a,b);
	printf("%d\n",i);
	return 0;
}
