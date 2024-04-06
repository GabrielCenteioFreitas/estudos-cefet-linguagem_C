#include <stdio.h>

float calcularSalarioBase(float valor_hora, int qntd_horas_trabalhadas) {
  return valor_hora * qntd_horas_trabalhadas;
}

float calcularDescontoINSS(float salario_base) {
  if (salario_base*0.11 > 450.27) {
    return 450.27;
  } else {
    return salario_base * 0.11;
  }
}

float calcularDescontoIRPF(float salario_base) {
  if (salario_base <= 1800) {
    return 0;
  } else if (salario_base > 1800 && salario_base <= 2900) {
    return salario_base * 0.15;
  } else {
    return salario_base * 0.275;
  }  
}

int main() {
  int matricula, qntd_horas_trabalhadas;
  float valor_hora, salario_base;

  printf("Digite a matrícula do funcionário: ");
  scanf("%d", &matricula);
  printf("Digite o valor da hora trabalhada: R$");
  scanf("%f", &valor_hora);
  printf("Digite a quantidade de horas trabalhadas: ");
  scanf("%d", &qntd_horas_trabalhadas);

  salario_base = calcularSalarioBase(valor_hora, qntd_horas_trabalhadas);

  printf("\nA matrícula do funcionário é: %d", matricula);
  printf("\nO salário base é: R$%.2f", salario_base);
  printf("\nO desconto do INSS é: R$%.2f", calcularDescontoINSS(salario_base));
  printf("\nO desconto do IRPF é: R$%.2f", calcularDescontoIRPF(salario_base));
  printf("\nO salário líquido é: R$%.2f", salario_base - (calcularDescontoINSS(salario_base) + calcularDescontoIRPF(salario_base)));
  
  return 0;
}