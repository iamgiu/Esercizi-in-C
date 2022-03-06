/*Si realizzi un programma in linguaggio C che acquisisca da tastiera un numero e stampi il
valore assoluto di tale numero.*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

  //Definisco le varibiali
  int a, b; //b = corrispondente valore assoluto

  //Legggi il nmumero
  printf("Inserisci un numero: ");
  scanf("%d", &a);

  //Verifico se il numero è positivo o negativo
  if (a >= 0) {
    printf("Il numero %d e' positivo\n", a );

    //Assegno a b il numero di a
    b = a;
  }
  else {
    printf("Il numero %d e' negativo\n", a );

    //Assegno a b il numero di a cambiando il segno
    b = -a;

    //Stampo il risultato
    printf("Il valore assoluto di %d e' %d\n", a, b);
  }

  return 0;
}









/* Soluzione alternativa proposta esercizio "Valore assoluto" */
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int a ; /* numero inserito ed il corrispondente valore assoluto*/

  /* LEGGI IL NUMERO */
  printf("Immetti un numero: ") ;
  scanf("%d", &a) ;

  /* STAMPA IL NUMERO */
  printf("Il numero inserito e’ %d\n", a) ;

  /* VERIFICA SE IL NUMERO E’ NEGATIVO */
  if ( a < 0 ){
    /* SE IL NUMERO E’ NEGATIVO, IL VALORE ASSOLUTO E’ OTTENUTO CAMBIANDO
    IL SEGNO DEL NUMERO */
    a = -a ;
  }
  /* STAMPA IL RISULTATO */
  printf("Il valore assoluto del numero inserito e’ %d\n", a) ;

  exit(0) ;
}
