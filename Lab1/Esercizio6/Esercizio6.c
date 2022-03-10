/*Partendo dal codice dell’esercizio precedente, scrivere un programma C che legga da file una serie di operazione da eseguire
e scriva su un altro file l’operazione eseguita ed il risulta-to dell’operazione con due cifre decimali.
Esempio: di seguito un possibile contenuto del file di input Operations.txt:
+ 15.225 30.51
- 42.1 10.01
* 0.62 2.4
/ 5.0 2.5
Ed il file di output Results.txt:
+ 45.74
- 32.09
* 1.49
/ 2.00*/
#include <stdio.h>

int main(void) {
  FILE *fp_results, *fp_operations;
  float a, b, risultato;
  char ch;

  if ((fp_operations = fopen("Operations.txt", "r")) == NULL) {
      printf("Error opening file\n");
      return 1;
  }

  if ((fp_results = fopen("Results.txt", "r+")) == NULL) {
      printf("Error opening file\n");
      return 2;
  }

  /*printf("Scegli l'operazione: ");
  ch = getchar();

  printf("Inserire il primo numero: ");
  scanf("%f", &a);

  printf("Inserire il secondo numero: ");
  scanf("%f", &b);

  fprintf(fp_operations, "%c %.2f %.2f\n", ch, a, b);*/


  while (fscanf(fp_operations, "%c %f %f\n", &ch, &a, &b) != EOF) {
    switch(ch) {
      case '+':
        risultato = a + b;
        printf("La somma tra %.2f e %.2f e': %.2f\n", a, b, risultato);
        fprintf(fp_results, "%c %.2f\n", ch, risultato);
        break;
      case '-':
        risultato = a - b;
        printf("La differenza tra %.2f e %.2f e': %.2f\n", a, b, risultato);
        fprintf(fp_results, "%c %.2f\n", ch, risultato);
        break;
      case '*':
        risultato = a * b;
        printf("La moltiplicazione tra %.2f e %.2f e': %.2f\n", a, b, risultato);
        fprintf(fp_results, "%c %.2f\n", ch, risultato);
        break;
      case '/':
        risultato = a / b;
        printf("La divisione tra %f e %f e': %f\n", a, b, risultato);
        fprintf(fp_results, "%c %.2f\n", ch, risultato);
        break;
      default:
        printf("Errore\n");
        break;
    }
  }

  fclose(fp_operations);
  fclose(fp_results);

  return 0;

}
