#include <stdio.h>

int main() {
  int n = -1, fatorial = 1;

  while (n < 0) {
    printf("Insira um numero nao-negativo: ");
    scanf("%d", &n);    
  }

  for (int i = n; i > 0; i--) {
    fatorial *= i;
  }

  printf("%d! = %d", n, fatorial);
  
  return 0;
}