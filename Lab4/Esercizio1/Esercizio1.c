/*Sia V un vettore di N interi (con N≤30). Si scriva un programma in C che, una volta acquisito da tastiera
(o da file, la scelta è libera) il contenuto del vettore, chiami una funzione avente prototipo sottoSequenze(int V[], int N);
La funzione visualizzi tutti i sottovettori di dimensione massima formati da celle contigue, contenenti dati non nulli.

Esempio:
dato il vettore [1 3 4 0 1 0 9 4 2 0], i due sottovettori di dimensione massima (3) contenenti dati non nulli sono [1 3 4] e [9 4 2].

Suggerimenti:
Si noti che il problema può essere affrontando risolvendo due sottoproblemi:
  • identificare sottovettori di dati non nulli
    o è sufficiente “riconoscere” l’inizio e la fine di tali sottovettori
  • selezionare quelli di lunghezza massima:
    o un metodo semplice consiste nel “provare” tutte le lunghezze in modo decrescente,
      ferman-dosi alla prima lunghezza per cui si trovano sottovettori;
    o un metodo più efficiente consiste nel determinare prima la lunghezza massima e poi cercare i sottovettori corrispondenti
    o si potrebbe anche (in alternativa) cercare di fare una sola iterazione sul vettore principale per riconoscere i sottovettori,
      determinare la lunghezza massima e “ricordare” (usando un altro vettore) gli inizi dei sotto-vettori:
      ma la complessità/efficienza non cambierebbe (oc-correrebbe comunaue una ulteriore iterazione per stampare i sotto-vettori)
      e (probabilmen-te) il programma sarebbe più complicate che nella versione precedente.*/

#include <stdio.h>

int sottoSequenze(int V[], int N);

int main(void) {

  int V[30], N;

  printf("Quanti valori vuoi inserire? Per una massimo di 30: ");
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    printf("Inserisci il numero nella posizione %d: ", i);
    scanf("%d", &V[i]);  //Per inserire un valore da tastiera
  }

  sottoSequenze(V, N);

  return 0;
}

int sottoSequenze(int V[], int N) {
  int seq = 0, max = 0;

  printf("La sequenza di numeri e': ");
  for (int k = 0; k < N; k++) {
    printf("%d ", V[k]);
    if (V[k] != 0) {
      seq++;
    }
    else {
      if (seq > max) {
        max = seq;
      }
      seq = 0;
    }
  }

  if (seq > max) {
    max = seq;
  }
  printf(", i sottovettori di dimensione massima %d contenenti dati non nulli sono: ", max);
  seq = 0;
  for (int k = 0; k < N; k++) {
    if (V[k] != 0) {
      seq++;
    }
    else {
      seq = 0;
    }
    if (seq == max) {
      printf("[");
      for (int j = max; j >= 1; j--) {
        printf("%d ", V[k+1-j]);
      }
      printf("] ");
    }
  }

}
