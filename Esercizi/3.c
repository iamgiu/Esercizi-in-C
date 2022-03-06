//Si scriva un programma in linguaggio C che legga due valori interi e visualizzi la loro media aritmetica.

#include <stdio.h>
#include <stdlib.h>

int main(void) {

  //Definisco le Variabili
  int a, b;
  float media;

  //Stampa di cosa fa il programma
  printf("Calcolo della media di due numero\n\n");

  //Legge i due numeri
  printf("Inserisci il primo numero: ");
  scanf("%d", &a);

  printf("Inserisci il secondo numero: ");
  scanf("%d", &b);

  //Calcola la media dei due numeri
  media = (a + b) / 2;

  //Stampa il risultato
  printf("La media aritmetica dei due numeri inseriti %d e %d e': %f", a, b, media);

  return 0;
}
