#include <stdio.h>
#include <string.h>
#include "exporter.h"

typedef struct {
  char letra;
  int situacao;
} Palpite;

char palavra[6];
Palpite palpites[6][5];
int qtd_palpites = 0, ganhou = 0;

int contarLetras(char letra, int tamanho, char string[tamanho]) {
  int contador = 0;
  for (int i = 0; i < tamanho; i++) {
    if (string[i] == letra) {
      contador++;
    }
  }

  return contador;
}

void inicializarPalpites() {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 5; j++) {
      palpites[i][j].letra = '_';
      palpites[i][j].situacao = -1;
    }
  }
}

void printarJogo() {
  clearTerminal();
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 5; j++) {
      int situacao = palpites[i][j].situacao;
      char letra = palpites[i][j].letra;
        
      if (situacao == 1) {
        printf("\033[32m");
      } else if (situacao > 1) {
        printf("\033[33m");
      }
    
      printf("%c", letra);
    
      if (situacao > 0) {
        printf("\033[0m");
      }
    
      printf(" ");
    }
    printf("\n");
  }
}

void gerenciarPalpites() {
  while (qtd_palpites < 6 && ! ganhou) {
    int acertou = 0;
    char palpite[6];
    printf("\n");
    scanf("%s", palpite);
    
    for (int i = 0; i < 5; i++) {
      char letra = palpite[i] >= 97 && palpite[i] <= 122 ? palpite[i] - 32 : palpite[i];
      char letras_do_palpite[i];
        
      for (int j = 0; j < i; j++) {
        letras_do_palpite[j] = palpites[qtd_palpites][j].letra;
      }
            
      palpites[qtd_palpites][i].letra = letra;
    
      int situacao = 0;
      for (int j = 0; j < 5; j++) {
        if (letra == palavra[j]) {
          if (i == j) {
            situacao = 1;
            acertou++;

            for (int k = 0; k < i; k++) {
              if (
                letra == palpites[qtd_palpites][k].letra && 
                contarLetras(letra, i, letras_do_palpite) >= contarLetras(letra, 5, palavra) &&
                palpites[qtd_palpites][k].situacao == 2
              ) {
                palpites[qtd_palpites][k].situacao = 0;
                break;
              }
            }
         } else if (
           !situacao && 
           contarLetras(letra, i, letras_do_palpite) < contarLetras(letra, 5, palavra)
          ) {
            situacao = 2;
          }
        }
      }
            
      palpites[qtd_palpites][i].situacao = situacao;
    }

    qtd_palpites++;
    printarJogo();
    if (acertou == 5) {
      ganhou = 1;
    }
  }

  if (!ganhou) {
    printf("\nAh... poxa! A palavra era: %s\n", palavra);
  }
}

int main() {
  sortearPalavra(palavra);
  inicializarPalpites();
  printarJogo();
  gerenciarPalpites();
  
  return 0;
}