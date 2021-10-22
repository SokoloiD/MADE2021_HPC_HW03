#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <omp.h>
 
const long N = 1000000;

int main()
{
   
    long count=0;
    double pi;
    
    #pragma omp parallel for reduction(+: count)
    for (long i=0; i<N; i++) {

        unsigned int seed1 = i ;
        unsigned int seed2 = i * omp_get_thread_num();

        double x = (double)rand_r(&seed1) / (double)RAND_MAX;
        double y = (double)rand_r(&seed2) / (double)RAND_MAX;
        
        if ( x * x + y * y <= 1)
            count +=1;
  
    }
    
    pi=((double)count/(double)N) * 4.0;

    printf("Iteration count = %ld ,  pi approx = s %1.20f \n",N,pi);

    return 0;
}