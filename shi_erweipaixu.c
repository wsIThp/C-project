#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define M  10
#define N  10

void init_array(int *p,int n)
{
    int i,j;
    int a[i][j];
    srand(time(NULL));
    for (i = 0; i < M; i++)
    {
         for (j = 0; j < N; j++)
         {
            a[i][j]=rand()%100;
            printf("%5d",a[i][j]);
            //if((i)%M==0)
            //printf("%5d",a[i][j]);
           // {
             //   printf("\n");
           // }
            printf("%5d",a[i][j]);

         }
    }
}
void sort_array(int *p,int n)
{
    int i,j;
    int temp;

}

int main(int argc, const char *argv[])
{
    int array[M][N];
    int *p=NULL;
    p=&array[0][0];
    init_array(p,M*N);
    sort_array(p,M*N);
    return 0;
}
