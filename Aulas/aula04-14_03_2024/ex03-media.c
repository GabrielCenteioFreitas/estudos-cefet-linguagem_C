// Autor: Gabriel Centeio Freitas
// Data: 14/03/2024
// Descrição: Programa que calcula a média de uma determinada quantidade de números, sendo a quantidade escolhida pelo usuário

#include <stdio.h>

int main(void) {
  int qntd, num, soma=0;
  float media;

  printf("Digite a quantidade de números que você deseja calcular a média: ");
  scanf("%d", &qntd);
  for(int i=0; i<qntd;i++) {
    printf("Digite o %d° número: ",i+1);
    scanf("%d", &num);
    while (num<=0) {
      printf("Digite o %d° número: ",i+1);
      scanf("%d", &num);      
    }
    soma+=num;
  }

  media = (float)soma/qntd;
  printf("A média dos %d números é %.2f", qntd, media);
  
  return 0;
}