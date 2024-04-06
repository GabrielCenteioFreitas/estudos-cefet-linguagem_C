#include <stdio.h>

int calcula_soma(int num1, int num2, int num3) {
  printf("\nA soma dos números é: %d", num1 + num2 + num3);
  return num1 + num2 + num3;
}

void calcula_media(int soma) {
  printf("\nA média dos números é: %.2f", soma/3.0);
}

int main() {
  int num1, num2, num3, soma;

  printf("Insira o primeiro número: ");
  scanf("%d", &num1);
  printf("Insira o segundo número: ");
  scanf("%d", &num2);
  printf("Insira o terceiro número: ");
  scanf("%d", &num3);

  soma = calcula_soma(num1, num2, num3);
  calcula_media(soma);


  return 0;
}