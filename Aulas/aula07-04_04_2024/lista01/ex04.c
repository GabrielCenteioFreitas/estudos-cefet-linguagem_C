#include <stdio.h>

float calculaValor(float valor, int qntd) {
  return valor*qntd;
}

int main() {
  float valor;
  int qntd;

  printf("Digite o valor do litro do combustível: ");
  scanf("%f", &valor);
  printf("Digite a quantidade de litros abastecida: ");
  scanf("%d", &qntd);

  printf("O valor a ser pago é R$ %.2f", calculaValor(valor, qntd));

  return 0;
}