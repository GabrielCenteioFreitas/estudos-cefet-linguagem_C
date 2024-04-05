#include <stdio.h>

float calcularValorPerifericos(int qntd_perifericos) {
  float preco, valor_perifericos = 0;
  int i = 1;

  for (; qntd_perifericos > 0; qntd_perifericos--) {
    printf("Preço do periférico %d: ", i);
    scanf("%f", &preco);

    valor_perifericos += preco;
    i++;
  }

  return valor_perifericos;
}

int main() {
  float preco, valor, valor_perifericos, total;
  int modelo, qntd_perifericos, vendas_sem_perifericos = 0, i = 1;

  do {
    printf(">=--- Venda %02d ---=<\n", i);

    printf("Insira o modelo do produto: ");
    scanf("%d", &modelo);
    if (modelo != 0) { 
      printf("Insira o preço do produto: ");
      scanf("%f", &preco);
      printf("Insira a quantidade de periféricos: ");
      scanf("%d", &qntd_perifericos); 
      
      valor_perifericos = calcularValorPerifericos(qntd_perifericos);
      valor = preco + valor_perifericos;
      printf("\nO valor a ser pago é: R$ %.2f\n\n", valor);

      if (qntd_perifericos == 0) {
        vendas_sem_perifericos++;
      }

      total += valor;
      i++;
    }
    
  } while(modelo != 0);

  printf(">=-----------------=<\n\nVendas sem periféricos: %d\nMédia dos valores a serem pagos: R$%.2f\n", vendas_sem_perifericos, total/(i-1));

  return 0;
}