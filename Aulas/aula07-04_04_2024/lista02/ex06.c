#include <stdio.h>
#include <math.h>

float calcularDistancia(xa, ya, xb, yb) {
 return sqrt(pow(xb - xa, 2) + pow(yb - ya, 2));
}

int main() {
  float x1, y1, x2, y2, x3, y3;

  printf("Insira as coordenadas do primeiro ponto(X Y): ");
  scanf("%f%f", &x1, &y1);
  printf("Insira as coordenadas do segundo ponto(X Y): ");
  scanf("%f%f", &x2, &y2);
  printf("Insira as coordenadas do terceiro ponto(X Y): ");
  scanf("%f%f", &x3, &y3);

  printf("\nO perímetro do triângulo é: %.2f", calcularDistancia(x1, y1, x2, y2) + calcularDistancia(x1, y1, x3, y3) + calcularDistancia(x2, y2, x3, y3));
  
  return 0;
}