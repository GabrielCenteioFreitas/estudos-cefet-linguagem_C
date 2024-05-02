#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

int exibirMenu() {
  char escolha;

  system(CLEAR);
  printf("Bem-vindo ao jogo da velha!\n\nDeseja iniciar? (s/n): ");
  scanf(" %c", &escolha);

  return escolha == 's' || escolha == 'S';
}

void exibirTabuleiro(char tabuleiro[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%c ", tabuleiro[i][j]);
    }
    printf("\n");
  }
}

void toggleJogador(int *jogador) {
  if (*jogador == 1){
    (*jogador) = 0;
  } else if (*jogador == 0){
    (*jogador) = 1;
  }
}

int verificarLinhas(char tabuleiro[3][3]) {
  for (int i = 0; i < 3; i++) {
    if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][2] != '_') {
      return 1;
    }
  }

  return 0;
}

int verificarColunas(char tabuleiro[3][3]) {
  for (int i = 0; i < 3; i++) {
    if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[2][i] != '_') {
      return 1;
    }
  }

  return 0;
}

int verificarDiagonais(char tabuleiro[3][3]) {
  for (int i = 0; i < 3; i += 2) {
    if (tabuleiro[0][i] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2-i] && tabuleiro[1][1] != '_') {
      return 1;
    }
  }

  return 0;
}

int verificarTabuleiro(char tabuleiro[3][3]) {  
  return (verificarLinhas(tabuleiro) || verificarColunas(tabuleiro) || verificarDiagonais(tabuleiro));
}

void sair() {
  char saida;
  
  printf("\n\nInsira qualquer tecla para sair\n");
  scanf(" %c", &saida);
}

int main() {
  while (exibirMenu()) {  
    char tabuleiro[3][3] = {{'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'}},
        letra_jogador,
        saida;
    int jogador = 0, 
        linha, coluna, 
        resultado = 0,
        jogadas = 0;
  
    while(jogadas < 10) {
      system(CLEAR);
      exibirTabuleiro(tabuleiro);
      if (resultado == 1) {
        printf("\n\nTemos um vencedor!\nParabéns ao jogador %c!", letra_jogador);
        sair();
        break;
      }
  
      if (jogador == 0) letra_jogador = 'X';
      if (jogador == 1) letra_jogador = 'O';
  
      if (jogadas < 9) {
        printf("\n\nVez do jogador %c\nOnde deseja jogar? (LINHA COLUNA): ", letra_jogador);
        scanf("%d%d", &linha, &coluna);
  
        if (tabuleiro[linha-1][coluna-1] == '_') {
          tabuleiro[linha-1][coluna-1] = letra_jogador;
          toggleJogador(&jogador);
          jogadas++;
        }
  
        resultado = verificarTabuleiro(tabuleiro);
      } else {
        printf("\n\nDeu velha!");
        sair();
        break;
      }
    }
  }
  
  return 0;
}