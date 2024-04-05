#include <stdio.h>

float calcularMedia(float a, float b) {
    return (a + b) / 2;
}

int main() {
  float a, b;

  printf("Digite o primeiro número: ");
  scanf("%f", &a);
  printf("Digite o segundo número: ");
  scanf("%f", &b);

  printf("A média é %.2f", calcularMedia(a, b));
  return 0;
}