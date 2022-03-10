/*Si scriva un programma che calcoli l’area di un cerchio o di un quadrato in base alla scelta dell’utente.
L’utente può specificare se calcolare l’area del quadrato (Q) tramite la lunghezza della diagonale (D) o del lato (L),
mentre l’area del cerchio (C) specificando se tramite il diametro (D) oppure il raggio (R).
Esempio: Se l’utente inserisce Q D10, il programma dovrà stampare a schermo Area Qua-drato = 50.0
In particolare:
a) Si definisca una costante P tramite #define, e gli si assegni il valore 3.14, (nota: con la define non si mette né l’= né il ;)
b) Si acquisiscano i caratteri da tastiera.
c) Si calcoli il valore dell’area in base alla scelta dell’utente.
d) Si stampi il risultato a video.
Nota: Quadrato: Area = L*L = D*D/2, Cerchio: Area = pi*R*R = pi*D*D/4)*/

#include <stdio.h>
#define PIGRECO 3.14
#define N 10

int main(void) {

  char stringa[N], figura, dato;
  float valore, area;

  printf("Inserire Q se si vuole cacolare l'area di un quadrato specificando se il valore inserito si tratta della diagonale o del lato (D o L) oppure si inserisca C se si vuole calcolare l'area di un cerchio specificando se il valore inserito e' il raggio o il diametro (R o D): ");
  gets(stringa);
  sscanf(stringa, "%c %c%f", &figura, &dato, &valore);

  switch(figura) {
    case 'Q':
      switch(dato) {
        case 'D':
          area = (valore*valore)/2;
          printf("L'area del quadrato con diagonale %f e': %f", valore, area);
          break;
        case 'L':
          area = valore*valore;
          printf("L'area del quadrato con lato %f e': %f", valore, area);
          break;
        default:
          printf("Errore");
          break;
      }
      break;
    case 'C':
      switch(dato) {
        case 'D':
          area = (valore*valore*PIGRECO)/4;
          printf("L'area del cerchio con diametro %f e': %f", valore, area);
          break;
        case 'R':
          area = valore*valore*PIGRECO;
          printf("L'area del cerchio con raggio %f e': %f", valore, area);
          break;
        default:
          printf("Errore");
          break;
      }
      break;
    default:
      printf("Errore");
      break;
  }
  return 0;
}
