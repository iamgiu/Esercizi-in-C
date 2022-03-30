/*E’ dato un file testo, contenente solo caratteri alfabetici, numerici, segni di punteggiatura (. , ; : ! ? '),
spazi e a-capo. Si vuole generare un secondo file contenente il testo, letto dal primo file e trasformato nel modo seguente:

- Sostituire le cifre numeriche con il carattere ‘*’.
- Inserire uno spazio dopo ogni segno di punteggiatura, a meno che questo non sia già seguito da uno spazio o un a-capo.
- Il primo carattere alfabetico successivo a un punto, punto esclamativo o interrogativo deve essere maiuscolo, se non lo è trasformarlo in maiuscolo (anche se tra la punteggiatura e il carattere alfabetico ci sono uno o più spazi o a capo).
- Le righe del testo devono essere al massimo di 25 caratteri (a-capo escluso). Se sono più lunghe vanno troncate (anche a metà di una parola) aggiungendo un a-capo esattamente dopo il venticinquesimo carattere.
- Al termine di ogni riga vanno aggiunti, prima dell’a-capo, eventuali spazi per raggiungere i 25 caratteri.
- Ogni riga deve terminare con il numero di caratteri del file originale trascritti nella riga, nel formato: “ | c:%d \n”.
I nomi dei file sono costanti (il primo file è input.txt, il secondo testo.txt) e definiti con #define.

Esempio:

Contenuto di input.txt                                                          Contenuto di testo.txt:
Caratterizzata da un passato turbolento, in                                     Caratterizzata da un pass| c:25
epoca medievale Rouen fu devastata piu' volte                                   ato turbolento, in | c:19
da incendi ed epidemie e durante la Guerra                                      epoca medievale Rouen fu | c:25
dei Cent'Anni fu occupata dagli inglesi.                                        devastata piu' volte | c:21
nel 1431 nella sua piazza centrale la giovane                                   da incendi ed epidemie e | c:25
Giovanna d'Arco (Jeanne d'Arc) fu processata                                    durante la Guerra | c:18
per eresia e arsa sul rogo!durante la seconda                                   dei Cent' Anni fu occupat| c:24
guerra mondiale gli Alleati bombardarono                                        va dagli inglesi. | c:17
ampie zone della citta', soprattutto il                                         Nel **** nella sua piazza| c:25
quartiere che si estende a sud della cattedrale.                                centrale la giovane | c:21
                                                                                Giovanna d' Arco ( Jeanne| c:23
                                                                                d' Arc) fu processata | c:22
                                                                                per eresia e arsa sul rog| c:25
                                                                                o! Durante la seconda | c:21
                                                                                guerra mondiale gli Allea| c:25
                                                                                ti bombardarono | c:16
                                                                                ampie zone della citta' ,| c:24
                                                                                soprattutto il quartiere| c:25
                                                                                che si estende a sud del| c:25
                                                                                la cattedrale. | c:15*/
#include <stdio.h>
#define FILE_IN "input.txt"
#define FILE_OUT "testo.txt"

int main () {
  FILE *fin, *fout;
  char curr_char, next_char, next_doppio;
  int k = 1, n;

  if ((fin = fopen(FILE_IN, "r+")) == NULL) {
      printf("Error opening file\n");
      return 1;
  }
  if ((fout = fopen(FILE_OUT, "r+")) == NULL) {
      printf("Error opening file\n");
      return 2;
  }

  while (!feof(fin)) {
    curr_char = fgetc(fin);
    //Al termine di ogni riga vanno aggiunti, prima dell’a-capo, eventuali spazi per raggiungere i 25 caratteri
    //Ogni riga deve terminare con il numero di caratteri del file originale trascritti nella riga, nel formato: “ | c:%d \n”.
    if (next_char == '\n' || curr_char == '\n') {
      for (int i = 0; i < (25 - k); i++) {
        fputc(' ', fout);
      }
      fprintf(fout, "| c:%d", k-1);
      k = 1;
    }
    if (k >= 25) {
      fprintf(fout, "| c:%d\n", k);
      k = 1;
    }
    //Sostituire le cifre numeriche con il carattere ‘*’
    if (curr_char >= 48 && curr_char <= 57) {
      fputc('*', fout);
      k++;
    }
    //-Inserire uno spazio dopo ogni segno di punteggiatura, a meno che questo non sia già seguito da uno spazio o un a-capo.
    //-Il primo carattere alfabetico successivo a un punto, punto esclamativo o interrogativo deve essere maiuscolo, se non lo è trasformarlo in maiuscolo
    //(anche se tra la punteggiatura e il carattere alfabetico ci sono uno o più spazi o a capo).
    //-Le righe del testo devono essere al massimo di 25 caratteri (a-capo escluso). Se sono più lunghe vanno troncate (anche a metà di una parola) aggiungendo un a-capo esattamente dopo il venticinquesimo carattere.
    else {
      if (curr_char == 44 || curr_char == 46 || curr_char == 58 || curr_char == 59 || curr_char == 33 || curr_char == 63 || curr_char == 39) {
        next_char = fgetc(fin);
        k++;
        if (next_char == ' ' || next_char == '\n') {
          if (curr_char == 46 || curr_char == 33 || curr_char == 63) {
            next_doppio = fgetc(fin);
            k++;
            if (next_doppio >= 97 && next_doppio <= 122) {
              next_doppio = next_doppio - 32;
              fprintf(fout, "%c%c%c",curr_char, next_char, next_doppio);
            }
            if (next_doppio >= 48 && next_doppio <= 57) {
                fprintf(fout, "%c%c*",curr_char, next_char);
            }
          }
          else {
            fprintf(fout, "%c%c",curr_char, next_char);
          }
        }
        else {
          if (curr_char == 46 || curr_char == 33 || curr_char == 63) {
            if (next_char >= 48 && next_char <= 57) {
                fprintf(fout, "%c *",curr_char);
            }
            if (next_char>= 97 && next_char <= 122) {
              next_char = next_char - 32;
              fprintf(fout, "%c %c",curr_char, next_char);
            }
          }
          else {
            if (next_char >= 48 && next_char <= 57) {
                fprintf(fout, "%c *",curr_char);
            }
            else {
              fprintf(fout, "%c %c",curr_char, next_char);
            }
          }
        }
      }
      else {
        fputc(curr_char, fout);
      }
    }
    k++;
    next_char = -1; //per resettare il valore in modo che k non tornasse 0 a ogni iterazione
  }
  fclose(fin);
  fclose(fout);
  return 0;
}
