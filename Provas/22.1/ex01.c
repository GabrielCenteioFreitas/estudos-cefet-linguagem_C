#include <stdio.h>

int main() {
  int qntd, codigo, data, semanas, peso, mais_semanas, menos_semanas, mais_demorada, menos_demorada, qntd_marco = 0;
  float media = 0;

  printf("Qntd: ");
  scanf("%d", &qntd);

  for (int i = 0; i < qntd; i++) {
    scanf("%d%d%d%d", &codigo, &data, &semanas, &peso);
    if (i == 0 || semanas > mais_semanas) {
      mais_semanas = semanas;
      mais_demorada = codigo;
    }
    if (i == 0 || semanas < menos_semanas) {
      menos_semanas = semanas;
      menos_demorada = codigo;
    }
    if (((data%10000)/100) == 3) {
      media += peso;
      qntd_marco++;
    }
  }

  printf("Media de março: %.2f\n", media/qntd_marco);
  printf("Municipio mais demorada: %d\n", mais_demorada);
  printf("Municipio menos demorada: %d\n", menos_demorada);


  
  return 0;
}