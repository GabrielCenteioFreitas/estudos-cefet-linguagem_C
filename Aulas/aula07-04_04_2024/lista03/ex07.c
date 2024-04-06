#include <stdio.h>

void pagamento_dinheiro(float valor_despesa, float valor_pago) {
  if (valor_despesa - valor_pago == 0) {
    printf("\nNão há troco.");
  } else {
    printf("\nO troco é de R$%.2f", valor_despesa-valor_pago);
  }
}

int main() {
  float valor_despesa, valor_pago;
  char escolha;

  printf("Insira o valor da despesa: R$");
  scanf("%f", &valor_despesa);
  printf("\n[D] Cartão de débito\n[C] Cartão de crédito\n[N] Dinheiro\nInsira o método de pagamento: ");
  scanf(" %c", &escolha);

  if (escolha == 'N') {
    printf("\nInsira o valor pago: R$");
    scanf("%f", &valor_pago);
    pagamento_dinheiro(valor_despesa, valor_pago);
  } else {
    printf("\nNão há troco.");
  }


  
  return 0;
}