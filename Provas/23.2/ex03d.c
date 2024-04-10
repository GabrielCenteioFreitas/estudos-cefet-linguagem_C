#include <stdio.h>

int bissexto(int ano) {
  return (ano%4 == 0) && ((ano%100 != 0) || (ano%400 == 0));
}

int validarData(int dia, int mes, int ano) {
  int dias_do_mes;

  if (mes < 1 || mes > 12) {
    return 0;
  }

  if (mes == 2) {
    if (bissexto(ano)) {
      dias_do_mes = 29;
    } else {
      dias_do_mes = 28;
    }
  } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
    dias_do_mes = 30;
  } else {
    dias_do_mes = 31;
  }

  return (dia > 0 && dia <= dias_do_mes);
}

int main(void) {
  int dia, mes, ano;
  scanf("%d%d%d", &dia, &mes, &ano);
  printf("%d", validarData(dia, mes, ano));
  
  return 0;
}