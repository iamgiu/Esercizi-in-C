//Si scriva un programma in linguaggio C che legga due valori interi e visualizzi la loro somma.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int a, b;
  int c;

  /*Stampa cosa esegue il programma*/
  printf("Somma due numeri\n\n");

  //Leggi gli addendi
  printf("Immetti il primo numero: ");
  scanf("%d", &a);

  printf("Immetti il primo numero: ");
  scanf("%d", &b);

  //Calcola la Somma
  c = a + b;

  //Stampa il risultato
  printf("\n");
  printf("La somma %d + %d è uguale a %d\n", a, b, c);

  exit(0);
}
