#include <stdio.h>

int divisores(int a, int b) {
  int aux, mdc, divisor_encontrado = 0;

  if (a < b) {
    aux = a;
  } else {
    aux = b;
  }

  while (aux > 0) {
    if (a%aux == 0 && b%aux == 0) {
      printf("%d\n", aux);
      if (divisor_encontrado == 0) {
        mdc = aux;
      }
      divisor_encontrado++;
    }
    aux--;
  }
  return mdc;
}

int main(void) {
  int a, b;

  scanf("%d%d", &a, &b);
  printf("%d", divisores(a, b));
  
  return 0;
}