#include <stdio.h>

int calculaValor(int horas, int minutos) {
  return (horas*60)+minutos;
}

int main() {
  int horas, minutos;

  printf("Digite as horas: ");
  scanf("%d", &horas);
  printf("Digite os minutos: ");
  scanf("%d", &minutos);

  printf("O horário atual em minutos é %d", calculaValor(horas, minutos));

  return 0;
}