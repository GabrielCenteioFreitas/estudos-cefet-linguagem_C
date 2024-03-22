// Autor: Gabriel Centeio Freitas
// Data: 21/03/2024
// Descrição: Programa que recebe dois números e exibe o MDC entre eles, explicando passo a passo o algoritmo de Euclides

#include <stdio.h>

int calcularMDC(int a_original, int b_original) {
  int a = a_original, b = b_original, aux, contador = 1;

  if (a < b) {
    aux = b;
    b = a;
    a = aux;
  } else {
    aux = a;
  }

  if (a % b == 0) {
    printf("1. A divisão de %d por %d resulta em resto 0.\n", a, b);
    contador++;
    printf("%d. ", contador);
  } else {
    while (a % b != 0) {
      printf("%d. A divisão de %d por %d resulta em resto %d.\n", contador, a, b, a%b);
      contador++;
      aux = a;
      if (a > b) {
        a = b;
      }
      b = aux%b;
      printf("%d. Atribuímos a = %d e b = %d (resto).\n", contador, a, b);
      contador++;
    }
    printf("%d. A divisão de %d por %d resulta em resto %d.\n", contador, a, b, a%b);
    contador++;
    printf("%d. ", contador);
  }

  return b;
}

int main() {
  int a_original, b_original;

  printf("Insira o 1° número: ");
  scanf("%d", &a_original);
  printf("Insira o 2° número: ");
  scanf("%d", &b_original);
  printf("\n");

  printf("O MDC de %d e %d é %d.", a_original, b_original, calcularMDC(a_original, b_original));
  
  return 0;
}