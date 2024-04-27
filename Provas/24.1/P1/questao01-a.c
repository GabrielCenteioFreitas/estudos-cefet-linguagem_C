#include <stdio.h>
#include <math.h>

float calcularX(float a, float b, float c) {
  float numerador = sqrt((a-b)*3);
  float denominador = c + pow(a, 5);
  return (numerador / denominador);
}

int main() {
  printf("%f", calcularX(1, 1, 1));
}
