#include <stdio.h>

int verificarMatricula(int matricula) {
  return (
    (matricula/1000 >= 10 && matricula/1000 <= 22) &&
    (matricula%100 >= 1 && matricula%100 <= 90) &&
    ((matricula/100)%100 == 1 || (matricula/100)%100 == 2)
    );
}

int main() {
  int matricula;

  printf("Insira a matrícula: ");
  scanf("%d", &matricula);
  
  if (verificarMatricula(matricula)) {
    printf("\nMatricula válida");
  } else {
    printf("\nMatricula inválida");
  }

  
  return 0;
}