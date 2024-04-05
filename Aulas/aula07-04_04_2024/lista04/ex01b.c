#include <stdio.h>

void exibirTabuada(int n) {
  
  printf("\n>=--- Tabuada do %d ---=<\n", n);
  for(int i = 1; i <= 10; i++) {
    if (n != 10) {
      printf("%d x %2d = %2d\n", n, i, n * i);   
    } else {
      printf("%d x %2d = %3d\n", n, i, n * i);   
    }
  } 
}

int main() {
  
  for(int i = 1; i <= 10; i++) {
    exibirTabuada(i);
  } 

  return 0;
}