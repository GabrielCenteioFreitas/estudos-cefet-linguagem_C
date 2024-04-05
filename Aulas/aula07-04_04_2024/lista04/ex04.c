#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

float horista() {
  float valor_hora;
  int qntd_horas;

  printf("Insira o valor por hora: R$");
  scanf("%f", &valor_hora);
  printf("Insira a quantidade de horas trabalhadas: ");
  scanf("%d", &qntd_horas);

  return valor_hora*qntd_horas;
}

float contratado() {
  float salario;

  printf("Insira o salário: R$");
  scanf("%f", &salario);

  return salario;
}

float prestadorDeServico() {
  int qntd_servicos;
  float valor_hora;

  printf("Insira a quantidade de serviços prestados: ");
  scanf("%d", &qntd_servicos);
  printf("Insira o valor por cada serviço: R$");
  scanf("%f", &valor_hora);

  return valor_hora*qntd_servicos;
}

int exibirMenu() {
  int escolha;
  
  printf("[1] Horista\n[2] Contratado\n[3] Prestador de Serviço\n\nEscolha uma opção: ");
  scanf("%d", &escolha);

  return escolha;
}

int main() {
  int escolha;
  float salario;
  char saida;

  for (int i = 1; i <= 50; i++) {
    system(CLEAR);
    printf(">=--- Funcionário %02d ---=<\n", i);
    escolha = exibirMenu();

    switch(escolha) {
      case 1:
        salario = horista();
        break;
      case 2:
        salario = contratado();
        break;
      case 3:
        salario = prestadorDeServico();
        break;
      default:
        break;
    }

    printf("\nSalário: R$%.2f\n", salario);

    printf("Insira qualquer caractere para continuar: ");
    scanf(" %c", &saida);
  }


  
  return 0;
}