/* Un file (sorgente.txt) contiene un testo composto da un numero indefinito di righe, di lunghezza massima 200 caratteri ognuna. Un secondo file (dizionario.txt) è organizzato come segue:

  • sulla prima riga è presente un numero intero e positivo S (≤30), che indica il numero di possibili ricodifiche (sostituzioni) presenti nel dizionario
  • le successive S linee del file riportano, una per linea, le coppie <ricodifica><originale> che rappresentano le sostituzioni possibili.
    <originale> rappresenta la sequenza di caratteri da ricercare nel file sorgente mentre <ricodifica> la sua sostituzione nella forma $<intero>$

Lo scopo del programma è di ricodificare il primo file di testo (sorgente.txt) andando a sostituire le sequenze di caratteri sulla base dei contenuti
del secondo file (dizionario.txt). In caso di più sostituzioni possibili per una certa sottostringa, il programma scelga la prima sostituzione trovata.
Il risultato della ricodifica sia salvato su un terzo file (ricodificato.txt).

Esempio:

Il contenuto del file sorgente.txt è:

apelle figlio di apollo fece una palla di pelle di pollo tutti i pesci vennero a galla per vedere la palla di pelle di pollo fatta da apelle figlio di apollo

Il contenuto del file dizionario.txt è:
  9
  $11$ pelle
  $2$ pollo
  $333$ palla
  $41$ alla
  $5078$ tta
  $6$ tti
  $7$ ll
  $81$ er
  $900$ ere

Il file di uscita ricodificato.txt conterrà:

a$11$ figlio di a$2$
fece una $333$ di $11$ di $2$
tu$6$ i pesci venn$81$o a g$41$
p$81$ ved$81$e la $333$ di $11$ di $2$
fa$5078$ da a$11$ figlio di a$2$ */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define file_sor "sorgente.txt"
#define file_diz "dizionario.txt"
#define file_ric "ricodifica.txt"

#define N 200

//Creo una struct dove contiene codice + parola originale -> contenuto di dizionario.txt
typedef struct {
   char codice[10];
   char parola[N + 1];
} dizionario;

//definisco le mie funzioni
void letturaDiz(dizionario d[N], int *dim);
void stampaDiz(dizionario d[N], int dim);
void sorgente(dizionario d[N], int dim);
void ricodifica(char stringa[], char sottoStr[], char nuovaStr[]);

int main() {
  int dim;
  dizionario d[N];

  letturaDiz(d, &dim);

  printf("Il mio dizionario contiene:\n");
  stampaDiz(d, dim);

  sorgente(d, dim);

  printf("\nRicodifica eseguita");
  }

//leggo il mio file dizionario e inserisco codice e parola originaria nel mio array di struct
void letturaDiz(dizionario d[N], int *dim) {
  FILE *fd;
  int dimensione;


  if ((fd = fopen(file_diz, "r")) == NULL) {
    printf("Error opening file!");
  }

  if(!feof(fd)) {
    fscanf(fd, "%d", &dimensione);
  }
  else {
    printf("Error!");
}

  *dim = dimensione;

  for(int i = 0; i < dimensione; i++) {
    fscanf(fd, "%s %s", d[i].codice, d[i].parola);
  }
  fclose(fd);
}

//stampa il mio dizionario
void stampaDiz(dizionario d[N], int dim) {
  for(int i = 0; i < dim; i++) {
    printf("%s %s\n", d[i].codice, d[i].parola);
  }
}

//leggo il file sorgente e printo sul file ricodifica il testo ricodificato dalla funzione
void sorgente(dizionario d[N], int dim) {
  FILE *fs, *fr;
  char temp[N + 1], c; //temp = la mia stringa temporanea

  if ((fs = fopen(file_sor, "r")) == NULL) {
    printf("Error opening file!");
  }

  if ((fr = fopen(file_ric, "r+")) == NULL) {
    printf("Error opening file!");
  }

  fscanf(fs, "%s", temp);
  c = fgetc(fs);

  while(!feof(fs)) {
  for(int i = 0; i < dim; i++) {
    //strstr = Questa funzione restituisce la posizione della prima occorrenza di ago nella stringa pagliaio, se non trovato restituisce null.
    //pagliaio - stringhe C per essere recuperati.
    //ago - nella stringa pagliaio per la ricerca di stringhe di piccole dimensioni.
     if(strstr(temp, d[i].parola) != NULL) {
        ricodifica(temp, d[i].parola, d[i].codice);
        break;
     }
  }
  fprintf(fr, "%s%c", temp, c);
  fscanf(fs, "%s", temp);
  c = fgetc(fs);
  }

  fclose(fs);
  fclose(fr);
}

//funzione che mi ricordifica le parole interessate
void ricodifica(char stringa[], char sottoStr[], char nuovaStr[]) {
 int strLen, sottoLen, nuovaLen, flag, in, fin, i, j, k; //Definisco già i, j e k per utilizzarli all'interno della funzione
//init = serve per cercare un determinato indice -> string[in] -> string[fin]

 strLen = strlen(stringa); //La funzione strlen() calcola la lunghezza della stringa s
 sottoLen = strlen(sottoStr);
 nuovaLen = strlen(nuovaStr);

 for(i = 0; i < strLen; i++) {
    flag = 0; //indicatore che segnala una variazione delle condizioni iniziali
    in = i;

    //cerca se sottostringa è in stringa
    //e trova indice inizio (j) e indice fine (i)
    for(j = 0; stringa[i] == sottoStr[j]; j++, i++) {
       if(j == sottoLen-1) {
          flag = 1;
       }
       fin = i;
    }

    if(flag == 0) {
       i -= j;
    }

    else {
     // elimina i caratteri da sostituire
     for(j = in; j < fin; j++) {
        for(k = in; k < strLen; k++) {
           stringa[k] = stringa[k+1];
        }
        strLen--;
        i--;
     }
     // inserisce la sottostringa
     for(j = in; j < in + nuovaLen; j++) {
        for(k = strLen; k >= j; k--) {
           stringa[k+1] = stringa[k];
        }
        stringa[j] = nuovaStr[j-in];
        strLen++;
        i++;
     }
    }
  }
}
