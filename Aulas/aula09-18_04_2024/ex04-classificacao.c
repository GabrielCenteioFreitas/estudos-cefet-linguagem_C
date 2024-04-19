#include <stdio.h>

int leValidaClassificacao() {
  int classificacao;

  do {
    printf("Digite a classificação (1 a 4): ");
    scanf("%d", &classificacao);
  } while (classificacao < 1 || classificacao > 4);

  return classificacao;
}

void classe(int classificacao, int *qntd_min, int *qntd_max) {
  switch (classificacao) {
    case 1:
      (*qntd_min) = 100;
      (*qntd_max) = 120;
      break;
    case 2:
      (*qntd_min) = 150;
      (*qntd_max) = 180;
      break;
    case 3:
      (*qntd_min) = 200;
      (*qntd_max) = 250;
      break;
    case 4:
      (*qntd_min) = 250;
      (*qntd_max) = 300;
      break;
  }    
}

int main() {
  int classificacao, qntd_min, qntd_max;

  for (int i = 0; i < 100; i++) {
    classificacao = leValidaClassificacao();
    classe(classificacao, &qntd_min, &qntd_max);
    printf("Qntd mínima: %d\n", qntd_min);
    printf("Qntd máxima: %d\n\n====================================\n\n", qntd_max);
  }
  
  return 0;
}