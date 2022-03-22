#include <stdio.h>

int main(void) {

  int f0 = 1, f1 = 2, n, i, fn;

  printf("Inserisci un numero: ");
  scanf("%d", &n);

  printf("%d %d ", f0, f1);
  for (i = 2; i < n; i++) {
      fn = f0 * f1;
      printf("%d ", fn);
      f0 = f1;
      f1 = fn;
    }
    return 0;
}
