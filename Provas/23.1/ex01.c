#include <stdio.h>

typedef struct _Produto Produto;
struct _Produto {
  int codigo, codigo_fornecedor, tipo;
  float preco;
};

void preenchePercentualAumentoPorFornecedor(int codigo_fornecedor, float percentual_aumento, float aumentos[10]) {
  aumentos[codigo_fornecedor-1] = percentual_aumento;
}

int main() {
  float aumentos[10];

  for (int i = 0; i < 10; i++) {
    preenchePercentualAumentoPorFornecedor(i+1, 0.1*(i+1), aumentos);
  }

  for (int i = 0; i < 10; i++) {
    printf("Aumento %d: %.2f\n", i+1, aumentos[i]);
  }

  return 0;
}