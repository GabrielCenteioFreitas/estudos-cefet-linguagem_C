#include <stdio.h>

typedef struct {
  int codigo;
  char nome[21];
  int qtd;
} Produto;

typedef struct {
  int codigo;
  char tipo;
  int qtd, qtd_pend;
} Movimentacao;

#define QTD_PRODUTOS 3

void leDadosProdutos(Produto estoque[QTD_PRODUTOS]) {
  printf("=--- LENDO PRODUTOS ---=\n");
  for (int i = 0; i < QTD_PRODUTOS; i++) {
    printf("Nome: ");
    scanf("%s", estoque[i].nome);
    printf("Código: ");
    scanf("%d", &estoque[i].codigo);
    printf("Qtd: ");
    scanf("%d", &estoque[i].qtd);
    printf("\n");
  }

  printf("\n");
}

int leMovimentacoes(Movimentacao movs[], Produto estoque[QTD_PRODUTOS]) {
  int i = 0, codigo = -1;

  printf("=--- LENDO MOVIMENTAÇÕES ---=\n");
  while (codigo) {
    printf("Código: ");
    scanf("%d", &codigo);

    if (!codigo)
      break;

    movs[i].codigo = codigo;
    printf("Tipo: ");
    scanf(" %c", &movs[i].tipo);
    printf("Qtd: ");
    scanf("%d", &movs[i].qtd);
    printf("\n");

    int index;
    for (int j = 0; j < QTD_PRODUTOS; j++) {
      if (estoque[j].codigo == codigo) {
        index = j;
        break;
      }
    }

    if (movs[i].tipo == 's') {
      if (movs[i].qtd > estoque[index].qtd) {
        movs[i].qtd_pend = movs[i].qtd - estoque[index].qtd;
        estoque[index].qtd = 0;
      } else {
        estoque[index].qtd -= movs[i].qtd;
        movs[i].qtd_pend = 0;
      }
    } else {
      estoque[index].qtd += movs[i].qtd;
      movs[i].qtd_pend = 0;
    }

    i++;
  }

  printf("\n\n");
  return i;
}

void geraSaida(Produto estoque[20], int qntd_m, Movimentacao movs[qntd_m]) {
  int prod_zerados = 0;

  printf("=--- GERANDO SAÍDA ---=\n");
  for (int i = 0; i < QTD_PRODUTOS; i++) {
    int total_s = 0, total_d = 0, total_p = 0;

    for (int j = 0; j < qntd_m; j++) {
      if (movs[j].codigo == estoque[i].codigo) {
        if (movs[j].tipo == 's') {
          total_s += movs[j].qtd;
          total_p += movs[j].qtd_pend;
        } else {
          total_d += movs[j].qtd;
        }
      }
    }

    if (!estoque[i].qtd) prod_zerados++;

    printf("-- Produto %d\n", estoque[i].codigo);
    printf("Nome: %s\n", estoque[i].nome);
    printf("Qtd solicitada: %d\n", total_s);
    printf("Qtd pendente: %d\n", total_p);
    printf("Qtd devolvida: %d\n", total_d);
    printf("Qtd em estoque: %d\n\n", estoque[i].qtd);
  }

  printf("\nQtd com estoque zero: %d", prod_zerados);
}

int main() {
  Produto estoque[QTD_PRODUTOS];
  Movimentacao movs[1000];

  leDadosProdutos(estoque);
  int qntd_movs = leMovimentacoes(movs, estoque);

  geraSaida(estoque, qntd_movs, movs);
  
  return 0;
}