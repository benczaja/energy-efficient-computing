#include<stdio.h> // needed for ‘printf’ 
#include<stdlib.h> // needed for ‘RAND_MAX’ 
#include<time.h> // needed for clock() and CLOCKS_PER_SEC etc
#include<omp.h> // needed for OpenMP 
#include<iostream> // needed for cout, endl etc etc
#include<pmt.h> // needed for PMT


void initialize_matrices(int ROWS, int COLUMNS, float **A, float **B, float **C){
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

void simple_matrix_multiply(int ROWS, int COLUMNS, float **A, float **B, float **C){
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

void openmp_matrix_multipl(int ROWS, int COLUMNS, float **A, float **B, float **C){
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

int main( int argc, char *argv[] )  {
    if( argc == 3 ) {
        printf("Will compute");
    }
    else if( argc > 3 ) {
        printf("I need 1 argument (arraysize)..... Too many arguments supplied.\n");
        exit(1);
    }
    else {
        printf("I need 1 argument (arraysize)..... Too few arguments supplied.\n");
        exit(1);
    }

    int ROWS;
    int COLUMNS;
    sscanf(argv[1], "%d", &ROWS);
    sscanf(argv[2], "%d", &COLUMNS);

    float A[ROWS][COLUMNS];    // result
    float B[ROWS][COLUMNS];    // result
    float C[ROWS][COLUMNS];    // result


    auto sensor = pmt::rapl::Rapl::create();
    auto start = sensor->read();

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

    //simple_matrix_multiply(); // Do the matrix multiplication
    auto end = sensor->read();


    std::cout<<"RESULTS-------"<<std::endl;
    std::cout<<"Matrix Size: "<<ROWS<<std::endl;
    std::cout <<"PMT Seconds: "<< pmt::PMT::seconds(start, end) << " s"<< std::endl;
    std::cout <<"PMT Joules: " << pmt::PMT::joules(start, end) << " J" << std::endl;
    std::cout <<"PMT Watts: " << pmt::PMT::watts(start, end) << " W" << std::endl;

    
    
    //initialize_matrices(); // We need to re-intiaize to make sure we get "correct answer"

    //start = sensor->read();
    //openmp_matrix_multiply(); // Do the matrix multiplication
    //end = sensor->read();

    //std::cout <<"PMT seconds: "<< pmt::PMT::seconds(start, end) << " s"<< std::endl;
    //std::cout <<"PMT Joules: " << pmt::PMT::joules(start, end) << " J" << std::endl;
    //std::cout <<"PMT Watts: " << pmt::PMT::watts(start, end) << " W" << std::endl;
    
    return 0;
}
