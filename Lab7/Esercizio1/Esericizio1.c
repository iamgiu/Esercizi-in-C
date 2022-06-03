/*Un file di testo contiene una matrice di interi (0 o 1) con il seguente formato:
• la prima riga del file specifica le dimensioni reali della matrice (numero di righe nr e numero di colonne nc).
  Si assuma che entrambi i valori siano al più pari a 50
• ciascuna delle nr righe successive contiene gli nc valori corrispondenti a una riga della matrice, separati da uno o più spazi
• ogni cella può contenere solamente il valore 0 (associato al colore bianco) o il valore 1 (associato al colore nero)
• le celle nere sono organizzate in modo da formare regioni rettangolari
  (ogni regione nera è circondata da una cornice di celle bianche, oppure da bordo/i della matrice).
  A tal fine, si consideri che l'adiacenza delle celle è considerata solo lungo i quattro punti cardinali principali (Nord, Sud, Ovest, Est), non in diagonale.

Si scriva un programma C che:
  • legga la matrice dal file di ingresso. Si assuma che il file non contenga errori (i.e. tutti i rettangoli neri rispettano
    la formattazione descritta precedentemente)
  • individui le regioni nere più grandi, rispettivamente in termini di: (1) altezza, (2) larghezza e (3) area.
    Nel caso di parità di dimensione, si riporti una tra le regioni che soddisfa il rispettivo criterio.
  • per ognuna delle regioni identificate al punto precedente, produca in output le seguenti informazioni:
    le coordinate (riga,colonna) dell’estremo superiore sinistro, l’altezza, la larghezza e l’area.

Esempio:   + mappa corrispondente
5 6
1 1 0 0 0 0
0 0 1 1 0 0
0 0 1 1 0 1
0 0 0 0 0 1
1 0 1 0 0 1

Output del programma:
Max altezza: estremo=(2,5), altezza=3, larghezza=1, area=3
Max larghezza: estremo=(0,0), altezza=1, larghezza=2, area=2
Max area: estremo=(1,2), altezza=2, larghezza=2, area=4*/

#include <stdio.h>
#include <stdlib.h>

#define N 60
#define R 50
#define C 50
#define file "matrice.txt"

typedef struct {
	int x; //coordinata x
	int y; //coordinata y
	int b; //base
	int h; //altezza
	int a; //area
} log;

typedef enum {FALSE = 0, TRUE} bool;

void leggiFile(int matrice[][C], int *nc, int *nr);
void rettangoli(int matrice[][C], int nr, int nc, log *max_b, log *max_h, log *max_a);
void r_prec(log *r, int x, int y, int b, int h, int a);
void stampaRettangolo(log r);

int main () {
  log max_b = {0, 0, 0, 0, 0};
  log max_h = {0, 0, 0, 0, 0};
  log max_a = {0, 0, 0, 0, 0};
  int matrice[R][C], nc, nr, temp;
	bool boolRett = FALSE;

  leggiFile(matrice, &nc, &nr);

	rettangoli(matrice, nr, nc, &max_b, &max_h, &max_a);

	printf("Max Base: \t");
	stampaRettangolo(max_b);
	printf("Max Altezza: \t");
	stampaRettangolo(max_h);
	printf("Max Area: \t");
	stampaRettangolo(max_a);
}

void leggiFile(int matrice[][C], int *nc, int *nr){
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

void rettangoli(int matrice[][C], int nr, int nc, log *max_b, log *max_h, log *max_a) {
  int i, j, tempI, tempJ, b = 0, h = 0, a;
	bool countB;

	for(i = 0; i < nr; i++) {
		for(j = 0; j < nc; j++) {
			countB = TRUE;
			if(matrice[i][j] == 1) {
				tempI = i;
				tempJ = j;
				while(matrice[tempI][tempJ] == 1) {
					matrice[tempI][tempJ] = 0;
					if (countB) {
						b++;
					}
					tempJ++;
					if(tempJ >= nc || matrice[tempI][tempJ] == 0) { // se cambia riga
						tempI++;
						tempJ = j;
						h++;
						countB = FALSE; // smette di contare per la base
					}
					if(tempI >= nr) {
						break;
					}
				}
				a = b * h;
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
