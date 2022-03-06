// Si scriva un programma in linguaggio C che legga un valore intero e visualizzi il valore intero precedente e il successivo.

#include <stdio.h>
#include <stdlib.h>

int main(void) {

  //Variabili
  int a, prec, succ;

  //Leggi il numero
  printf("Immetti il numero: ");
  scanf("%d", &a);

  //Calcola il numero precedente
  prec = a - 1;

  //Calcola il numero successivo
  succ = a + 1;

  //Stampa il risultato
  printf("\n");
  printf("Il numero inserito e' %d\n", a);
  printf("Il numero precedente a %d e' %d\n", a, prec );
  printf("Il numero successivo a %d e' %d\n", a, succ );

  return 0;
}
