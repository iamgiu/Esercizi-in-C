/*Un file (ad esempio: sorgente.txt) contiene un testo composto da un numero indefinito di righe.
Notare che il testo NON contiene il carattere ‘$’.
Lo scopo del programma è di ricodificare il testo sostituendo una sequenza di caratteri ripetuti (da un minimo di 2 ad un massimo di 9 caratteri ripetuti)
con la seguente terna di caratteri:
<carattere ripetuto>$<numero di ripetizioni>
ATTENZIONE: il numero di ripetizioni non deve considerare la prima occorrenza del carattere: per esempio, AA contiene 1 ripetizione, BBB contiene 2 ripetizioni, etc.
Nel caso in cui un carattere sia ripetuto più di 9 volte, le ripetizioni devono essere spezzate in più intervalli.
Ad esempio:
- “AAAAAAAAAAAAA” deve essere codificato come “A$9A$2”
- “il numero 1000000 e’ grande” deve essere codificato come “il numero 10$5 e’ grande”
- “ci sono 15 = ripetuti: =============== e 4 punti….” deve essere codificato come “ci sono 15 = ripetuti: =$9=$4 e 4 punti.$3”
Il risultato della ricodifica sia salvato su un secondo file (ad esempio: compresso.txt).
Esempio:
Il contenuto del file sorgente.txt è:
Partenza Destinazione Costo
Parigi New York 1000
Roma Londra 700
Sidney Los Angeles 2222
Il file di uscita compresso.txt conterrà:
Partenza $5Destinazione $3Costo
Parigi $9New York $410$2
$4Roma $9 Londra $5700
$2Sidney $6Los Angeles $42$3
Si scrivano due funzioni, in grado di effettuare, rispettivamente, la compressione (codifica dal file originale a quello compresso) e la decompressione
(codifica dal file compresso a quello originale). I prototipi delle funzioni siano
int comprimi(FILE *fin, FILE *fout);
int decomprimi(FILE *fin, FILE *fout);
In caso di errore le funzioni ritornano come risultato 0, diversamente ritornano il numero di caratteri scritti nel file in uscita.
Il programma main deve:
- permettere all’utente di selezionare quale operazione effettuare: compressione o decompressione (tramite un opportuno input da tastiera)
- aprire i file di input e di output
- in base alla scelta dell’utente, richiamare la funzione di compressione o decompressione sui file aperti.
Nota: Si consiglia di usare un terzo file per il testo decompresso (ad esempio: decompresso.txt) evitando così di sovrascrivere, perdendolo, il file originale sorgente.txt*/

#include <stdio.h>

int compressione(FILE *fin, FILE *fout);
int decompressione(FILE *fin, FILE *fout);

int main(void) {

  char choice;
  FILE *fin, *fout;

  printf("Compressione (C) o decompressione (D): ");
  scanf("%c", &choice);

  switch(choice) {
    case 'C':
      if ((fin = fopen("sorgente.txt", "r+")) == NULL) {
          printf("Error opening file\n");
          return 1;
      }
      if ((fout = fopen("compresso.txt", "r+")) == NULL) {
          printf("Error opening file\n");
          return 2;
      }
      compressione(fin, fout);
      fclose(fin);
      fclose(fout);
      break;
    case 'D':
      if ((fin = fopen("compresso.txt", "r+")) == NULL) {
          printf("Error opening file\n");
          return 1;
      }
      if ((fout = fopen("decompresso.txt", "r+")) == NULL) {
          printf("Error opening file\n");
          return 2;
      }
      decompressione(fin, fout);
      fclose(fin);
      fclose(fout);
      break;
    default:
      printf("Errore nella digitazione!");
      break;
  }
  return 0;
}

int compressione(FILE *fin, FILE *fout) {
  int c = 0;
  char c1, c2;

  while ((c1 = fgetc(fin)) != EOF) {
    if (c == 0) {
      c2 = c1;
      c++;
    }
    else {
      if (c2 == c1) {
        c++;
        if (c == 10) {
          fprintf(fout, "%c$%d", c2, c - 1);
          c = 1;
          c2 = c1;
        }
      }
      else {
        if (c == 1) {
          fputc(c2, fout);
          c2 = c1;
        }
        else {
          if (c == 2) {
            fputc(c2, fout);
            fputc(c2, fout);
            c = 1;
            c2 = c1;
          }
          else{
            fprintf(fout, "%c$%d", c2, c - 1);
            c = 1;
            c2 = c1;
          }
        }
      }
    }
  }
  return 0;
}

int decompressione(FILE *fin, FILE *fout) {
  int c = 0;
  char c1, c2;

  while ((c1 = fgetc(fin)) != EOF) {
    if (c1 == '$') {
      c = fgetc(fin) - '0'; // - '0' -> trasforma da char ad int
      for (int i = 0; i < c; i++) {
        fprintf(fout, "%c", c2);
      }
    }
    else {
      c2 = c1;
      fputc(c2, fout);
    }
  }
  return 0;
}
