#include <stdio.h>

int verificaPerfeito(int n) {
  int soma = 0;

  for (int i = n; i > 0; i--) {
    if (n%i == 0 && i != n) {
      soma += i;
    }
  }

  return (soma == n);
}

int main() {
  int n, qntd_perfeitos = 0;

  for (int i = 0; i < 100; i++) {
    printf("Insira um número: ");
    scanf("%d", &n);

    if(verificaPerfeito(n)) {
      printf("%d é um número perfeito\n", n);
      qntd_perfeitos++;
    } else {
      printf("%d não é um número perfeito\n", n);
    }
  }

  printf("Qntd de perfeitos: %d", qntd_perfeitos);

  return 0;
}