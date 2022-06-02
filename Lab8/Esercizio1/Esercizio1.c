/*Re implementare l’esercizio 1 del Lab7 apportandovi le seguenti modifiche:
• Supponendo di avere dichiarato nel main una matrice di interi M di dimensioni NR x NC NC, con NR e NC pari a 50, si acquisisca la matrice da un file di
  testo mediante una funzione (leggiMatriceleggiMatrice) che restituisce il numero di righe e di colonne della matrice acquisita,
  come parametri “by referen-ce” (o meglio, “by pointer”).

  La funzione deve avere il seguente prototipo:

    void leggiMatrice(int mat[][NC], int maxR, int *nrp, int *ncp);

  e deve essere chiamata nel main usando la seguente istruzione:

    leggiMatrice(M, NR, &nr, &nc);

    Come risultato della chiamata alla funzione, le variabili intere nr e nc dovrebbero contenere il numero effettivo di righe e colonne della matrice acquisita, MM.

• Il riconoscimento delle regioni deve essere gestito da una funzione riconosciRegione che, da-ta una casella della matrice identificata dagli indici di riga e colonna r e cc,
  deve determinare se questa casella rappresenti l’estremo superiore sinistro di una regione rettangolare.
  La funzione deve restituire un numero intero booleano come valore di ritorno: rispettivamente, 1 se la regione è stata trovata, 0 altrimenti.
  Anche le dimensioni (larghezza e altezza) della regione rettangolare devono essere restituite “by reference”, come è stato fatto per nr e nc al punto precedente.
  La funzione deve essere chiamata come segue:

  if (riconosciRegione(M,
    nr,nc, r,c,&b,&h)) {
    // stampa messaggio per rettangolo con
    // estremo in (r,c), base b e altezza h
  }*/

#include <stdio.h>
#include <stdlib.h>

#define N 50

#define file "mappa.txt"

typedef struct {
	int x; //coordinata x
	int y; //coordinata y
	int b; //base
	int h; //altezza
	int a; //area
} log;

typedef enum {FALSE = 0, TRUE} bool;

void leggiMatrice(int matrice[][N], int *nc, int *nr);
bool regione(int matrice[][N], int nr, int nc, int r, int c, int *b, int *h);
void rettangoli(int matrice[][N], int nr, int nc, log *max_b, log *max_h, log *max_a);
void r_prec(log *r, int x, int y, int b, int h, int a);
void stampaRettangolo(log r);

int main () {
  log max_b = {0, 0, 0, 0, 0};
  log max_h = {0, 0, 0, 0, 0};
  log max_a = {0, 0, 0, 0, 0};
  int matrice[N][N], nc, nr, temp;
	bool boolRett = FALSE;

  leggiMatrice(matrice, &nc, &nr);

  rettangoli(matrice, nr, nc, &max_b, &max_h, &max_a);

  printf("Max Base: \t");
  stampaRettangolo(max_b);
  printf("Max Altezza: \t");
  stampaRettangolo(max_h);
  printf("Max Area: \t");
  stampaRettangolo(max_a);
}

void leggiMatrice(int matrice[][N], int *nc, int *nr){
  FILE *fp;
  int c, r, i, j;

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
  fclose(fp);
}

bool regione(int matrice[][N], int nr, int nc, int r, int c, int *b, int *h) {
// se non è un estremo sinistro, termina la funzione
if(r > 0 && matrice[r-1][c] == 1) {
    return FALSE;
 }
 if(c > 0 && matrice[r][c-1] == 1) {
    return FALSE;
 }

 int tempR, tempC;
 bool countB = TRUE;
 *b = 0;
 *h = 0;
 if(matrice[r][c] == 1) {
    tempR = r;
    tempC = c;
    while(matrice[tempR][tempC] == 1) {
       if (countB) {
          *b = *b + 1;
       }
       tempC++;
       if(tempC >= nc || matrice[tempR][tempC] == 0) {
          tempR++;
          tempC = c;
          *h = *h + 1;
          countB = FALSE;
       }
       if(tempR >= nr) {
          break;
       }
    }
    return TRUE;
 }
}

void rettangoli(int matrice[][N], int nr, int nc, log *max_b, log *max_h, log *max_a) {
	int i, j, tempI, tempJ, b = 0, h = 0, a;
  log rett = {0,0,0,0,0};
	bool countB;

  printf("Rettangoli trovati: \n");

	for(i = 0; i < nr; i++) {
		for(j = 0; j < nc; j++) {
			countB = TRUE;
        if(regione(matrice, nr, nc, i, j, &b, &h)) {
          a = b * h;
          r_prec(&rett, i, j, b, h, a);
          stampaRettangolo(rett);
          if((max_b->b) < b) {
 				  r_prec(max_b, i, j, b, h, a);
   			}
   			if((max_h->h) < h) {
   				r_prec(max_h, i, j, b, h, a);
   			}
   			if((max_a->a) < a) {
   				r_prec(max_a, i, j, b, h, a);
   			}
   			b = 0;
   			h = 0;
			}
		}
	}
   printf("\n");
}
void r_prec(log *r, int x, int y, int b, int h, int a) {
	r->x = x;
	r->y = y;
	r->b = b;
	r->h = h;
	r->a = a;
}

void stampaRettangolo(log r) {
	printf("estremo: (%d,%d) larghezza=%d, altezza=%d, area=%d\n",
			r.x,
			r.y,
			r.b,
			r.h,
			r.a
	);
}
