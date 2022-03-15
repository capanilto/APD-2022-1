#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

void hello(void);

int main () {

    #pragma omp parallel num_threads(12)
    hello();

    return 0;

}

void hello(void) {
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();
    int cores = omp_get_num_procs();

    printf("Hello vindo da thread %d de %d - %d cores\n", my_rank, thread_count, cores);
}
