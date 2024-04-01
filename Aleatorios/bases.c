// Esse projeto é um Conversor de Bases e também uma Calculadora com operações de Soma, Subtração, Multiplicação e Divisão para qualquer base

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

int outraBaseParaDecimal(int base, char* num) {
  int expoente = 0, decimal = 0;
  
  for (int i = strlen(num)-1; i >= 0 ; i--) {
    
    if (isdigit(num[i])) {
      decimal += (num[i] - '0')*pow(base, expoente);
    } else {
      decimal += (toupper(num[i])-55)*pow(base, expoente);
    }

    expoente++;
  }

  return decimal;
}

char* decimalParaOutraBase(int base, int num) {
  int resto, i = 0;
  char *num_convertido = NULL;

  do {
    resto = num % base;
    num /= base;

    if (resto >= 10 && resto <= 35) {
      // + 'A' é pra virar tabela ASCII, -58 é pq -26 eu acesso a letra f e -32 a letra F
      resto = (resto + 'A') - 58;
    }

    num_convertido = realloc(num_convertido, (i + 1) * sizeof(char));
    num_convertido[i] = resto + '0';
    i++;
  } while (num != 0);

  num_convertido = realloc(num_convertido, (i + 1) * sizeof(char));
  num_convertido[i] = '\0';

  int j, len = i;
  for (j = 0; j < len / 2; j++) {
    char temp = num_convertido[j];
    num_convertido[j] = num_convertido[len - j - 1];
    num_convertido[len - j - 1] = temp;
  }

  return num_convertido;
}

void conversorDeBase() {
  system(CLEAR);
  int base_do_num, base_para_converter;
  char num[100], saida;

  system(CLEAR);
  printf("Insira um número: ");
  scanf("%s", num);
  printf("De qual base é esse número? ");
  scanf("%d", &base_do_num);
  printf("Para qual base deseja converter? ");
  scanf("%d", &base_para_converter);

  int num_decimal = outraBaseParaDecimal(base_do_num, num);

  char* num_convertido = decimalParaOutraBase(base_para_converter, num_decimal);

  printf("\nO número convertido para a base %d é %s\n", base_para_converter, num_convertido);

  free(num_convertido);

  printf("\nDigite qualquer coisa para sair ");
  scanf(" %c", &saida);
}

void realizarOperacoes() {
  int escolha, base;
  int soma, subtracao, multiplicacao, divisao;
  char num1[100], num2[100], saida;

  system(CLEAR);
  printf("[1] Soma\n[2] Subtração\n[3] Multiplicação\n[4] Divisão\n\nEscolha o que deseja fazer: ");
  scanf("%d", &escolha);
  printf("\nInsira em qual base será realizada a operação: ");
  scanf("%d", &base);  

  system(CLEAR);
  printf("Insira o 1° número: ");
  scanf("%s", num1);
  printf("Insira o 2° número: ");
  scanf("%s", num2);

  switch (escolha) {
    case 1:
      soma = outraBaseParaDecimal(base, num1) + outraBaseParaDecimal(base, num2);
      printf("\nA soma dos números é %s\n", decimalParaOutraBase(base, soma));
      break;
  case 2:
      subtracao = outraBaseParaDecimal(base, num1) - outraBaseParaDecimal(base, num2);
      printf("\nA subtração dos números é %s\n", decimalParaOutraBase(base, subtracao));
      break;
  case 3:
      multiplicacao = outraBaseParaDecimal(base, num1) * outraBaseParaDecimal(base, num2);
      printf("\nA multiplicação dos números é %s\n", decimalParaOutraBase(base, multiplicacao));
      break;
  case 4:
      divisao = outraBaseParaDecimal(base, num1) / outraBaseParaDecimal(base, num2);
      printf("\nA divisão dos números é %s\n", decimalParaOutraBase(base, divisao));
      break;
  default:
    break;
  }

  printf("\nDigite qualquer coisa para sair ");
  scanf(" %c", &saida);
}

int main() {
  int escolha;

  do {
    system(CLEAR);

    printf("[1] Converter bases\n[2] Realizar operações com qualquer base\n[3] Sair\n\nEscolha o que deseja fazer: ");
    scanf("%d", &escolha);
    
    if (escolha == 1) {
      conversorDeBase();        
    } else if (escolha == 2) {
      realizarOperacoes();
    }
      
  } while (escolha == 1 || escolha == 2);

  return 0;
}
