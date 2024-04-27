#include <stdio.h>

float categorizarIdade(int idade) {
  if (idade <= 19) {
    printf("Jovem\n");
  } else if (idade <= 59) {
    printf("Adulto\n");
  } else {
    printf("Idoso\n");
  }
}

int main() {
  categorizarIdade(60);
}