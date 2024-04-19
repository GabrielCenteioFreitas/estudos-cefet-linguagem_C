#include <stdio.h>

void umDepartamento(int qntd_func, float *maior_salario, int *qntd_func_maior) {
  float salario;
  
  for (int i = 0; i < qntd_func; i++) {
    printf("Digite o salário do funcionário: R$");
    scanf("%f", &salario);

    if (salario == *maior_salario) {
      (*qntd_func_maior)++;
    }
    if (i == 0 || salario > *maior_salario) {
      (*maior_salario) = salario;
      (*qntd_func_maior) = 1;
    }
  }  
}

int main() {
  int qntd_dep, qntd_func, qntd_func_maior = 0, codigo;
  float maior_salario;

  do {
    printf("Insira o código do dep: ");
    scanf("%d", &codigo);

    if (codigo != 0) {
      printf("Insira a qntd de funcionários desse dep: ");
      scanf("%d", &qntd_func);
      umDepartamento(qntd_func, &maior_salario, &qntd_func_maior);

      printf("\nMaior salário: R$%.2f\n", maior_salario);
      printf("Qntd de funcionários que recebem esse valor: %d", qntd_func_maior);
      printf("\n\n=-------=\n\n");
    }
  } while(codigo != 0);
  
}