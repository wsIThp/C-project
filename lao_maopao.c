#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define M 20

void print_array(int *p ,int n)
{
    int i=0;
    for (i = 0; i < n; i++)
    {
        if((i%8)==0)
        {
        printf("\n");
        }
        printf("%7d",p[i]);

    }
    printf("\n");
}
void init_array(int *p ,int n)
{
    srand(time(NULL));

    int i=0;
    for (i = 0; i < n; i++)
    {
        p[i]=rand()%(n*2);
    }
}

void sort_array(int *p ,int n)
{
    int i=0;
    int j=0;
    int temp;
    for (i = 0; i < (n-1); i++) 
    {
        for (j = i+1; j < n; j++)
        {
             if (p[i]>p[j]) 
          {   
            temp=p[i];
            p[i]=p[j];
            p[j]=temp;
            }
        }
    }
}

int main(int argc, const char *argv[])
{
    int array[M];

    init_array(array,M);
    print_array(array,M);
getchar();
    sort_array(array,M);
getchar();
    print_array(array,M);
    return 0;
}
