#include <stdio.h>
#include <omp.h>

int main(){
int myid, nthreads;

    #pragma omp parallel private(myid)
    {
        myid = omp_get_thread_num();
        nthreads = omp_get_num_threads();

        printf("Hello world. I am thread %d of %d\n", myid, nthreads);
 }
 return 0;
 }
