/*Un file contiene un testo composto da un numero non noto di caratteri.
Lo scopo del programma è di ricodificare il testo, generando un secondo file,
nel quale i caratteri sono stati ricodificati secondo le regole seguenti:

I caratteri numerici sono ricodificati nel seguente modo:
  • I caratteri numerici (‘0’…’9’) sono ricodificati nel carattere numerico posto k posizioni più avanti,
    con k che parte da 0 e viene incrementato di 1 ogni volta che un carattere numerico viene ricodificato
    (ATTENZIONE: gli incrementi sono effettuati MODULO 10, cioè, arrivati a 9 si riparte da 0).
    Ad esempio, se il file inizia con la riga: “Il numero 248 e’ pari”:
    - ‘2’ (k parte da 0) deve essere codificato come ‘2’+ 0 = ‘2’ (k diventa 1)
    - ‘4’ deve essere codificato come ‘4’ + 1 = ‘5’ (k diventa 2)
    - ‘8’ deve essere codificato come ‘8’ + 2 = ‘0’ (dopo aver superato ‘9’ si riparte da ‘0’)

I caratteri alfabetici sono ricodificati nel seguente modo:
  • Se un carattere alfabetico è preceduto da un carattere non alfabetico, resta inalterato
  • Se è preceduto da un carattere alfabetico (sia c0 il carattere precedente), il suo codice ASCII
    deve essere incrementato di h posizioni nell’insieme dei caratteri alfabetici (con h=c0-‘A’ se c0 è maiuscolo, h=c0-‘a’ se c0 è minuscolo).
    L’incremento di h è MODULO 26, cioè arrivati alla ‘z’ o ‘Z’ (a seconda che il carattere ricodificato sia maiuscolo o minuscolo)
    si riparte da ‘a’ o ‘A’.

Il risultato della ricodifica sia salvato su un secondo file (I nomi dei file siano opportunamente acquisiti da tastiera).

Esempio:
Se il contenuto del file è:
  Apelle figlio di Apollo
  fece una palla di pelle di pollo
  tutti i pesci vennero a galla
  per vedere la palla di pelle di pollo
  fatta da Apelle figlio di Apollo.

Il file di uscita codificato conterrà:
  Aptept fntema dl Apdozn fjlp uhh ppall dl ptept dl pdozn tngzh i ptlnv vzmzdui a
  ggrcc ptk vzcgxb ll ppall dl ptept dl pdozn ffyrr dd Aptept fntema dl Apdozn.

Si scrivano due funzioni, in grado di effettuare, rispettivamente, la codifica
(dal file di origine al file codificato) e la decodifica (dal file codificato al file di origine).

I prototipi delle funzioni siano:
int codifica(FILE *fin, FILE *fout);
int decodifica(FILE *fin, FILE *fout);

In caso di errore le funzioni ritornano come risultato 0, diversamente ritornano il numero di caratteri scritti nel file in uscita.

Il programma main deve:
  - permettere all’utente di selezionare quale operazione effettuare: codifica o decodifica (tramite un opportuno input da tastiera)
  - acquisire da tastiera i nomi dei file di input e output
  - aprire i file di input e di output
  - in base alla scelta dell’utente, richiamare la funzione di codifica o decodifica sui file aperti*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int compressione(FILE *fin, FILE *fout);
int decompressione(FILE *fin, FILE *fout);

int main(void) {
  char choice, in[20], out[20];
  FILE *fin, *fout;


  printf("Compressione (C) o Decompressione (D): ");
  scanf("%c", &choice);

  switch(choice) {
    case 'C':
      printf("Nome input: ");
      scanf("%s", in);

      printf("Nome output: ");
      scanf("%s", out);

      if ((fin = fopen(in, "r+")) == NULL) {
          printf("Error opening file\n");
          return 1;
      }
      if ((fout = fopen(out, "r+")) == NULL) {
          printf("Error opening file\n");
          return 2;
      }
      compressione(fin, fout);
      fclose(fin);
      fclose(fout);
      break;
    case 'D':
      printf("Nome input: ");
      scanf("%s", in);

      printf("Nome output: ");
      scanf("%s", out);

      if ((fin = fopen(in, "r+")) == NULL) {
          printf("Error opening file\n");
          return 1;
      }
      if ((fout = fopen(out, "r+")) == NULL) {
          printf("Error opening file\n");
          return 2;
      }
      decompressione(fin, fout);
      fclose(fin);
      fclose(fout);
      break;
    default:
      printf("Errore!");
      break;
  }
  return 0;
}

int compressione (FILE *fin, FILE *fout) {
  char c0, c1, c2;
  int h = 0, k = 0, i = 0;

  while ((c1 = fgetc(fin)) != EOF) {
    //Codifica numerica
    if (c1 >= '0' && c1 <= '9') {
      c1 = c1 - '0';
      c0 = c1 + k;
      if (c0 > 9) {
        c0 = c0 % 10;
        c0 = c0 + '0';
        fprintf(fout, "%c", c0);
        k++;
      }
      else {
        c0 = c0 + '0';
        fprintf(fout, "%c", c0);
        k++;
      }
    }

    //Codifica lettere
    else {
      if (isdigit(c2) == 0) {
        if (c2 >= 'a' && c2 <= 'z') {
          h = c2 - 'a';
          printf("%c %c", c2, c1);
          if (i > 'z') {
            i = 'a' + (i - ('z' - 1));
            fprintf(fout, "%c", i);
          }
          else {
            i = c1 + h;
            fprintf(fout, "%c", i);
          }
        }
        if (c2 >= 'A' && c2 <= 'Z') {
          h = c2 - 'A';
          if (i > 'Z') {
            i = 'A' + (i - ('Z' - 1));
            fprintf(fout, "%c", i);
          }
          else {
            i = c1 + h;
            fprintf(fout, "%c", i);
          }
        }
      }
      else {
        fputc(c1, fout);
      }
      k = 0;
    }
    c2 = c1;
  }
  return 0;
}

int decompressione (FILE *fin, FILE *fout) {
  printf("ciao");
  return 0;
}
