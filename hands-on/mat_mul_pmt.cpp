#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<omp.h>
#include<pmt.h>
#include<iostream>

static const int ROWS = 1000;     // Number of rows in each matrix
static const int COLUMNS = 1000;  // Number of columns in each matrix

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

    auto sensor = pmt::rapl::Rapl::create();
    
    auto start = sensor->read();
    simple_matrix_multiply(); // Do the matrix multiplication
    auto end = sensor->read();

    std::cout <<"PMT seconds: "<< pmt::PMT::seconds(start, end) << " s"<< std::endl;
    std::cout <<"PMT Joules: " << pmt::PMT::joules(start, end) << " J" << std::endl;
    std::cout <<"PMT Watts: " << pmt::PMT::watts(start, end) << " W" << std::endl;

    
    
    initialize_matrices(); // We need to re-intiaize to make sure we get "correct answer"

    start = sensor->read();
    openmp_matrix_multiply(); // Do the matrix multiplication
    end = sensor->read();

    std::cout <<"PMT seconds: "<< pmt::PMT::seconds(start, end) << " s"<< std::endl;
    std::cout <<"PMT Joules: " << pmt::PMT::joules(start, end) << " J" << std::endl;
    std::cout <<"PMT Watts: " << pmt::PMT::watts(start, end) << " W" << std::endl;
    
    return 0;
}
