#include<stdio.h> // needed for ‘printf’ 
#include<stdlib.h> // needed for ‘RAND_MAX’ 
#include<time.h> // needed for clock() and CLOCKS_PER_SEC etc
#include<omp.h> // needed for OpenMP 

static const int ROWS = 2000;     // Number of rows in each matrix
static const int COLUMNS = 2000;  // Number of columns in each matrix

float A[ROWS][COLUMNS];    // Matrix A
float B[ROWS][COLUMNS];    // Matric B
float C[ROWS][COLUMNS];    // result

void initialize_matrices(){
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
    printf("(Simple) Matix Multiplication\n");
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
    int num_threads = omp_get_max_threads();
    printf("(OpenMP) Matix Multiplication Using %d Threads\n", num_threads);
    
    #pragma omp parallel for 
    for (int i = 0; i < ROWS; ++i) 
    {
        for (int j = 0; j < COLUMNS; ++j) 
        {
            for (int k = 0; k < COLUMNS; ++k) 
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main()  {


    printf("Initializing A (size %d) and B (size %d) arrays with random values between (0..1)\n",ROWS,COLUMNS);
    initialize_matrices();

    clock_t t; // clock_t is of long type
    t = clock(); // start the clock
    simple_matrix_multiply(); // Do the matrix multiplication
    t = clock() - t; // stop the clock
    
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // convert to seconds (and long to double)
    printf("TIME: %f sec\n",time_taken);

    //initialize_matrices(); // We need to re-intiaize to make sure we get "correct answer"

    //double start = omp_get_wtime();  //omp needed here because clock will sum up time for all threads
    //openmp_matrix_multiply(); // Do the matrix multiplication
    //double end = omp_get_wtime(); 
    //printf("TIME: %f sec\n",(end-start));

    return 0;
}
