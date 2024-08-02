#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "exporter.h"
#include <termios.h>
#include <fcntl.h>

#define LARGURA 16
#define ALTURA 16
#define ATRAVESSAPAREDE 0
int perdeu = 0;
int tamanhoDaCobra = 2;
int cobra[LARGURA*ALTURA][2] = {{0, 0}, {0, 1}};
int maca[2];
char movimento = 'd';

void gerarMaca() {
  while (arrayIntEstaNoArray(tamanhoDaCobra, 2, maca, cobra)) {
    maca[0] = rand() % (ALTURA - 1);
    maca[1] = rand() % (LARGURA - 1);
  }
}

void gerenciarPerdeu() {
  perdeu = 1;
  clearTerminal();
  printarPerdeu();
  
  int macasComidas = tamanhoDaCobra - 2;
  if (macasComidas > 0) {
    printf("       Você comeu %d maçã(s)!", macasComidas);
  }
}

void printarJogo() {
  clearTerminal();
  for (int i = 0; i < ALTURA; i++) {
    for (int j = 0; j < LARGURA; j++) {
      int coords[2] = {i, j};
      if (arrayIntEstaNoArray(tamanhoDaCobra, 2, coords, cobra)) {
        if (arraysIntSaoIguais(2, coords, cobra[tamanhoDaCobra - 1])) {
          printf("🐸");
        } else {
          printf("🟩");
        }
      } else if (arraysIntSaoIguais(2, coords, maca)) {
        printf("🍎");
      } else {
        printf("⬛");
      }
    }
    printf("\n");
  }
}

int verificarSeTemIgual() {
  for (int i = 0; i < tamanhoDaCobra; i++) {
    int contador = 0;

    for (int i = 0; i < tamanhoDaCobra; i++) {
      if (arraysIntSaoIguais(2, cobra[i], cobra[tamanhoDaCobra-1])) {
        contador++;
      }
    }

    if (contador > 1) return 1;
  }

  return 0;
}

void moverCima() {
  if (cobra[tamanhoDaCobra-2][0] - 1 < 0) {
    if (ATRAVESSAPAREDE) {
      cobra[tamanhoDaCobra-1][0] = ALTURA - 1;
    } else gerenciarPerdeu();
  } else {
    cobra[tamanhoDaCobra-1][0] = cobra[tamanhoDaCobra-2][0] - 1;
  }
  cobra[tamanhoDaCobra-1][1] = cobra[tamanhoDaCobra-2][1];
}
void moverDireita() {
  cobra[tamanhoDaCobra-1][0] = cobra[tamanhoDaCobra-2][0];
  if (cobra[tamanhoDaCobra-2][1] + 1 > LARGURA-1) {
    if (ATRAVESSAPAREDE) {
      cobra[tamanhoDaCobra-1][1] = 0;
    } else gerenciarPerdeu();
  } else {
    cobra[tamanhoDaCobra-1][1] = cobra[tamanhoDaCobra-2][1] + 1;
  }
}
void moverBaixo() {
  if (cobra[tamanhoDaCobra-2][0] + 1 > ALTURA-1) {
    if (ATRAVESSAPAREDE) {
      cobra[tamanhoDaCobra-1][0] = 0;
    } else gerenciarPerdeu();
  } else {
    cobra[tamanhoDaCobra-1][0] = cobra[tamanhoDaCobra-2][0] + 1;
  }
  cobra[tamanhoDaCobra-1][1] = cobra[tamanhoDaCobra-2][1];
}
void moverEsquerda() {
  cobra[tamanhoDaCobra-1][0] = cobra[tamanhoDaCobra-2][0];
  if (cobra[tamanhoDaCobra-2][1] - 1 < 0) {
    if (ATRAVESSAPAREDE) {
      cobra[tamanhoDaCobra-1][1] = LARGURA-1;
    } else gerenciarPerdeu();
  } else {
    cobra[tamanhoDaCobra-1][1] = cobra[tamanhoDaCobra-2][1] - 1;
  }
}
  
void gerenciarMovimento() {
  if (movimento == 'w') moverCima();
  if (movimento == 'd') moverDireita();
  if (movimento == 's') moverBaixo();
  if (movimento == 'a') moverEsquerda();
}

void gerenciarComeu() {
  gerarMaca();
  tamanhoDaCobra++;
  gerenciarMovimento();
}

void mover() {
  for (int i = 0; i < tamanhoDaCobra; i++) {
    cobra[i][0] = cobra[i+1][0];
    cobra[i][1] = cobra[i+1][1];
  }
  
  gerenciarMovimento();

  if (arrayIntEstaNoArray(tamanhoDaCobra, 2, maca, cobra)) gerenciarComeu();

  if (verificarSeTemIgual()) gerenciarPerdeu();
}

int main() {
  srand(time(NULL));
  gerarMaca();
  while (!perdeu) {
    printarJogo();

    if (kbhit()) {
      char ch = getchar();
      if (ch == 'w') movimento = 'w';
      if (ch == 'd') movimento = 'd';
      if (ch == 's') movimento = 's';
      if (ch == 'a') movimento = 'a';
    }
    
    mover();
    
    usleep(500000); // 500.000 microsegundos
  }
  
  return 0;
}