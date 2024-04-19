#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

int leValidatipo() {
  int tipo;
  do {
    printf("\n[1] Fruta\n[2] Legume\n[3] Verdura\nInsira o tipo: ");
    scanf("%d", &tipo);
  } while (tipo < 1 || tipo > 3);

  return tipo;
}

void leDadosProdutos(int qntd_produtos, int *qntd_1, int *qntd_2, int *qntd_3) {
  int codigo, tipo;
  
  for (; qntd_produtos > 0; qntd_produtos--) {
    system(CLEAR);
    printf("Insira o código do produto: ");
    scanf("%d", &codigo);
    tipo = leValidatipo();

    if (tipo == 1) {
      (*qntd_1)++;
    } else if (tipo == 2) {
      (*qntd_2)++;
    } else if (tipo == 3) {
      (*qntd_3)++;
    }
  }  
}

int main() {
  int qntd_produtos, qntd_1 = 0, qntd_2 = 0, qntd_3 = 0;

  printf("Insira a qntd de produtos: ");
  scanf("%d", &qntd_produtos);
  leDadosProdutos(qntd_produtos, &qntd_1, &qntd_2, &qntd_3);
  system(CLEAR);
  printf("Quantidade do tipo 1: %d\n", qntd_1);
  printf("Quantidade do tipo 2: %d\n", qntd_2);
  printf("Quantidade do tipo 3: %d", qntd_3);
  
  return 0;
}