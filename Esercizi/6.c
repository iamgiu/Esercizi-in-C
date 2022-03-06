/*Si realizzi un programma in linguaggio C che acquisisca da tastiera un numero e stampi
un messaggio che indichi se tale numero sia positivo oppure negativo.*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

  //Definisco le variabili
  int a;

  //Leggi il numero
  printf("Inserisci un numero: ");
  scanf("%d", &a);

  //Verico se il numero è + o -
  if (a >= 0) {
    printf("Il numero %d e' positivo\n", a);
  }
  else {
    printf("Il nmumero %d e' negativo\n", a);
  }

  return 0;
}
