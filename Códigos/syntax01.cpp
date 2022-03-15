#include   <omp.h>
#include <stdio.h>
#define NT 4
#define thrd_no omp_get_thread_num

int main(){
    #pragma omp parallel for num_threads(NT)                 // PRAG 1
    for(int i=0; i<NT; i++) printf("1 -thrd no %d\n",thrd_no());

    #pragma omp parallel for \
                num_threads(NT)                              // PRAG 2
    for(int i=0; i<NT; i++) printf("2 - thrd no %d\n",thrd_no());

    #pragma omp parallel num_threads(NT)                     // PRAG 3-4
    #pragma omp for
    for(int i=0; i<NT; i++) printf("3 - thrd no %d\n",thrd_no());

    #pragma omp parallel num_threads(NT)                     // PRAG 5
    {
       int no = thrd_no();
       if (no%2) { printf("4 - thrd no %d is Odd \n",no);}
       else      { printf("5 - thrd no %d is Even\n",no);}

       #pragma omp for
       for(int i=0; i<NT; i++) printf("6 - thrd no %d\n",thrd_no());
    }
}
