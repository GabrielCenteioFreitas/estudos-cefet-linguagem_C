// Autor: Gabriel Centeio Freitas
// Data: 14/03/2024
// Descrição: Programa que calcula a média de uma determinada quantidade de números, sendo a quantidade escolhida pelo usuário

#include <stdio.h>

int main(void) {
  int qntd;
  float num, soma=0, media;

  printf("Digite a quantidade de números que você deseja calcular a média: ");
  scanf("%d", &qntd);
  if (qntd<=0) {
    printf("O número deve ser positivo.");
    return 0;
  }
  for(int i=0; i<qntd;i++) {
    printf("Digite o %d° número: ",i+1);
    scanf("%f", &num);
    soma+=num;
  }

  media = soma/qntd;
  printf("A média dos %d números é %.2f", qntd, media);
  
  return 0;
}