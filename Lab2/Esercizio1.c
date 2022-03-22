/*Scrivere un programma C che, acquisiti 2 numeri interi positivi ne calcoli il massimo comune divisore utilizzando la formula di Eulero.
Formula di Eulero o metodo dei resti: si procede per divisioni successive del numero maggiore per quello minore,
sostituendo ad ogni passo il valore maggiore con il minore ed il minore col resto della divisione.
Il processo termina quando il resto è 0.
Esempio: A = 34 , B = 18
passo 1: 34 % 18 = 16
passo 2: 18 % 16 = 2
passo 3: 16 % 2 = 0 -> stop!
Risultato: MCD = 2*/

#include <stdio.h>

int main(void) {

  int a, b, resto, contatore;

  printf("Inserisci il primo numero: ");
  scanf("%d", &a);
  printf("Inserisci il secondo numero: ");
  scanf("%d", &b);

  contatore = 0;
  while (resto != 0) {
    resto = a % b;
    contatore++;
    printf("Passo %d: %d %% %d = %d\n", contatore, a, b, resto);
    a = b;
    b = resto;
  }
    printf("MCD = %d\n", a);

  return 0;
}
