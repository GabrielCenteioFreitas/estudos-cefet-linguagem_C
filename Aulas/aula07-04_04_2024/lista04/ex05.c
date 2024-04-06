#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

float processarDepartamento(int codigo, int qntd_func) {
  int matricula;
  float salario, soma_salarios = 0;

  for (int i = 1; i <= qntd_func; i++) {
    printf("- Funcionário %02d -\n", i);
    printf("Insira a matrícula: ");
    scanf("%d", &matricula);
    printf("Insira o salário: ");
    scanf("%f", &salario);

    soma_salarios += salario;
  }

  printf(">=----------------------=<\n\nO código do departamento é: %d\nA soma dos salários do departamento é: %.2f\n\n", codigo, soma_salarios);

  return soma_salarios;
}

int main() {
  int codigo, qntd_func;
  float salario, soma_todos_salarios = 0;
  char saida;

  for (int i = 1; i <= 3; i++) {
    system(CLEAR);
    printf(">=--- Departamento %02d ---=<\n", i);
    printf("Insira o código do departamento: ");
    scanf("%d", &codigo);
    printf("Insira a quantidade de funcionários do departamento: ");
    scanf("%d", &qntd_func);

    soma_todos_salarios += processarDepartamento(codigo, qntd_func);

    printf(">=----------------------=<\nInsira qualquer caractere para ");
    if (i < 3) {
      printf("continuar: ");
    } else {
      printf("sair: ");
    }
    
    scanf(" %c", &saida);
  }

  system(CLEAR);
  printf(">=--- Soma de todos salários ---=<\n\nA soma de todos os salários é de: R$%.2f\n", soma_todos_salarios);



  return 0;
}