// Autor: Gabriel Centeio Freitas
// Data: 14/03/2024
// Descrição: Programa que calcula a distância entre 2 pontos a quantidade de vezes que o usuário desejar

#include <stdio.h>
#include <math.h>

float calcularDistancia(float x1, float y1, float x2, float y2) {
    float distancia = sqrt(pow(x2-x1,2)+pow(y2-y1,2));

    return distancia;
}

int main(void) {
  int qntd;
  float x1, y1, x2, y2;

  printf("Quantas distâncias deseja calcular? ");
  scanf("%d", &qntd);

  for (int i=0;i<qntd;i++) {
   printf("Insira as coordenadas(X1 Y1 X2 Y2): ");
   scanf("%f%f%f%f", &x1, &y1, &x2, &y2);
   printf("Distância: %.2f\n", calcularDistancia(x1,y1,x2,y2));
  }
  
  return 0;
}