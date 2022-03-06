/*Si scriva un programma in linguaggio C che, dato un numero reale D immesso da tastiera,
calcoli e stampi:
1. l’area del quadrato di lato D
2. l’area del cerchio di diametro D
3. l’area del triangolo equilatero di lato D*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {

  //Definisco le varibiali
  float d, aq, ac, at, r, rad3_4; //rad3_4 costante pari a radice(3)/4

  rad3_4 = sqrt(3) / 4;

  //Leggi il numero
  printf("Inserisci un numero: ");
  scanf("%f", &d);

  //Area del quadrato
  aq = pow(d, 2); //definito da una libreria pow oppure aq = d * d

  //Area del cerchio di diametro d
  r = d / 2;
  ac = M_PI * pow(r, 2); /*nota: il valore di PI greco e’ definito in math.h come M_PI*/

  //Area triangolo equilatero di lato d
  at = rad3_4 * pow(d, 2);

  //Stampa il risultato
  printf("\n");
  printf("Le aree calcolate sono:\n");
  printf("Area del quadrato di lato %f = %f\n", d, aq);
  printf("Area del cerchio di diametro %f = %f\n", d, ac);
  printf("Area triangolo equilatero di lato %f = %f\n", d, at);

  return 0;
}
