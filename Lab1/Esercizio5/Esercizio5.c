/*Scrivere un programma “calcolatrice” che esegua le quattro operazioni aritmetiche di base
(addizione, sottrazione, divisione e moltiplicazione) tra due valori op1 e op2.
Realizzare un programma C che:
a) Acquisisca da tastiera utilizzando getchar l’operazione da eseguire (‘+’, ‘-‘, ‘*’ e ‘/’)
b) Acquisisca da tastiera utilizzando scanf i due operandi (float) (es. 21.0 2.0).
c) Stampi a schermo il carattere dell’operazione seguita dal risultato (es. / 10.50).
Approfondimento: Cosa succede quando op2 è uguale a 0?*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

  //Defenisco le Variabili
  float a, b;
  float somma, differenza, moltiplicazione, quoziente;
  char ch;

  printf("Scegli l'operazione: ");
  ch = getchar();

  printf("Inserire il primo numero: ");
  scanf("%f", &a);

  printf("Inserire il secondo numero: ");
  scanf("%f", &b);

  switch(ch) {
    case '+':
      somma = a + b;
      printf("La somma tra %.2f e %.2f e': %.2f\n", a, b, somma);
      break;
    case '-':
      differenza = a - b;
      printf("La differenza tra %.2f e %.2f e': %.2f\n", a, b, differenza);
      break;
    case '*':
      moltiplicazione = a * b;
      printf("La moltiplicazione tra %.2f e %.2f e': %.2f\n", a, b, moltiplicazione);
      break;
    case '/':
      quoziente = a / b;
      printf("La divisione tra %f e %f e': %f\n", a, b, quoziente);
      break;
    default:
      printf("Errore\n");
      break;
  }

  return 0;
}
