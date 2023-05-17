#include <stdio.h> // needed for ‘printf’ 
#include <stdlib.h> // needed for ‘RAND_MAX’ 
#include <string.h> // needed for strcmp
#include <stdbool.h> // needed for bool usage
#include <ctype.h> // needed for isdigit
#include <omp.h> // needed for OpenMP 
#include <time.h> // needed for clock() and CLOCKS_PER_SEC etc


void printUsage()
{
    fprintf(stderr, "mat_mul (matrix size) [-s|-p|-h]\n");
    fprintf(stderr, "\t      Invoke simple implementation of matrix multiplication\n");
    fprintf(stderr, "\t-s    Invoke simple implementation of matrix multiplication\n");
    fprintf(stderr, "\t-p    Invoke parallel (OpenMP) implementation of matrix multiplication\n");
    fprintf(stderr, "\t-h    Display help\n");
}

bool isNumber(char number[])
{
    int i = 0;

    //checking for negative numbers
    if (number[0] == '-')
        i = 1;
    for (; number[i] != 0; i++)
    {
        //if (number[i] > '9' || number[i] < '0')
        if (!isdigit(number[i]))
            return false;
    }
    return true;
}


void initialize_matrices(float** A, float** B, float** C, int ROWS, int COLUMNS){
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

void simple_matrix_multiply(float** A, float** B, float** C, int ROWS, int COLUMNS){
    
    printf("(Simple) Matix Multiplication of 2D matricies of equal sizes (%d, %d)\n",ROWS,COLUMNS);

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

void openmp_matrix_multiply(float** A, float** B, float** C, int ROWS, int COLUMNS){
    
    int num_threads = omp_get_max_threads();
    
    printf("(OpenMP) Matix Multiplication of 2D matricies of equal sizes (%d, %d)\n",ROWS,COLUMNS);
    printf("Using %d Threads\n", num_threads);
    
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

  int ROWS;
  int COLUMNS;

  /* bools needed for the argument parsing logic */
  bool openmp = false;
  bool simple = true;
  bool sanity_check = false;

  /* Parse the arguments */
  for(int i=0; i<argc; ++i)
  {   
      if (! strcmp("-s", argv[i]))
      {
          simple = true;
      }
      else if (! strcmp("-p", argv[i]))
      {
          openmp = true;
          simple = false;
      }
      else if (!strcmp("-h", argv[i]))
      {
          printUsage();
          return (EXIT_FAILURE) ;
      }
      else if (isNumber(argv[i])){
        sscanf(argv[1], "%d", &ROWS);
        sscanf(argv[1], "%d", &COLUMNS);
        sanity_check = true;
      }
  }
  /* Dumb logic to make sure an array size was passed */
  if (! sanity_check){
      printf("I need (arraysize) as an argument ..... Exiting.\n");
      return (EXIT_FAILURE);
  }

  /* declare the arrays */
  float **A;
  float **B;
  float **C;

  /* allocate the arrays */
  A = malloc(ROWS * sizeof *A);
  B = malloc(ROWS * sizeof *B);
  C = malloc(ROWS * sizeof *C);
  for (int i=0; i<ROWS; i++)
  {
    A[i] = malloc(COLUMNS * sizeof *A[i]);
    B[i] = malloc(COLUMNS * sizeof *B[i]);
    C[i] = malloc(COLUMNS * sizeof *C[i]);
  }

  /*======================================================================*/
  /*                START of Section of the code that matters!!!          */
  /*======================================================================*/

  /* initialize the arrays */
  initialize_matrices(A, B, C, ROWS, COLUMNS);

  /* Simple matrix multiplication */
  if (true == simple)
  {
    clock_t t; // declare clock_t (long type)
    t = clock(); // start the clock
    
    simple_matrix_multiply(A, B, C, ROWS, COLUMNS);
    
    t = clock() - t; // stop the clock

    double time_taken = ((double)t)/CLOCKS_PER_SEC; // convert to seconds (and long to double)
    printf("TIME: %f sec\n",time_taken);
  }
  /* OpenMP parallel matrix multiplication */
  if (true == openmp)
  {
    // omp_get_wtime needed here because clock will sum up time for all threads
    double start = omp_get_wtime();  

    openmp_matrix_multiply(A, B, C, ROWS, COLUMNS);
    
    double end = omp_get_wtime(); 
    printf("TIME: %f sec\n",(end-start));
  }

  /*======================================================================*/
  /*                 END of Section of the code that matters!!!           */
  /*======================================================================*/

  /* deallocate the arrays */
  for (int i=0; i<ROWS; i++)
  {
    free(A[i]);
    free(B[i]);
    free(C[i]);
  }
  free(A);
  free(B);
  free(C);
}