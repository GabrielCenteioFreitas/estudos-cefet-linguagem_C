#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "exporter.h"

int main() {
  srand(time(NULL));

  int qntd_dados, qntd_lados, qntd_jogadas;

  printf("Quantos dados vai querer jogar por rodada? ");
  scanf("%d", &qntd_dados);
  printf("O dado terá quantos lados? ");
  scanf("%d", &qntd_lados);
  printf("Quantas vezes jogaremos os dados? ");
  scanf("%d", &qntd_jogadas);

  int max = qntd_lados*qntd_dados;
  int resultados[max+1];

  for (int i = 0; i <= max; i++) {
    resultados[i] = 0;
  }
  
  for (int i = 0; i < qntd_jogadas; i++) {
    int soma = 0;
    
    for (int j = 0; j < qntd_dados; j++) {
      soma += (rand() % qntd_lados) + 1;
    }

    resultados[soma]++;
  }

  clearTerminal();
  
  int largura = (int)log10(max) + 1;
  for (int i = qntd_dados; i <= max; i++) {
    printf("%*d ", largura, i);
    for (int j = 0; j < resultados[i]; j++) {
      printf("■");
    }
    printf("\n");
  }
  
  return 0;
}