// C program to demonstrate
// use of sleep function
// till 10 milliseconds in Windows.
#include <stdio.h>
#include <unistd.h>

int main( int argc, char *argv[] )  {
    if( argc == 2 ) {
        printf("Will compute");
    }
    else if( argc > 2 ) {
        printf("I need 1 argument (sleep time in sec)..... Too many arguments supplied.\n");
        return 1;
    }
    else {
        printf("I need 1 argument (sleep time in sec)..... Too few arguments supplied.\n");
        return 1;
    }

    int sleep_time;
    sscanf(argv[1], "%d", &sleep_time);

    //%d Threads\n", num_threads
 
    printf("Program to sleep for %d seconds.\n",sleep_time);
 
    sleep(sleep_time);
 
    return 0;
}