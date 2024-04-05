#include <stdio.h>

int calcularSoma(int a, int b) {
  printf("A soma é %d", a+b);
  return a + b;
}

int main() {
  int a, b;

  printf("Digite o primeiro número: ");
  scanf("%d", &a);
  printf("Digite o segundo número: ");
  scanf("%d", &b);
  
  calcularSoma(a, b);
  return 0;
}