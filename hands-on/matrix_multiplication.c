#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

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
    int x_size;
    int y_size;
    sscanf(argv[1], "%d", &x_size);
    sscanf(argv[2], "%d", &y_size);

    // This is probably overkill
    float (*A)[6];
    float (*B)[6];
    float (*C)[6];
    A = malloc(sizeof *A * 1000000);
    B = malloc(sizeof *B * 1000000);
    C = malloc(sizeof *C * 1000000);

    printf("Initializing A and B arrays with random values (1..10)\n");
    for(int i=0;i<x_size;i++)
    {
        for(int j=0;j<y_size;j++)
        {
            A[i][j] = rand() % 10; // Get a number between 1 and 10
            B[i][j] = rand() % 10; // Get a number between 1 and 10
        }
    }


    printf("Multiplying A*B\n");
    for(int i=0;i<x_size;i++)
    {
        for(int j=0;j<y_size;j++)
        {
            C[i][j]=0;
            for(int k=0;k<y_size;k++)
            {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
    ////for printing result
    //printf("The result of a*b = \n");
    //for(int i=0;i<x_size;i++)
    //{
    //    for(int j=0;j<y_size;j++)
    //    {
    //        //printf("%d\t",c[i][j]);
    //    }
    //    //printf("\n");
    //}
    //return 0;
}