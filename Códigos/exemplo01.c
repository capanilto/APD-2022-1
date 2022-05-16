/******************************************************************************
* DESCRIÇÃO:
*   Neste exemplo simples, a thread principal cria uma região paralela.
*   Todas as threads do time obtêm seu id de thread e o imprimem
*   A thread principal imprime apenas o número total de threads.
*   Duas rotinas OpemMP são usadas para obtero número de threads e
*   cada ID de thread.
* AUTHOR: Blaise Barney  5/99, modificado por José Anilto em 03/2022
******************************************************************************/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
int nthreads = 123, tid = 456; // experimente inicializar tid com algum valor

/* Cria um conjunto de threads (fork) dando a elas cópias das variáveis. */
#pragma omp parallel private(nthreads, tid)
  {

  /* Obtém o número da thread */
  tid = omp_get_thread_num();
  printf("Hello World from thread = %d\n", tid);

  /* Somente a thread 0 faz isto */
  if (tid == 0)
    {
    nthreads = omp_get_num_threads();
    printf("Number of threads = %d\n", nthreads);
    }

  }
  /* Todas as threads se juntam aqui (join) */
  printf("\n Valor de tid: %d\n\n", tid);
  printf("\n Valor de nthread: %d\n\n", nthreads);

}
/******************************************************************************
* OBSERVAÇÃO:
*   O que acontece se tirar o private() da linha19?
*   Provavelmente antes da execução do if da linha 27 alguma thread
*   altera o valor de tid, fazendo com que o resultado final seja inconsistente.
*
*   Experimente inicializar os valores de nthreads e tid.
*
*   Experimente tirar a cláusula private() e veja o que acontece com tid e nthreads
******************************************************************************/
