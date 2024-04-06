#include <stdio.h>

int descobrirMaior(int a, int b, int c) {
  if (a > b && a > c) {
    return a;
  } else if (b > a && b > c) {
    return b;
  } else {
    return c;
  }
}

int main() {
  int a, b, c;

  printf("Digite o valor de a: ");
  scanf("%d", &a);
  printf("Digite o valor de b: ");
  scanf("%d", &b);
  printf("Digite o valor de c: ");
  scanf("%d", &c);

  printf("\nO maior valor é %d", descobrirMaior(a, b, c));

  
  return 0;
}