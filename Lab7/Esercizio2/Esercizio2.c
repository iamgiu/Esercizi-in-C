/*Si considerino i seguenti algoritmi di ordinamento per ordinare in maniera ascendente vettori di interi:

• Selection Sort
• Insertion Sort
• Shell Sort

Si scriva un programma in C che per ogni sequenza numerica acquisita da file (sort.txt) invochi tutti gli algoritmi di
ordinamento sopra indicati e stampi a video:
• il numero di scambi
• il numero di iterazioni del ciclo esterno
• per ogni passo del ciclo esterno, il numero di iterazioni del ciclo interno
• il numero totale di iterazioni.

Il file sort.txt è caratterizzato dal seguente formato:
• la prima riga riporta il numero S di sequenze numeriche contenute nel file
• le successive S righe riportano, una per riga, le seguenti informazioni:
<lunghezza> <sequenza>
dove <lunghezza> è un intero non negativo (al massimo 100) che rappresenta la lunghezza della sequenza riportata su tale riga,
mentre <sequenza> è una sequenza di <lunghezza> numeri interi separati da uno spazio.

Esempio del file sort.txt:

4
5 1 2 3 4 5
5 1 2 3 4 0
5 5 4 3 2 1
5 1 5 2 4 3*/

#include <stdio.h>

#define file "sort.txt"
#define N 100

void selectionSort(int s[], int seq);
void insertionSort(int [], int seq);
void shellSort(int s[], int seq);
void stampaVettore(int s[], int seq);

int main() {
   int s1[N], s2[N], s3[N], seq, num, cont=1;
   FILE *fp;

   if((fp = fopen(file, "r")) == NULL) {
      printf("Error opening file!\n");
      return 1;
   }

   if(!feof(fp)) {
      fscanf(fp, " %d ", &seq);
   }

   for(int i = 0; i < seq; i++) {
      if(!feof(fp)) {
        fscanf(fp, " %d ", &num);
      }
      for(int j = 0; j < num; j++) {
        if(!feof(fp)) {
         fscanf(fp, " %d ", &s1[j]);
         s2[j] = s1[j];
         s3[j] = s1[j];
        }
      }
      printf("SEQUENZA %d:\n", cont);
      selectionSort(s1, num);
      printf("\n");
      insertionSort(s2, num);
      printf("\n");
      shellSort(s3, num);
      printf("\n");
      cont++;
    }
    return 0;
}

void selectionSort(int s[], int seq) {
   int i, j, min, temp, scambi = 0, iterEsterno = 0, iterInterno = 0, iterTot = 0;
   for(i = 0; i < seq; i++, iterEsterno++) {
      min = i;
      for(j = i + 1; j < seq; j++, iterInterno++) {
         if(s[j] < s[min]) {
            min = j;
         }
      }
      if(min != i) {
         temp = s[i];
         s[i] = s[min];
         s[min] = temp;
         scambi++;
      }
   }
   iterTot = iterEsterno + iterInterno;
   printf("SELECTION SORT: \n");
   printf("Scambi effettuati: %d\n", scambi);
   printf("Iterazioni esterne: %d\n", iterEsterno);
   printf("Iterazioni interne: %d\n", iterInterno);
   printf("Iterazioni totali: %d\n", iterTot);
}

void insertionSort(int s[], int seq) {
   int i, j, x, scambi = 0, iterEsterno = 0, iterInterno = 0, iterTot = 0;
   for(i = 0; i < seq; i++, iterEsterno++) {
      x = s[i];
      for(j = i - 1; j >= 0 && x < s[j]; j--, iterInterno++) {
         s[j+1] = s[j];
         scambi++;
      }
      if(j+1 != i) {
         scambi++;
      }
      s[j+1] = x;
   }
   iterTot = iterEsterno + iterInterno;
   printf("INSERTION SORT: \n");
   printf("Scambi effettuati: %d\n", scambi);
   printf("Iterazioni esterne: %d\n", iterEsterno);
   printf("Iterazioni interne: %d\n", iterInterno);
   printf("Iterazioni totali: %d\n", iterTot);
}

void shellSort(int s[], int seq) {
   int i, j, h = 1, x, scambi = 0, iterEsterno = 0, iterInterno = 0, iterTot = 0;
   while (h < seq/3)
      h = 3*h+1;
   while(h >= 1) {
      for (i = h; i < seq; i++, iterEsterno++) {
         j = i;
         x = s[i];
         for(j = i; j >= h && x < s[j-h]; j-=h, iterInterno++) {
            s[j] = s[j-h];
            scambi++;
         }
         if(j != i) {
            scambi++;
         }
         s[j] = x;
      }
      h = h/3;
   }
   iterTot = iterEsterno + iterInterno;
   printf("SHELL SORT: \n");
   printf("Scambi effettuati: %d\n", scambi);
   printf("Iterazioni esterne: %d\n", iterEsterno);
   printf("Iterazioni interne: %d\n", iterInterno);
   printf("Iterazioni totali: %d\n", iterTot);
}

void stampaVettore(int s[], int seq) {
   int i;
   for(i = 0; i < seq; i++) {
      printf(" %d ", s[i]);
   }
   printf("\n");
}
