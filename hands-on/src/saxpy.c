#include <stdio.h> // needed for ‘printf’ 
#include <stdlib.h> // needed for ‘RAND_MAX’ 
#include <string.h> // needed for strcmp
#include <stdbool.h> // needed for bool usage
#include <ctype.h> // needed for isdigit
#include <omp.h> // needed for OpenMP 
#include <time.h> // needed for clock() and CLOCKS_PER_SEC etc


void printUsage()
{
    fprintf(stderr, "saxpy (array size) [-s|-p|-h]\n");
    fprintf(stderr, "\t      Invoke simple implementation of Saxpy (Single precision A X plus Y)\n");
    fprintf(stderr, "\t-s    Invoke simple implementation of Saxpy (Single precision A X plus Y)\n");
    fprintf(stderr, "\t-p    Invoke parallel (OpenMP) implementation of Saxpy (Single precision A X plus Y)\n");
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


void simple_saxpy(int n, float a, float * x, float * y){

    printf("(Simple) saxpy of Array of size (%d)\n",n);

    for(int i=0; i<n; i++){
        y[i] = a * x[i] + y[i];
    }
}

void openmp_saxpy(int n, float a, float * x, float * y){
    int num_threads = omp_get_max_threads();

    printf("(OpenMP) saxpy of Array of size (%d)\n",n);
    printf("Using %d Threads\n", num_threads);

    #pragma omp parallel for
    for(int i=0; i<n; i++){
        y[i] = a * x[i] + y[i];
    }
}


int main( int argc, char *argv[] )  {

    int N;
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
          sscanf(argv[1],"%d", &N);
          sanity_check = true;
        }
    }
    /* Dumb logic to make sure an array size was passed */
    if (! sanity_check){
        printf("I need (arraysize) as an argument ..... Exiting.\n");
        return (EXIT_FAILURE);
    }

    float sx[N]; /* n is an array of N integers */
    float sy[N]; /* n is an array of N integers */

    /* Simple saxpy */
    /*==============================*/
    if (true == simple)
    {
      clock_t t; // declare clock_t (long type)
      t = clock(); // start the clock
    
      simple_saxpy(N, 2.0, sx, sy);
    
      t = clock() - t; // stop the clock    
      double time_taken = ((double)t)/CLOCKS_PER_SEC; // convert to seconds (and long to double)
      printf("TIME: %f sec\n",time_taken);
    }

    /* OpenMP parallel saxpy */
    /*==============================*/
    if (true == openmp)
    {

    // omp_get_wtime needed here because clock will sum up time for all threads
    double start = omp_get_wtime();  

    openmp_saxpy(N, 2.0, sx, sy);
    
    double end = omp_get_wtime(); 
    printf("TIME: %f sec\n",(end-start));

    }


}