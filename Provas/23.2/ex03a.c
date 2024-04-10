#include <stdio.h>

int verificaQuadradoPerfeito(int n) {
  int k = 1;
  while (k*k != n && k < n) {
    k++;
  }
  return (k != n);
}

int main(void) {
  int n;

  scanf("%d", &n);
  printf("%d", verificaQuadradoPerfeito(n));
  
  return 0;
}