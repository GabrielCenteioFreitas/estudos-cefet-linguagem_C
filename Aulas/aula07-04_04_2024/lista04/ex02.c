#include <stdio.h>

int lerDados(int qntd_auto) {
  int qntd_estoque_1000 = 0, modelo, qntd_estoque;

  for (int i = 1; i<=qntd_auto; i++) {
    printf("\n>=--- Automóvel %02d ---=<\n", i);
    printf("Insira o modelo: ");
    scanf("%d", &modelo);
    printf("Insira a quantidade em estoque: ");
    scanf("%d", &qntd_estoque);

    if (qntd_estoque >= 1000) {
      qntd_estoque_1000++;
    }
  }

  return qntd_estoque_1000;
}

int main() {
  int qntd_auto, qntd_estoque_1000;

  printf("Insira a quantidade de automóveis: ");
  scanf("%d", &qntd_auto);

  qntd_estoque_1000 = lerDados(qntd_auto);
  
  printf("=--------------------=<\n\nA quantidade de automóveis com 1000 ou mais unidades em estoque é: %d", qntd_estoque_1000);

  
  return 0;
}