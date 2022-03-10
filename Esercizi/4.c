/*Si scriva un programma in linguaggio C capace di compiere le 4 operazioni (somma, sottrazione,
moltiplicazione e divisione) tra due numeri reali inseriti da tastiera. Dopo che sono
stati inseriti i due numeri, detti A e B, il programma dovrà visualizzare i quattro valori
A+B, A-B, A*B, A/B. Si ipotizzi che sia B/=0.*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

  //Stampa di cosa fa il programma
  printf("Programma: Calcolatrice\n\n");

  //Defenisco le Variabili
  float a, b;
  float somma, differenza, moltiplicazione, quoziente;

  //Legge i due numeri
  printf("Inserire il primo numero: ");
  scanf("%f", &a);

  printf("Inserire il secondo numero (diverso da zero): ");
  scanf("%f", &b);

  //Calcoli
  somma = a + b;
  differenza = a - b;
  moltiplicazione = a * b;
  quoziente = a / b;

  //Stampo i risultati
  printf("I numeri inseriti sono: %f, %f\n", a, b);
  printf("La somma tra %f e %f e': %f\n", a, b, somma);
  printf("La differenza tra %f e %f e': %f\n", a, b, differenza);
  printf("La moltiplicazione tra %f e %f e': %for\n", a, b, moltiplicazione);
  printf("La divisione tra %f e %f e': %f\n", a, b, quoziente);

  return 0;
}
