#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<iostream>
#include<pmt.h>


static const int ROWS = 1000;     // Number of rows in each matrix
static const int COLUMNS = 1000;  // Number of columns in each matrix

float A[ROWS][COLUMNS];    // Matrix A
float B[ROWS][COLUMNS];    // Matric B
float C[ROWS][COLUMNS];    // result

void initialize_matrices(){
    // Initial the matrices A,B with with random values between (0..1) and C to 0
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

int main()  {

    printf("Initializing A (size %d) and B (size %d) arrays with random values between (0..1)\n",ROWS,COLUMNS);
    initialize_matrices();
    printf("Multiplying A*B\n");

    //pmt::State start,end;
    //std::unique_ptr<pmt::PMT> sensor(pmt::rapl::Rapl::create());
    auto sensor = pmt::rapl::Rapl::create();
    //std::unique ptr<pmt::PMT> sensor(pmt::rapl::Rapl::create());
    simple_matrix_multiply();
    auto start = sensor->read();


    auto end = sensor->read();

    std::cout <<"PMT seconds "<< pmt::PMT::seconds(start, end) << " s"<< std::endl;
    std::cout <<"PMT Joules " << pmt::PMT::joules(start, end) << " J" << std::endl;
    std::cout <<"PMT Watts " << pmt::PMT::watts(start, end) << " W" << std::endl;

    ////for printing result
    //printf("The result of a*b = \n");
    //for(int i=0;i<ROWS;i++)
    //{
    //    for(int j=0;j<COLUMNS;j++)
    //    {
    //        //printf("%d\t",c[i][j]);
    //    }
    //    //printf("\n");
    //}
    //return 0;
}
