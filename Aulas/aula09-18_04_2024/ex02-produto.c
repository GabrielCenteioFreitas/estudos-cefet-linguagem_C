#include <stdio.h>

void exibeEContabilizaTipo(char tipo_produto, int *qntd_nac, int *qntd_imp) {
    if (tipo_produto == 'N') {
      printf("Produto nacional!\n");
      (*qntd_nac)++;
    } else if (tipo_produto == 'I') {
      printf("Produto importado!\n");
      (*qntd_imp)++;
    }
}

int main() {
  int qntd_estoque, codigo, qntd_nac = 0, qntd_imp = 0;
  float preco;
  char tipo_produto;

  for (int i = 0; i < 40; i++) {
    printf("Digite o código do produto: ");
    scanf("%d", &codigo);
    printf("[N] Nacional\n[I] Importado\nInsira o tipo: ");
    scanf(" %c", &tipo_produto);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &qntd_estoque);
    printf("Insira o preço unitário: R$");
    scanf("%f", &preco);
    printf(">=-----=<\n");
    printf("Código do produto: %d\n", codigo);
    exibeEContabilizaTipo(tipo_produto, &qntd_nac, &qntd_imp);
    printf("Valor em estoque: R$ %.2f\n\n", qntd_estoque * preco);
  }
  printf("Qntd nacionais: %d\n", qntd_nac);
  printf("Qntd importado: %d\n", qntd_imp);
}