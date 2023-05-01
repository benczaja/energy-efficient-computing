#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<time.h>

int main( int argc, char *argv[] )  {

    if( argc == 3 ) {
        printf("Will multiply two 2D matricies of size (%s,%s) \n", argv[1],argv[2]);
    }
    else if( argc > 3 ) {
        printf("I need 2 arguments (Xdim, Ydim)..... Too many arguments supplied.\n");
        exit(1);
    }
    else {
        printf("I need 2 arguments (Xdim, Ydim)..... Too few arguments supplied.\n");
        exit(1);
    }
    srand(time(NULL)); // Initialization or RANDOM NUMBER
    long int x_tmp;
    long int y_tmp;
    char *eptr;

    x_tmp = strtol(argv[1],&eptr,10);
    y_tmp = strtol(argv[2],&eptr,10);

    int x_size = (int)x_tmp;
    int y_size = (int)y_tmp;


    int a[x_size][y_size];
    int b[x_size][y_size];
    int c[x_size][y_size];

    printf("I am here\n");
    // loop an init with rand vals
    for(int i=0;i<x_size;i++)
    {
        for(int j=0;j<y_size;j++)
        {
            a[i][j] = rand() % 10; // Get a number between 1 and 10
            b[i][j] = rand() % 10; // Get a number between 1 and 10
        }
    }

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
            //printf("%d\t",c[i][j]);
        }
        //printf("\n");
    }
    return 0;
}