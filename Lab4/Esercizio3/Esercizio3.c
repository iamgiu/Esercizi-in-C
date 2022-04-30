/* Un file di testo contiene una matrice di interi con il seguente formato:
  • la prima riga del file specifica le dimensioni della matrice (numero di righe nr e numero di colonne nc).
    Si assuma che entrambi i valori siano comunque al più pari a 20
  • ciascuna delle nr righe successive contiene gli nc valori corrispondenti a una riga della matrice, separati da uno o più spazi.

Si scriva un programma C che:
  • legga tale matrice dal file di ingresso, il cui nome (massimo 20 caratteri) sia letto da tastiera
  • chieda ripetutamente all’utente un valore dim compreso tra 1 e il minimo tra nr e nc e stampi tutte le sottomatrici quadrate di tale dimensione contenute nella matrice
  • termini l’iterazione se l’utente inserisce un valore non coerente con le dimensioni della matrice
  • determini e stampi al termine la sottomatrice quadrata, tra quelle precedentemente individuate, la somma dei cui elementi è massima.

Se ad esempio il file contenesse la seguente matrice di 3 righe per 4 colonne
  3 4
  1 2 3 4
  5 6 7 8
  9 0 1 1

e dim valesse 2, occorrerebbe visualizzare:

Le sottomatrici quadrate di dimensione 2 sono:
  1 2
  5 6
  2 3
  6 7
  3 4
  7 8
  5 6
  9 0
  6 7
  0 1
  7 8
  1 1

La sottomatrice con somma degli elementi massima (22) e’:
  3 4
  7 8*/

#include <stdio.h>
#include <stdlib.h>
#define R 20
#define C 20

void lettura(char file[], int matrice[][C], int *nr, int *nc);
void stampa(int matrice[][C], int nr, int nc);
int maxmat(int matrice[][C], int nr, int nc, int *maxdim);
void SottoMatrice(int matrice[][C], int nr, int c, int dim);

int main() {
  int matrice[R][C], nr, nc, maxdim, dim;
  char file[20];

  printf("Inserisci il nome del file da aprire: ");
  scanf("%s",file);

  lettura(file, matrice, &nr, &nc);

  printf("La matrice e': ");
  stampa(matrice, nr, nc);

  maxmat(matrice, nr, nc, &maxdim);

  printf("Inserisci un numeri minore o uguale a %d: ", maxdim);
  scanf("%d", &dim);

  printf("Le sottomatrici sono:\n");
  SottoMatrice(matrice, nr, nc, dim);

  return 0;
}

void SottoMatrice(int matrice[][C], int nr, int nc, int dim) {
  int maxSum = 0, appSum = 0, maxSub[dim][C], appSub[dim][C];

  for(int i = 0; i < nr - (dim - 1); i++) {
		for(int j = 0; j < nc - (dim - 1); j++) {
      for (int i2 = 0; i2 < dim; i2++) {
        for (int j2 = 0; j2 < dim; j2++) {
          appSum += matrice[i + i2][j + j2];
          appSub[i2][j2] = matrice[i + i2][j + j2];
        }
      }
      stampa(appSub, dim, dim);
      printf("\n");
      if (appSum > maxSum) {
        maxSum = appSum;
        for (int i2 = 0; i2 < dim; i2++) {
          for (int j2 = 0; j2 < dim; j2++) {
            maxSub[i2][j2] = appSub[i2][j2];
          }
        }
      }
      appSum = 0;
		}
	}
  printf("La matrice con la somma degli elementi massima (%d):\n", maxSum);
  stampa(maxSub, dim, dim);
}

void lettura(char file[], int matrice[][C], int *nr, int *nc) {
  FILE *fp;
  int r, c, i, j;

  fp=fopen(file,"r");

  fscanf(fp,"%d",&r);
  fscanf(fp,"%d",&c);

  *nr= r;
  *nc = c;

  for(i = 0; i < r; i++) {
    for(j = 0; j < c; j++) {
      fscanf(fp, "%d", &matrice[i][j]);
    }
 }

 printf("La matrice ha %d righe e %d colonne\n", r, c);

 fclose(fp);

}

void stampa(int matrice[][C], int nr, int nc) {
 int i, j;

 for(i = 0; i < nr; i++) {
    for(j = 0; j < nc; j++) {
      printf("%d ",matrice[i][j]);
    }
 printf("\n");
 }
}

int maxmat(int matrice[][C], int nr, int nc, int *maxdim) {
  int max;

  if (nr < nc) {
    max = nr;
  }
  else {
    max = nc;
  }

  *maxdim = max;

  printf("La dimensione massima della matrice quadrata e': %d\n", max);
}
