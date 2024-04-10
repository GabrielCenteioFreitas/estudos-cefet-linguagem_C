#include <stdio.h>

int main() {
  int valor, total_valores_normais = 0, qntd_valores = 0, qntd_normais = 0, qntd_susp = 0;
  float media;

  while (1) {
    printf("Valor: ");
    scanf("%d", &valor);

    if(qntd_valores == 0 || valor < 1.5*media) {
      printf("Normal\n");
      total_valores_normais += valor;
      qntd_normais++;
      media = (float) total_valores_normais / qntd_normais;
    } else if (valor < 2*media) {
      printf("Suspeita\n");
      qntd_susp++;
    } else {
      printf("Bloqueada\n");
      break;
    }
    qntd_valores++;
  }

  printf("Média: %f\n", media);
  printf("Qntd normais: %d\n", qntd_normais);
  printf("Qntd suspeitas: %d", qntd_susp);

  return 0;
}