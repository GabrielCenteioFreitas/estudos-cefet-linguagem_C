// Autor: Gabriel Centeio Freitas
// Data: 21/03/2024
// Descrição: Programa que recebe um valor N e calcula a soma dos números de 1 a N utilizando a estrutura de repetição "for"

#include <stdio.h>

int main() {
  int num, soma=0;

  printf("Digite um número: ");
  scanf("%d", &num);

  while (num<=0) {
    printf("Insira um número positivo\nDigitr um número: ");
    scanf("%d", &num);
  }

  for (int i = num; i>0; i--) {
    soma += i;
  }


  printf("A soma de todos os números de 1 até %d é %d", num, soma);

  return 0;
}