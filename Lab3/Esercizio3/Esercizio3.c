/*E’ data una sequenza di numeri interi, contenuta in un file testo (numeri.txt,
come nome definito con #define), nel quale gli interi sono separati da spazio o
a-capo.

Occorre verificare che l’i-esimo numero xi (con i ≥2) sia, rispetto ai due numeri precedenti (xi-1 e xi-2),
pari alla loro somma (xi-2 + xi-1), differenza (xi-2 - xi-1), prodotto (xi-2 * xi-1) o quoziente (xi-2 / xi-1)
(attenzione a evitare le divisioni per 0!). Se un dato non è corretto, va scartato e si passa a verificare il successivo (ignorando il dato scartato).

Occorre inoltre individuare il massimo e il minimo tra i dati della sequenza (ignorando i dati eventualmente scartati). Al termine stampare a video:
1. il risultato della verifica, cioè se tutti i dati rispettano la regola o se qualcuno (indicare quanti) sia stato scartato
2. I valori massimo e minimo tra i numeri in sequenza, escludendo quelli eventualmente scartati.

Contenuto di numeri.txt:                                                        Messaggi stampati a video:                                       Motivazione:
12                                                                              Numero massimo: 12                                               Vengono scartati:
3                                                                               Numero minimo: -3                                                 - 0 perchè non è risultato di alcuna operazione su 7 e -3
4                                                                               Numeri scartati: 2                                                - 11 perchè non è risultato di alcuna operazione su 3 e 9
7 -3
0
4
1
3
3 9
11*/

#include <stdio.h>
#define FILE_IN "numeri.txt"

int main () {
  FILE *fin;
  int x1, x2, x3, scartati = 0, max, min, bol;

  if ((fin = fopen(FILE_IN, "r")) == NULL) {
      printf("Error opening file\n");
      return -1;
  }


  if (!feof(fin)) {
    fscanf(fin, "%d", &x1);
    if (!feof(fin)) {
      fscanf(fin, "%d", &x2);
    }
    max = x1;
    min = x1;
  }

  while (!feof(fin)) {
    fscanf(fin, "%d", &x3);

    if (!feof(fin)) {
      bol = (x3 == (x1 + x2)) || (x3 == (x1 - x2)) || (x3 == (x1 * x2)) || (x3 == (x1 / x2) && x2 != 0); //valore da utilizzare nell'if

      if (!bol) {
        printf("%d numero scartato, non e' un risultato di nessuna operazione tra %d e %d\n", x3, x1, x2);
        scartati++;
      }
      else {
        if (x1 > max) {
          max = x1;
        }
        if (x1 < min) {
          min = x1;
        }

        x1 = x2;
        x2 = x3;
      }
    }
  }

  if (x1 > max) {
    max = x1;
  }
  if (x2 > max) {
    max = x2;
  }
  if (x1 < min) {
    min = x1;
  }
  if (x2 < min) {
    min = x2;
  }

  printf("Numero massimo: %d\nNumero minimo: %d\nNumeri scartati: %d\n", max, min, scartati);
  return 0;
}
