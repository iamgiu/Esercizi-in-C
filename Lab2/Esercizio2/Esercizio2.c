/*Scrivere un programma in linguaggio C che visualizzi i primi N numeri della serie di Fibonacci, con N acquisito in input da tastiera.
Suggerimento: ecco i primi numeri appartenenti alla serie 0 1 1 2 3 5 8 …
In modo formale la serie si costruisce considerando la seguente relazione: Xi = Xi-1 + Xi-2, con X0 = 0 e X1 = 1;
Approfondimento: si modifichi la serie come segue:
Xi = Xi-1 * Xi-2, con X0 = 1 e X1 = 2;
Si determini sperimentalmente (osservando i risultati ottenuti) quanti sono gli elementi di questa serie rappresentabili
con variabili di tipo intero (int) e di tipo intero senza segno (unsigned int)*/

#include <stdio.h>

int main(void) {

  int f0 = 0, f1 = 1, n, i, fn;

  printf("Inserisci un numero: ");
  scanf("%d", &n);

  printf("%d %d ", f0, f1);
  for (i = 2; i < n; i++) {
      fn = f0 + f1;
      printf("%d ", fn);
      f0 = f1;
      f1 = fn;
    }
    return 0;
}
