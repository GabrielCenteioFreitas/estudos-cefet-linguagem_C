#include <stdio.h>

float processarPostos() {
  float valor, maior_valor, valor_total = 0;
  int codigo;

  for (int i = 1; i<=20; i++) {
    printf("\n>=--- Posto %02d ---=<\n", i);
    printf("Digite o código do posto: ");
    scanf("%d", &codigo);
    printf("Digite o valor total arrecadado no posto: ");
    scanf("%f", &valor);

    if (i == 1 || valor > maior_valor) {
      maior_valor = valor;
    }

    valor_total += valor;
  }

  printf(">=----------------=<\n\nO maior valor arrecadado foi de R$%.2f\n", maior_valor);

  return valor_total;
}

int main() {
  float valor_total;

  valor_total = processarPostos();
  printf("O valor total arrecadado foi de R$%.2f", valor_total);
  
  return 0;
}