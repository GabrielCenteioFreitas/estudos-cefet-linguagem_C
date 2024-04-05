#include <stdio.h>

float aplicarAumento(int preco_unitario) {
  return preco_unitario*1.2;
}

int main() {
  int preco_unitario;

  printf("Digite o preço unitário do produto: ");
  scanf("%d", &preco_unitario);

  printf("O preço com aumento é: %.2f", aplicarAumento(preco_unitario));
  
  return 0;
}