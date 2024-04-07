#include <stdio.h>

void calcularQntdCelulas(int valor) {
  int cedulas[7] = {100, 50, 20, 10, 5, 2, 1}, aux = valor;

  for (int i = 0; i < 7; i++) {
    if (aux/cedulas[i] != 0) {
      printf("\n%d nota(s) de R$ %d,00", aux/cedulas[i], cedulas[i]);
    }
    aux %= cedulas[i];
  }
}

int main() {
  int valor;

  printf("Digite o valor a ser sacado: ");
  scanf("%d", &valor);

  calcularQntdCelulas(valor);  

  return 0;
}