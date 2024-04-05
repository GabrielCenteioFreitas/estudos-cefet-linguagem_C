#include <stdio.h>

void exibirTabuada(int n) {
  printf("\n>=--- Tabuada do %d ---=<\n", n);
  for(int i = 1; i <= 10; i++) {
    printf("%d x %2d = %d\n", n, i, n * i);    
  } 
}

int main() {
  int n;

  printf("Insira um número: ");
  scanf("%d", &n);
  exibirTabuada(n);
  
  return 0;
}