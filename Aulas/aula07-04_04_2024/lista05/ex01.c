#include <stdio.h>

float calcularValor(int qntd_downloads, float preco) {
  float tamanho, valor;
  int i = 1;

  for (; qntd_downloads > 0; qntd_downloads--) {
    printf("Tamanho do download %d: ", i);
    scanf("%f", &tamanho);

    valor += (tamanho * preco);
    i++;
  }
  printf("\nO valor a ser pago é: R$ %.2f\n", valor);

  return valor;
}

int main() {
  float preco, valor, maior_valor, total;
  int qntd_downloads, i = 1;

  printf("Insira o preço por MByte: ");
  scanf("%f", &preco);

  do {
    printf("\n>=--- Usuário %02d ---=<\n", i);
    printf("Insira a quantidade de downloads: ");
    scanf("%d", &qntd_downloads);
    if (qntd_downloads != 0) {  
      valor = calcularValor(qntd_downloads, preco);
      if (i == 1) {
        maior_valor = valor;
      } else if (valor > maior_valor) {
        maior_valor = valor;
      }
  
      total += valor;
      i++;
    }

  } while(qntd_downloads != 0);

  printf(">=-----------------=<\n\nValor médio a ser pago: R$%.2f\nMaior valor a ser pago: R$%.2f\n", total/(i-1), maior_valor);
  
  return 0;
}