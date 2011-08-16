#include <stdio.h>
#define N 20
#define M 20
int main(int argc, const char *argv[])
{
    char c[N]="ahdiaohfnja";
    char d[M];
    copy(d,c);
    printf("%s",d);
    return 0;

}
copy (char *ptr,char *ptr1)
{
    while(*ptr1!=0)
    {
        *ptr=*ptr1;
        ptr++;
        ptr1++;
    }
    *ptr='\0';
    return 0;
}


