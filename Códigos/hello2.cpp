#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include <sched.h>

int main () {

    int x = 16;
    double a[x], b[x], c[x];
    #pragma omp parallel for
    for (int i=0; i<x; i++) {
        a[i] = 2;
        b[i] = 3.2 + i;
        c[i] = pow(b[i], a[i]);

        int my_rank = omp_get_thread_num();
        int thread_count = omp_get_num_threads();
        printf("\n %f", c[i]);
        printf(" - Hello from thread %d of %d \n", my_rank, thread_count);
        }

    return 0;

}
