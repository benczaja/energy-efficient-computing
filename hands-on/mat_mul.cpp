#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<omp.h>

static const int ROWS = 1000;     // Number of rows in each matrix
static const int COLUMNS = 1000;  // Number of columns in each matrix

float A[ROWS][COLUMNS];    // Matrix A
float B[ROWS][COLUMNS];    // Matric B
float C[ROWS][COLUMNS];    // result

void initialize_matrices(){
    printf("Initializing A (size %d) and B (size %d) arrays with random values between (0..1)\n",ROWS,COLUMNS);
    for (int i = 0 ; i < ROWS ; i++)
    {
        for (int j = 0 ; j < COLUMNS ; j++)
        {
            A[i][j] = (float) rand() / RAND_MAX ;
            B[i][j] = (float) rand() / RAND_MAX ;
            C[i][j] = 0.0 ;
        }
    }
}

void simple_matrix_multiply(){
    printf("(Simple) Multiplying A*B\n");
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLUMNS;j++)
        {
            for(int k=0;k<COLUMNS;k++)
            {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

void openmp_matrix_multiply(){
    printf("(OpenMP) Multiplying A*B\n");
    int num_threads = omp_get_max_threads();
    printf("Using %d Threads\n", num_threads);
    //#pragma omp parallel for private(i,j,k) shared(A,B,C)
    #pragma omp parallel for 
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            for (int k = 0; k < COLUMNS; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main()  {

    initialize_matrices();
    
    simple_matrix_multiply();
   
    openmp_matrix_multiply();

    return 0;
}
