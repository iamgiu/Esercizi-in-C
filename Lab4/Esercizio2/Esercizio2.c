/*Si scriva una funzione C in grado di permettere all'utente di far ruotare verso destra o verso sinistra i
contenuti di un vettore di N interi, di un numero a scelta di posizioni P.
Il vettore è da intendersi come circolare, nel senso che l’elemento a destra della cella di indice N-1 è la cella di indice 0 e l’elemento
a sinistra della cella di indice 0 è la cella di indice N-1. La figura seguente illustra una rotazione a
destra di 3 posizioni:

1 2 3 4 5 6 -> 4 5 6

La funzione abbia il seguente prototipo:

void ruota(int v[maxN], int N, int P, int dir);

Il main:
  1. acquisisca da tastiera N (N ≤ maxN con maxN pari a 30)
  2. acquisisca da tastiera il vettore V
  3. effettui ripetutamente delle rotazioni, acquisendo ciascuna volta P (P < N, P=0 per terminare) e la
  direzione (dir =-1 per rotazione a destra, dir = 1 per rotazione a sinistra) e stampi il vettore risultante.*/

#include <stdio.h>
#define maxN 30

void ruota(int V[maxN], int N, int P, int dir);

int main() {
  int V[maxN], N, P = 1, dir;

  printf("Quanti valori vuoi inserire? Per una massimo di 30: ");
  scanf("%d", &N);

  if (N <= maxN) {
    for (int i = 0; i < N; i++) {
      printf("Inserisci il numero nella posizione %d: ", i);
      scanf("%d", &V[i]);  //Per inserire un valore da tastiera
    }

    // while () {
      printf("Inserire posizioni (P < N, 0 per terminare): ");
      scanf("%d", P);
    //}

    printf("Inserire la direzione: (-1 per rotazione a destra, 1 per rotazione a sinistra): ");
    scanf("%d", &dir);

    ruota(V, N, P, dir);
  }
  else {
    printf("Errore!");
  }
}

void ruota(int V[maxN], int N, int P, int dir) {
  printf("Ciao");
}
