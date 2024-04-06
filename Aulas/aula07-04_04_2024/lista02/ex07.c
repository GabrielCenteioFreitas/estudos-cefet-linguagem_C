#include <stdio.h>

float calcularVolumeCaixa(float a, float b, float c) {
  return a*b*c;
}

float calcularVolumeCilindro(float r, float h) {
  return 3.14*h*r*r;
}

int main() {
  float a, b, h, r;

  printf("Insira os lados da caixa(A B H): ");
  scanf("%f%f%f", &a, &b, &h);
  printf("Insira o valor do raio do cilindro: ");
  scanf("%f", &r);

  printf("\nVolume da caixa: %.2f", calcularVolumeCaixa(a, b, h)-calcularVolumeCilindro(r, h));

  
  return 0;
}