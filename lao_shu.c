#include <stdio.h>
int i;
int couter;
int main(int argc, const char *argv[])
{
    for (i = 0; i < 100; i++)   
    {
        if( (i%10)==9)
        {
            couter++;
        }
        if ((i/10)==9)
        {
            couter++;
        }
        
    }
    printf("%d",couter);
    return 0;
}
