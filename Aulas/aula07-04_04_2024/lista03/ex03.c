#include <stdio.h>
#include <math.h>

float calcularArea(float p, float h) {
  return (sqrt(p*h))/60;
}

void compararAreas(float area_inicio, float area_fim) {
  if (area_inicio == area_fim) {
    printf("\nManteve área inalterada");
  } else if (area_inicio > area_fim) {
    printf("\nDiminuiu a área corporal");
  } else {
    printf("\nAumentou a área corporal");
  }
}

int main() {
  float p_inicio, h_inicio, p_fim, h_fim, area_inicio, area_fim;

  printf("Insira o peso e a altura no início do ano(P H): ");
  scanf("%f%f", &p_inicio, &h_inicio);
  printf("Insira o peso e a altura no final do ano(P H): ");
  scanf("%f%f", &p_fim, &h_fim);

  area_inicio = calcularArea(p_inicio, h_inicio);
  area_fim = calcularArea(p_fim, h_fim);

  compararAreas(area_inicio, area_fim);
  
  return 0;
}