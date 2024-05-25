#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

int verificarLimitesAltura(int y, int altura) {
  return y > 0 && y < altura-1;
}
int verificarLimitesLargura(int x, int largura) {
  return x >= 0 && x < largura;
}
int verificarAmbosLimites(int y, int x, int altura, int largura) {
  return verificarLimitesLargura(x, largura) && verificarLimitesAltura(y, altura);
}

int contarPossibilidades(int possibilidades[4]) {
  for (int i = 0; i < 4; i++) {
    if (possibilidades[i]) return 1;
  }

  return 0;
}

void preencherLabirinto(int altura, int largura, int labirinto[altura][largura]) {
  for(int i = 0; i < altura; i++) {
    for(int j = 0; j < largura; j++) {
      labirinto[i][j] = 1;
    }
  }
}

void printarLabirinto(int altura, int largura, int labirinto[altura][largura], int y_entrada, int y_saida) {
  system(CLEAR);
  
  for(int i = 0; i < altura; i++) {
    for(int j = 0; j < largura; j++) {
      if ((i == y_entrada && j == 0) || (i == y_saida && j == largura-1)) {
        printf("⏩");
      } else {
        printf(labirinto[i][j] ? "⬛" : "⬜");
      }
    }
    printf("\n");
  }
}

int verificarPossibilidade1(int altura, int largura, int labirinto[altura][largura], int* x, int* y, int x_anterior, int y_anterior, int* jaExisteSaida) {
  int posX = *x, posY = *y;

  if (
    (verificarLimitesLargura(posX+1, largura)) && !(posX+1 == x_anterior && posY == y_anterior) &&
    (
      (
        (posX+1 == (largura-1) && !(*jaExisteSaida)) ||
        (posX+1 != (largura-1) && (
          (
            (!verificarAmbosLimites(posY  , posX+2, altura, largura) || labirinto[posY  ][posX+2]) &&
            (!verificarAmbosLimites(posY+1, posX+1, altura, largura) || labirinto[posY+1][posX+1]) &&
            (!verificarAmbosLimites(posY+1, posX+2, altura, largura) || labirinto[posY+1][posX+2]) &&
            (!verificarAmbosLimites(posY-1, posX+1, altura, largura) || labirinto[posY-1][posX+1]) &&
            (!verificarAmbosLimites(posY-1, posX+2, altura, largura) || labirinto[posY-1][posX+2])
          )
        ))
      ) || (
        verificarLimitesLargura(posX+1, largura) &&
        !labirinto[posY][posX+1]
      )
    )
  )  {  
    return 1;
  }
  
  return 0;
}

int verificarPossibilidade2(int altura, int largura, int labirinto[altura][largura], int* x, int* y, int x_anterior, int y_anterior) {
  int posX = *x, posY = *y;

  if (
    (verificarLimitesAltura(posY+1, altura)) && !(posX == x_anterior && posY+1 == y_anterior) && (posX != 0) && (posX != largura-1) &&
    (
      (
        (!verificarAmbosLimites(posY+2, posX  , altura, largura) || labirinto[posY+2][posX  ]) &&
        (!verificarAmbosLimites(posY+1, posX+1, altura, largura) || labirinto[posY+1][posX+1]) &&
        (!verificarAmbosLimites(posY+1, posX-1, altura, largura) || labirinto[posY+1][posX-1]) &&
        (!verificarAmbosLimites(posY+2, posX+1, altura, largura) || labirinto[posY+2][posX+1]) &&
        (!verificarAmbosLimites(posY+2, posX-1, altura, largura) || labirinto[posY+2][posX-1])
      ) ||
      (
        !labirinto[posY+1][posX]
      )
    )
  ) {
    return 1;
  }

  return 0;
}

int verificarPossibilidade3(int altura, int largura, int labirinto[altura][largura], int* x, int* y, int x_anterior, int y_anterior) {
  int posX = *x, posY = *y;

  if (
    (verificarLimitesLargura(posX-1, largura)) && !(posX-1 == x_anterior && posY == y_anterior) && (posX-1 != 0) &&
    (
      (
        (!verificarAmbosLimites(posY  , posX-2, altura, largura) || labirinto[posY  ][posX-2]) &&
        (!verificarAmbosLimites(posY+1, posX-1, altura, largura) || labirinto[posY+1][posX-1]) &&
        (!verificarAmbosLimites(posY+1, posX-2, altura, largura) || labirinto[posY+1][posX-2]) &&
        (!verificarAmbosLimites(posY-1, posX-1, altura, largura) || labirinto[posY-1][posX-1]) &&
        (!verificarAmbosLimites(posY-1, posX-2, altura, largura) || labirinto[posY-1][posX-2])
      ) || (
        verificarLimitesLargura(posX-1, largura) &&
        !labirinto[posY][posX-1]
      )
    )
  ) {
    return 1;
  }

  return 0;
}

int verificarPossibilidade4(int altura, int largura, int labirinto[altura][largura], int* x, int* y, int x_anterior, int y_anterior) {
  int posX = *x, posY = *y;

  if (
    (verificarLimitesAltura(posY-1, altura)) && !(posX == x_anterior && posY-1 == y_anterior) && (posX != 0) && (posX != largura-1) &&
    (
      (
        (!verificarAmbosLimites(posY-2, posX  , altura, largura) || labirinto[posY-2][posX  ]) &&
        (!verificarAmbosLimites(posY-1, posX+1, altura, largura) || labirinto[posY-1][posX+1]) &&
        (!verificarAmbosLimites(posY-1, posX-1, altura, largura) || labirinto[posY-1][posX-1]) &&
        (!verificarAmbosLimites(posY-2, posX+1, altura, largura) || labirinto[posY-2][posX+1]) &&
        (!verificarAmbosLimites(posY-2, posX-1, altura, largura) || labirinto[posY-2][posX-1])
      ) ||
      (
        !labirinto[posY-1][posX]
      )
    )
  ) {
    return 1;
  }

  return 0;
}

void gerarCaminho(int altura, int largura, int labirinto[altura][largura], int* x, int* y, int* x_anterior, int* y_anterior, int* jaExisteSaida, int* zerouPossibilidades, int y_entrada, int* y_saida) {
  int possibilidades[4] = {0}, random;
  // Possibilidade 1: andar para a direita
  // Possibilidade 2: andar para baixo
  // Possibilidade 3: andar para a esquerda
  // Possibilidade 4: andar para cima

  possibilidades[0] = verificarPossibilidade1(altura, largura, labirinto, x, y, *x_anterior, *y_anterior, jaExisteSaida);
  possibilidades[1] = verificarPossibilidade2(altura, largura, labirinto, x, y, *x_anterior, *y_anterior);
  possibilidades[2] = verificarPossibilidade3(altura, largura, labirinto, x, y, *x_anterior, *y_anterior);
  possibilidades[3] = verificarPossibilidade4(altura, largura, labirinto, x, y, *x_anterior, *y_anterior);
  
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

int main() {
  int largura = 36, altura = 36, labirinto[altura][largura],
      y_entrada = 1, y_saida,
      x = 0, y = y_entrada,
      x_anterior = -1, y_anterior = y_entrada,
      jaExisteSaida = 0, zerouPossibilidades = 0;

  srand(time(NULL));  
  
  preencherLabirinto(altura, largura, labirinto);
  labirinto[y][x] = 0;

  while (zerouPossibilidades < (largura*largura*altura) || !jaExisteSaida) {
    gerarCaminho(altura, largura, labirinto, &x, &y, &x_anterior, &y_anterior, &jaExisteSaida, &zerouPossibilidades, y_entrada, &y_saida);
  }
  printarLabirinto(altura, largura, labirinto, y_entrada, y_saida);

  return 0;
}