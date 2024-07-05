#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "exportador.h"

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif


int verificarPossibilidade1_2(int altura, int largura, int labirinto[altura][largura], int* x, int* y, int x_anterior, int y_anterior, int* jaExisteSaida) {
  int posX = *x, posY = *y;

  return (
    (verificarLimitesLargura(posX+1, largura)) && !(posX+1 == x_anterior && posY == y_anterior) &&
    (
      (
        (posX+1 == (largura-1) && !(*jaExisteSaida)) ||
        (posX+1 != (largura-1) &&
          (
            (!verificarAmbosLimites(posY  , posX+2, altura, largura) || labirinto[posY  ][posX+2]) &&
            (!verificarAmbosLimites(posY+1, posX+1, altura, largura) || labirinto[posY+1][posX+1]) &&
            (!verificarAmbosLimites(posY+1, posX+2, altura, largura) || labirinto[posY+1][posX+2]) &&
            (!verificarAmbosLimites(posY-1, posX+1, altura, largura) || labirinto[posY-1][posX+1]) &&
            (!verificarAmbosLimites(posY-1, posX+2, altura, largura) || labirinto[posY-1][posX+2]) &&
            (
              (
                (!verificarAmbosLimites(posY-1, posX, altura, largura) && !verificarAmbosLimites(posY-1, posX-1, altura, largura)) ||
                (labirinto[posY-1][posX] || labirinto[posY-1][posX-1])
              ) && (
                (!verificarAmbosLimites(posY+1, posX, altura, largura) && !verificarAmbosLimites(posY+1, posX-1, altura, largura)) ||
                (labirinto[posY+1][posX] || labirinto[posY+1][posX-1])
              )
            )
          )
        )
      ) || (
        verificarLimitesLargura(posX+1, largura) &&
        !labirinto[posY][posX+1]
      )
    )
  );
}

int verificarPossibilidade2_2(int altura, int largura, int labirinto[altura][largura], int* x, int* y, int x_anterior, int y_anterior) {
  int posX = *x, posY = *y;

  return (
    (verificarLimitesAltura(posY+1, altura)) && !(posX == x_anterior && posY+1 == y_anterior) && (posX != 0) && (posX != largura-1) &&
    (
      (
        (!verificarAmbosLimites(posY+2, posX  , altura, largura) || labirinto[posY+2][posX  ]) &&
        (!verificarAmbosLimites(posY+1, posX+1, altura, largura) || labirinto[posY+1][posX+1]) &&
        (!verificarAmbosLimites(posY+1, posX-1, altura, largura) || labirinto[posY+1][posX-1]) &&
        (!verificarAmbosLimites(posY+2, posX+1, altura, largura) || labirinto[posY+2][posX+1]) &&
        (!verificarAmbosLimites(posY+2, posX-1, altura, largura) || labirinto[posY+2][posX-1]) && 
        (
          (
           (!verificarAmbosLimites(posY, posX-1, altura, largura) && !verificarAmbosLimites(posY-1, posX-1, altura, largura)) ||
           (labirinto[posY][posX-1] || labirinto[posY-1][posX-1])
          ) && (
            (!verificarAmbosLimites(posY, posX+1, altura, largura) && !verificarAmbosLimites(posY-1, posX+1, altura, largura)) ||
            (labirinto[posY][posX+1] || labirinto[posY-1][posX+1])
          )
        )
      ) || (
        !labirinto[posY+1][posX]
      )
    )
  );
}

int verificarPossibilidade3_2(int altura, int largura, int labirinto[altura][largura], int* x, int* y, int x_anterior, int y_anterior) {
  int posX = *x, posY = *y;

  return (
    (verificarLimitesLargura(posX-1, largura)) && !(posX-1 == x_anterior && posY == y_anterior) && (posX-1 != 0) &&
    (
      (
        (!verificarAmbosLimites(posY  , posX-2, altura, largura) || labirinto[posY  ][posX-2]) &&
        (!verificarAmbosLimites(posY+1, posX-1, altura, largura) || labirinto[posY+1][posX-1]) &&
        (!verificarAmbosLimites(posY+1, posX-2, altura, largura) || labirinto[posY+1][posX-2]) &&
        (!verificarAmbosLimites(posY-1, posX-1, altura, largura) || labirinto[posY-1][posX-1]) &&
        (!verificarAmbosLimites(posY-1, posX-2, altura, largura) || labirinto[posY-1][posX-2]) &&
        (
          (
            (!verificarAmbosLimites(posY-1, posX, altura, largura) && !verificarAmbosLimites(posY-1, posX+1, altura, largura)) ||
            (labirinto[posY-1][posX] || labirinto[posY-1][posX+1])
          ) && (
            (!verificarAmbosLimites(posY+1, posX, altura, largura) && !verificarAmbosLimites(posY+1, posX+1, altura, largura)) ||
            (labirinto[posY+1][posX] || labirinto[posY+1][posX+1])
          )
        )
      ) || (
        verificarLimitesLargura(posX-1, largura) &&
        !labirinto[posY][posX-1]
      )
    )
  );
}

int verificarPossibilidade4_2(int altura, int largura, int labirinto[altura][largura], int* x, int* y, int x_anterior, int y_anterior) {
  int posX = *x, posY = *y;

  return (
    (verificarLimitesAltura(posY-1, altura)) && !(posX == x_anterior && posY-1 == y_anterior) && (posX != 0) && (posX != largura-1) &&
    (
      (
        (!verificarAmbosLimites(posY-2, posX  , altura, largura) || labirinto[posY-2][posX  ]) &&
        (!verificarAmbosLimites(posY-1, posX+1, altura, largura) || labirinto[posY-1][posX+1]) &&
        (!verificarAmbosLimites(posY-1, posX-1, altura, largura) || labirinto[posY-1][posX-1]) &&
        (!verificarAmbosLimites(posY-2, posX+1, altura, largura) || labirinto[posY-2][posX+1]) &&
        (!verificarAmbosLimites(posY-2, posX-1, altura, largura) || labirinto[posY-2][posX-1]) && 
        (
          (
            (!verificarAmbosLimites(posY, posX+1, altura, largura) && !verificarAmbosLimites(posY+1, posX+1, altura, largura)) ||
            (labirinto[posY][posX+1] || labirinto[posY+1][posX+1])
          ) && (
            (!verificarAmbosLimites(posY, posX-1, altura, largura) && !verificarAmbosLimites(posY+1, posX-1, altura, largura)) ||
            (labirinto[posY][posX-1] || labirinto[posY+1][posX-1])
          )
        )
      ) || (
        !labirinto[posY-1][posX]
      )
    )
  );
}

void gerarCaminho2(int altura, int largura, int labirinto[altura][largura], int* x, int* y, int* x_anterior, int* y_anterior, int* jaExisteSaida, int* zerouPossibilidades, int y_entrada, int* y_saida) {
  int possibilidades[4] = {0}, random;
  // Possibilidade 1: andar para a direita
  // Possibilidade 2: andar para baixo
  // Possibilidade 3: andar para a esquerda
  // Possibilidade 4: andar para cima

  possibilidades[0] = verificarPossibilidade1_2(altura, largura, labirinto, x, y, *x_anterior, *y_anterior, jaExisteSaida);
  possibilidades[1] = verificarPossibilidade2_2(altura, largura, labirinto, x, y, *x_anterior, *y_anterior);
  possibilidades[2] = verificarPossibilidade3_2(altura, largura, labirinto, x, y, *x_anterior, *y_anterior);
  possibilidades[3] = verificarPossibilidade4_2(altura, largura, labirinto, x, y, *x_anterior, *y_anterior);

  if (!contarPossibilidades(possibilidades)) {
    (*zerouPossibilidades)++;
    (*y) = y_entrada;
    (*x) = 0;
    (*y_anterior) = y_entrada;
    (*x_anterior) = -1;
    return;
  }

  random = rand() % 4;
  while (!possibilidades[random]) {
    random = rand() % 4;
  }

  switch(random) {
    case 0: // Possibilidade 1
      if (*x + 1 < largura) {
        labirinto[*y][*x + 1] = 0;
        (*x_anterior) = (*x);
        (*y_anterior) = (*y);
        (*x)++;

        if (*x == (largura-1)) {
          (*jaExisteSaida) = 1;
          (*y_saida) = (*y);
        }
      }
      break;
    case 1: // Possibilidade 2
      if (*y + 1 < altura) {
        labirinto[*y + 1][*x] = 0;
        (*x_anterior) = (*x);
        (*y_anterior) = (*y);
        (*y)++;
      }
      break;
    case 2: // Possibilidade 3
      if (*x - 1 > 0) {
        labirinto[*y][*x - 1] = 0;
        (*x_anterior) = (*x);
        (*y_anterior) = (*y);
        (*x)--;
      }
      break;
    case 3: // Possibilidade 4
      if (*y - 1 > 0) {
        labirinto[*y - 1][*x] = 0;
        (*x_anterior) = (*x);
        (*y_anterior) = (*y);
        (*y)--;
      }
      break;
    default:
      break;
  }
}

void gerarLabirinto2(int largura, int altura, int labirinto[altura][largura], int* y_entrada, int* y_saida) {
  int x = 0, y = *y_entrada,
      x_anterior = -1, y_anterior = *y_entrada,
      jaExisteSaida = 0, zerouPossibilidades = 0;

  srand(time(NULL));  

  preencherLabirinto(altura, largura, labirinto);
  labirinto[y][x] = 0;

  while (zerouPossibilidades < (largura*largura*altura*altura) || !jaExisteSaida) {
    gerarCaminho2(altura, largura, labirinto, &x, &y, &x_anterior, &y_anterior, &jaExisteSaida, &zerouPossibilidades, *y_entrada, y_saida);
  }
}