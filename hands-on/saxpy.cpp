#include<stdlib.h>
#include<iostream>     // std::cout, std::endl
#include<iomanip>      // std::setprecision
#include<pmt.h>        


void saxpy(int n, float a, float * x, float * y){
    for(int i=0; i<n; i++){
        y[i] = a * x[i] + y[i];
    }
}

int main( int argc, char *argv[] )  {

    if( argc == 2 ) {
        printf("Will compute a*x + y");
    }
    else if( argc > 2 ) {
        printf("I need 1 argument (arraysize)..... Too many arguments supplied.\n");
        exit(1);
    }
    else {
        printf("I need 1 argument (arraysize)..... Too few arguments supplied.\n");
        exit(1);
    }
    int N;
    sscanf(argv[1], "%d", &N);
    printf("with size of arrays x,y of size (%d) \n", N);
    float x[N]; /* n is an array of N integers */
    float y[N]; /* n is an array of N integers */


    auto sensor = pmt::rapl::Rapl::create();
    auto start = sensor->read();
    saxpy(N,2.0,x,y);

    auto end = sensor->read();
    std::cout << std::setprecision(5) <<"PMT: Seconds "<< pmt::PMT::seconds(start, end) << " s"<< std::endl;
    std::cout << std::setprecision(5) <<"PMT: Joules " << pmt::PMT::joules(start, end) << " J" << std::endl;
    std::cout << std::setprecision(5) <<"PMT: Watts " << pmt::PMT::watts(start, end) << " W" << std::endl;

}