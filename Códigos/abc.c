/*
* @@name:       directive_syntax_pragma.1.c
* @@type:       C
* @@compilable: yes
* @@linkable:   yes
* @@expect:     success
*/
#include   <omp.h>
#include <stdio.h>

int main(){



    #pragma omp parallel num_threads(16)
    {
        int x = omp_get_thread_num() % 8;
        //int x = omp_get_num_threads();
        int y = omp_get_thread_num();
        printf("Nucleo %d thrd no %d\n", x , y);
    }


}
