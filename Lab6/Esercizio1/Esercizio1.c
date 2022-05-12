/*Un'azienda di trasporto urbano traccia i propri automezzi in un file di log (file testuale di nome log.txt).

Il file è organizzato come segue:
• sulla prima riga, un intero positivo indica il numero di successive righe del file stesso (al più 1000)
• le righe successive riportano le informazioni sulle tratte, una per riga, con formato:
<codice_tratta><partenza><destinazione><data><ora_partenza><ora_arrivo><ritardo>
<codice_tratta>, <partenza> e <destinazione> sono stringhe lunghe al massimo 30 caratteri che rap- presentano rispettivamente il codice, la partenza e la destinazione della tratta;
<data> è la data della tratta nel formato yyyy/mm/dd;
<ora_partenza>, <ora_arrivo> indicano l’ora di partenza e arrivo della tratta nel formato hh:mm:ss; <ritardo> è un numero intero >=0 che rappresenta i minuti di ritardo accumulati dalla corsa (Si assuma che il ritardo non influisca sulla data della tratta).

Esempio del file log.txt:
6
GTT001 Braccini Porta_Nuova 2018/10/10 18:50:00 19:07:25 1
GTT001 Braccini Porta_Nuova 2018/12/10 19:50:00 20:06:00 1
GTT002 Politecnico XVIII_Dicembre 2018/10/10 10:01:23 10:12:08 4
GTT003 Einaudi Cso_Trapani 2018/09/10 14:11:23 14:38:23 2
GTT004 Marmolada Sebastopoli 2018/11/10 00:01:02 00:12:00 3
GTT002 Politecnico Piazza_Statuto 2018/11/10 23:11:59 23:20:07 0

Dopo aver letto il file e acquisito il contenuto in una opportuna struttura dati, si scriva un programma in C che fornisca un menu all’utente per scegliere tra una delle seguenti operazioni:

1. elencare tutte le corse partite in un certo intervallo di date
2. elencare tutti le corse partite da una certa fermata (partenza)
3. elencare tutti le corse aventi una specifica destinazione (capolinea)
4. elencare tutte le corse che hanno raggiunto la destinazione in ritardo, in un certo intervallo di date
5. elencare il ritardo complessivo accumulato dalle corse identificate da un certo codice di tratta
6. terminare il programma

Per selezionare una voce del menu l’utente deve inserire uno specifico comando da tastiera (si veda il paragrafo 4.4.1, Dal problema al programma). Ogni comando consiste di una parola tra "date", "partenza", "capolinea", "ritardo", "ritardo_tot" e "fine", eventualmente seguita sulla stessa riga da altre informazioni. Per esempio, "date" deve essere seguito da due date nel formato yyyy/mm/dd, "partenza" deve essere seguito dal nome della fermata di partenza, etc.
Per gestire la selezione da menu si utilizzi la strategia di codifica dei comandi simile a quella riportata nella slide 23 in C3 Capitolo 4 – Problem solving con uso di vettori – parte 2. Si definisca un nuovo ti- po enum comando_e, contenente i simboli r_date, r_partenza, r_capolinea, r_ritardo, r_ritardo_tot, r_fine. Si codifichi ogni comando nel corrispondente simbolo comando_e che consente facilmente di gestire menu basati su switch-case.

Si consiglia di:
• realizzare una funzione leggiComando che acquisisca la prima parola del comando da tastiera e ritorni il corrispondente valore di tipo comando_e
• realizzare una funzione menuParola che riceva come parametri la struttura dati dove sono memorizzate le tratte ed il numero di tratte memorizzate e gestisca mediante menu l’acquisizione dei comandi (la prima parola e le informazioni aggiuntive necessarie) così come la chiamata di un’opportuna funzione di selezione e stampa dei dati selezionati. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define file "log.txt"
#define N 30

typedef enum {
	r_date = 1,
	r_partenza,
	r_capolinea,
	r_ritardo,
	r_ritardo_tot,
	r_fine
} comando_e;

//false ↔ 0, true ↔ 1 false < true
typedef enum {false, true}
Boolean;

typedef struct {
	char codice[6+1];
	char partenza[N+1];
	char destinazione[N+1];
	char data[10+1];
	char oraP[8+1];
	char oraA[8+1];
	int ri;
} log;

void leggiFile(log corsa[N], int *tot);
comando_e leggiComando();
void menuParola(log corsa[N], int tot, comando_e scelta);
void stampa(log corsa);


int main() {
  int tot;
  log corsa[N];

  leggiFile(corsa, &tot);

  // inserimento scelta ed esecuzione comando
	comando_e scelta;
	do {
		scelta = leggiComando();
		menuParola(corsa, tot, scelta);
	} while(scelta != 6);

	return 0;
}

void leggiFile(log corsa[N], int *tot) {
  FILE *fp;
  int totale;

  if ((fp = fopen(file, "r")) == NULL) {
    printf("Error opening file!");
    return;
  }

  if(!feof(fp)) {
    fscanf(fp, "%d", &totale);
  }
  else {
    printf("Error!");
    return;
}

  *tot = totale;

  for(int i = 0; i < totale; i++) {
     fscanf(fp, " %6s %30s %30s %10s %10s %8s %d", corsa[i].codice,corsa[i].partenza, corsa[i].destinazione, corsa[i].data, corsa[i].oraP, corsa[i].oraA, &corsa[i].ri);
       }

  fclose(fp);
}

comando_e leggiComando() {
	int com = 0;

	printf("Le cose che puoi fare:\n1. elencare tutte le corse partite in un certo intervallo di date\n2. elencare tutti le corse partite da una certa fermata (partenza)\n3. elencare tutti le corse aventi una specifica destinazione (capolinea)\n4. elencare tutte le corse che hanno raggiunto la destinazione in ritardo, in un certo intervallo di date\n5. elencare il ritardo complessivo accumulato dalle corse identificate da un certo codice di tratta\n6. terminare il programma\nInserire numero: ");

	do {
		scanf("%d", &com);
		if(com >= 1 && com <= 6) {
			return com;
		}
    else {
			printf("Scelta sbagliata\n");
		}
	} while(true);
}

void menuParola(log corsa[N], int tot, comando_e scelta) {
  int cont = 1;

	switch(scelta) {

		case r_date: {
			char p[10+1], a[10+1];
			printf("Inserisci la data di partenza e la data di arrivo (formato yyyy/mm/dd): ");
			scanf("%s %s", p, a);

			for(int i = 0; i < tot; i++) {
				if(strcmp(corsa[i].data, p) >= 0 && strcmp(corsa[i].data, a) <= 0) {
          printf("Corsa %d:\n", cont);
          stampa(corsa[i]);
          cont++;
				}
			}

			printf("\n");
			break;
		}

		case r_partenza: {
			char p[N+1];

			printf("Inserisci la stazione di partenza: ");
			scanf("%s", p);

			for(int i = 0; i < tot; i++) {
				if(strcmp(corsa[i].partenza, p) == 0) {
          printf("Corsa %d:\n", cont);
          stampa(corsa[i]);
          cont++;
				}
			}

			printf("\n");
			break;
		}

		case r_capolinea: {
			char arrivo[N+1];
			printf("Inserisci la stazione di arrivo: ");
			scanf("%s", arrivo);
			for(int i = 0; i < tot; i++) {
				if(strcmp(corsa[i].destinazione, arrivo) == 0) {
          printf("Corsa %d:\n", cont);
          stampa(corsa[i]);
          cont++;
			  }
      }
			printf("\n");
			break;
		  }

		case r_ritardo: {
			char p[10+1], a[10+1];

			printf("Inserisci la data di partenza e la data di arrivo (formato yyyy/mm/dd): ");
			scanf("%s %s", p, a);

			for(int i = 0; i < tot; i++) {
				if(strcmp(corsa[i].data, p) >= 0 && strcmp(corsa[i].data, a) <= 0 && corsa[i].ri > 0) {
          printf("Corsa %d:\n", cont);
          stampa(corsa[i]);
			   }
      }
			printf("\n");
			break;
		}

		case r_ritardo_tot: {
			int r = 0;
			char codice[6+1];

			printf("Inserire il codice della tratta (GTTXXX): ");
			scanf("%s", codice);

			for(int i = 0; i < tot; i++) {
				if(strcmp(corsa[i].codice, codice) == 0) {
					r += corsa[i].ri;
				}
			}

			printf("Totale ritardo della tratta: %d\n", r);
			printf("\n");
			break;
		}

    case r_fine: {
      printf("Termino programma");
      break;
    }

    default:
      printf("Error");
      break;
  }
}

void stampa(log corsa) {
  printf("Codice: %6s\nPartenza: %30s\nDestinazione: %30s\nData: %30s\nOra Partenza: %30s\nOra Arrivo: %30s\nRitardo: %d\n\n", corsa.codice,corsa.partenza, corsa.destinazione, corsa.data, corsa.oraP, corsa.oraA, corsa.ri);
  return;
}
