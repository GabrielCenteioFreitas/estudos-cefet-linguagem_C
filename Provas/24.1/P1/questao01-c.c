#include <stdio.h>

void lerInfosVendas(int qntd_vendas) {
  int codigo, qntd_passagens, qntd_maiores_compradores;
  float valor_passagem, valor_venda, maior_venda;

  for (int i = 0; i < qntd_vendas; i++) {
    valor_venda = 0;
    printf("Código: ");
    scanf("%d", &codigo);
    printf("Quantidade de passagens: ");
    scanf("%d", &qntd_passagens);
    
    for (int j = 0; j < qntd_passagens; j++) {
      printf("Valor: ");
      scanf("%f", &valor_passagem);
      valor_venda += valor_passagem;
    }

    if (i == 0 || valor_venda > maior_venda) {
      maior_venda = valor_venda;
      qntd_maiores_compradores = 1;
    } else if (valor_venda == maior_venda) {
      qntd_maiores_compradores++;
    }

    printf("Valor da venda: R$%.2f\n", valor_venda);
  }

  printf("Maior valor pago: R$%.2f\n", maior_venda);
  printf("Quantidade de compras com esse valor: %d", qntd_maiores_compradores);
}

int main() {
  int qntd_vendas;

  scanf("%d", &qntd_vendas);
  lerInfosVendas(qntd_vendas);
}