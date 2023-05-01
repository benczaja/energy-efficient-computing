#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL)); // Initialization or RANDOM NUMBER
    int x_size = 10;
    int y_size = 10;

    int a[x_size][y_size];
    int b[x_size][y_size];
    int c[x_size][y_size];

    // loop an init with rand vals
    for(int i=0;i<x_size;i++)
    {
        for(int j=0;j<y_size;j++)
        {
            a[i][j] = rand() % 10;
            b[i][j] = rand() % 10;
            printf("%d\t",a[i][j]);
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }

    printf("multiply of the matrix=\n");
    for(int i=0;i<x_size;i++)
    {
        for(int j=0;j<y_size;j++)
        {
            c[i][j]=0;
            for(int k=0;k<y_size;k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    //for printing result
    printf("The result of a*b = \n");
    for(int i=0;i<x_size;i++)
    {
        for(int j=0;j<y_size;j++)
        {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}