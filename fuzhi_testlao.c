#include <stdio.h>

#define N     30

char *my_copy(char *d, char *s)
{
    while(*s!='\0')   
    {                  
        *d=*s;        
        d++;            
        s++;           
    }
    *d='\0';
    return d;
}
/*{
    char *m=d;
    while((*(d++)=*(s++))!='\0');
    return m;
}*/

int main(int argc, const char *argv[])
{
    char str[N]="helloworld";
    char c_str[N];
    my_copy(c_str,str);
    printf("%s",c_str);
    return 0;
}
