#include <stdio.h>

void exibirTotal(int qntd_mensal[6][12], int valores[6]) {
  for (int i = 0; i < 6; i++) {
    float total = 0;
    
    for (int j = 0; j < 12; j++) {
      total += qntd_mensal[i][j] * valores[i];
    }
    
    printf("Valor total em %d: R$ %.2f\n", 2010 + i, total);
  }
}

int main() {
  int qntd_mensal[6][12] = {
      {10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32}, // 2010
      {11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33}, // 2011
      {12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34}, // 2012
      {13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35}, // 2013
      {14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36}, // 2014
      {15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37}  // 2015
  };

  int valores[6] = {25000, 26000, 27000, 28000, 29000, 30000};

  exibirTotal(qntd_mensal, valores);
  
  return 0;
}