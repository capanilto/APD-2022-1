#include <stdio.h>
#include <omp.h>



int main(){
    int myid, nthreads, i;


    #pragma omp parallel private(myid)
    {
        myid = omp_get_thread_num();
        nthreads = omp_get_num_threads();
        i = omp_get_thread_num();
        printf("Hello world. I am thread %d - %d of %d\n", myid, i, nthreads);
        i = omp_get_thread_num();
        printf("Hello world. I am thread %d - %d of %d\n", myid, i, nthreads);

        printf("Hello world. I am thread %d - %d of %d\n", myid, i, nthreads);


    }
 return 0;
 }
