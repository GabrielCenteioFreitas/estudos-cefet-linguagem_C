#include <stdio.h>

void categorizarIdade(int idade) {
  if (idade < 16) {
    printf("\nNão eleitor");
  } else if ((idade >= 16 && idade < 18) || idade > 70) {
    printf("\nEleitor facultativo");
  } else {
    printf("\nEleitor");
  }
}

int main(void) {
  int idade;

  printf("Insira uma idade: ");
  scanf("%d", &idade);
  categorizarIdade(idade);
  
  return 0;
}