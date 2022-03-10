/*Utilizzando l’ambiente di sviluppo creare un nuovo progetto e scrivere il seguente pro-gramma in linguaggio C.
Verificare, inoltre, che non siano presenti errori in fase di compila-zione.
Dopo aver compilato il codice, eseguirlo ed esercitarsi con l’esecuzione del debug
osservan-do il valore delle variabili x, y e z, provare con diversi valori: 0, 9, 15, 20.*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int x, y;
  float z;

  printf("Insert an integer number: ");
  scanf("%d", &x);

  y = 3;

  z = (float)(x) / y;

  printf("%d/%d = %.3f\n", x, y, z);

  return 0;
}
