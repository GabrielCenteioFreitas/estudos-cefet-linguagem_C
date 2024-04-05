#include <stdio.h>

void calcularSemanas(int dias) {
  printf("%d semanas e %d dias", dias/7, dias%7);
}

int main() {
  int dias;

  printf("Insira o número de dias decorridos do evento: ");
  scanf("%d", &dias);

  calcularSemanas(dias);
  
  return 0;
}