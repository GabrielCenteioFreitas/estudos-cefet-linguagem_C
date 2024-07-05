#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "exporter.h"

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

int arrayPossuiElemento(char array[], char elemento, int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    if (array[i] == elemento) return 1;
  }

  return 0;
}

void printarLabirinto(int altura, int largura, int labirinto[altura][largura], int y_entrada, int y_saida, int x_atual, int y_atual) {
  system(CLEAR);
  printf("\n");

  for(int i = 0; i < altura; i++) {
    for(int j = 0; j < largura; j++) {
      if ((i == y_atual && j == x_atual)) {
        printf("🔴");
      } else {
        if ((i == y_entrada && j == 0) || (i == y_saida && j == largura-1)) {
          printf("⏩");
        } else {
          printf(labirinto[i][j] ? "⬛" : "  ");
        }
      }
    }
    printf("\n");
  }
}

void andar(int altura, int largura, int labirinto[altura][largura], int y_entrada, int y_saida, int* x_atual, int* y_atual) {
  char direcao_input[1],
      teclas_possiveis[8]={'W', 'w', 'A', 'a', 'S', 's', 'D', 'd'};

  printf("\nPróximo movimento(W A S D): ");
  scanf(" %c", &direcao_input[0]);

  if (!arrayPossuiElemento(teclas_possiveis, direcao_input[0], 8) || strlen(direcao_input) != 1) {
    system(CLEAR);
    return;
  }

  char direcao = direcao_input[0];

  if (
    (direcao == 'W' || direcao == 'w') &&
    verificarLimitesAltura((*y_atual)-1, altura) &&
    ((*x_atual) != 0 && (*x_atual) != largura-1) &&
    (labirinto[(*y_atual)-1][(*x_atual)] == 0)
  ) {
    (*y_atual)--;
  }
  if (
    (direcao == 'A' || direcao == 'a') &&
    verificarLimitesLargura((*x_atual)-1, largura) &&
    ((*x_atual)-1 != 0 || (*y_atual) == y_entrada) &&
    (labirinto[(*y_atual)][(*x_atual)-1] == 0)
  ) {
    (*x_atual)--;
  }
  if (
    (direcao == 'S' || direcao == 's') &&
    verificarLimitesAltura((*y_atual)+1, altura) &&
    ((*x_atual) != 0 && (*x_atual) != largura-1) &&
    (labirinto[(*y_atual)+1][(*x_atual)] == 0)
  ) {
    (*y_atual)++;
  }
  if (
    (direcao == 'D' || direcao == 'd') &&
    verificarLimitesLargura((*x_atual)+1, largura) &&
    ((*x_atual)+1 != largura-1 || (*y_atual) == y_saida) &&
    (labirinto[(*y_atual)][(*x_atual)+1] == 0)
  ) {
    (*x_atual)++;
  }
  
  system(CLEAR);
}

int main() {
  int largura = 32, altura = 32,
    labirinto[altura][largura],
    y_entrada = 1, y_saida,
    x_atual = 0, y_atual = 1,
    vitoria = 0;
  
  gerarLabirinto2(largura, altura, labirinto, &y_entrada, &y_saida);

  while (!vitoria) {
    printarLabirinto(altura, largura, labirinto, y_entrada, y_saida, x_atual, y_atual);
    andar(altura, largura, labirinto, y_entrada, y_saida, &x_atual, &y_atual);

    if (x_atual == largura-1) vitoria = 1;
  }

  printarFinal();
  return 0;
}