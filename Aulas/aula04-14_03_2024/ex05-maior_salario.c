// Autor: Gabriel Centeio Freitas
// Data: 14/03/2024
// Descrição: Programa que recebe os salários dos funcionários de uma empresa e exibe o maior, junto da quantidade de funcionários que recebem esse valor

#include <stdio.h>

// Se forem inseridas duas matrículas iguais, o programa considerará o maior salário
int verificarMatricula(int matricula, int *matriculas, int qntd_func) {
  for (int i = 0; i < qntd_func; i++) {
    if (matricula == matriculas[i]) {
      return 1;
    }
  }
  
  return 0;
}

int calculaMaiorSalario(int qntd_func, int *matriculas) {
  int qntd_maior_salario, matricula;
  float salario, maior_salario = 0;

  for (int i=0;i<qntd_func;i++) {
    printf("\nInsira a matrícula do funcionário: ");
    scanf("%d", &matricula);

    printf("Insira o salário do funcionário: ");
    scanf("%f", &salario);

    if (salario > maior_salario) {
      maior_salario = salario;
      qntd_maior_salario = 1;
    }
    else if (salario == maior_salario && verificarMatricula(matricula, matriculas, qntd_func)==0) {
      qntd_maior_salario++;
    }
    
    matriculas[i] = matricula;
  }

  if (qntd_maior_salario == 1) {
    printf("\nO maior salário é R$ %.2f e apenas 1 funcionário recebe esse valor.", maior_salario);
  }
  else {
    printf("\nO maior salário é R$ %.2f e %d funcionários recebem esse valor.", maior_salario, qntd_maior_salario);    
  }

  return 0;
}

int main(void) {
  int qntd_func;

  printf("Insira a quantidade de funcionários na empresa: ");
  scanf("%d", &qntd_func);

  int matriculas[qntd_func];

  calculaMaiorSalario(qntd_func, matriculas);

  return 0;
}