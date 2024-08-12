#include <stdio.h>

#define DIAS 5

void analisarVendas(int vendas[DIAS][4], float valores[4] ) {
  float total_tipos[4] = {0};

  for (int i = 0; i < DIAS; i++) {
    float total_do_dia = 0;
    
    for (int j = 0; j < 4; j++) {
      float valor_atual = vendas[i][j] * valores[j];
      total_tipos[j] += valor_atual;
      total_do_dia += valor_atual;
    }

    printf("Total do dia %d: R$ %.2f\n", i+1, total_do_dia);
  }

  for (int i = 0; i < 4; i++) {
    printf("Total do tipo %d: R$ %.2f\n", i+1, total_tipos[i]);
  }
}

int main() {
  int vendas[DIAS][4] = {
      {100, 150, 200, 250},
      {110, 160, 210, 260},
      {120, 170, 220, 270},
      {130, 180, 230, 280},
      {140, 190, 240, 290} 
  };

  float valores[4] = {5.50, 6.00, 6.50, 7.00};

  analisarVendas(vendas, valores);
  
  return 0;
}