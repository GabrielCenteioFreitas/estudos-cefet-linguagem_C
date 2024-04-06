#include <stdio.h>

float calculaIDH(float E, float L, float R) {
  if (E >= L+R) {
    return E * L * R / ((E + L + R)/3);
  } else {
    return (E + L + R)/3;
  }  
}

int main() {
  float E, L, R;

  printf("Digite o valor da dimensão Educação: ");
  scanf("%f", &E);
  printf("Digite o valor da dimensão Longevidade: ");
  scanf("%f", &L);
  printf("Digite o valor da dimensão Riqueza: ");
  scanf("%f", &R);

  printf("\nO valor do IDH é: %.2f", calculaIDH(E, L, R));
  
  return 0;
}