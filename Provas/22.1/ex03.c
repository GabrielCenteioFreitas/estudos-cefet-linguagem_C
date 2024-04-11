#include <stdio.h>

int diaSeguinte(int data) {
  int dia = data%100, mes = (data%10000)/100, ano = data/10000, dias_do_mes;

  if (mes == 2) {
    if (((ano%4 == 0 && ano%100 != 0) || ano%400 == 0)) {
      dias_do_mes = 29;
    } else {
      dias_do_mes = 28;
    }
  } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
    dias_do_mes = 30;
  } else {
    dias_do_mes = 31;
  }

  if (dia == dias_do_mes) {
    dia = 0;
    mes++;
    if (mes == 13) {
      mes = 1;
      ano++;
    }
  }

  return (ano*10000) + (mes*100) + (dia+1);
}

void imprimirDataFormatada(int data) {
  printf("%02d/%02d/%02d\n", data%100, (data%10000)/100, data/10000);
}

int main() {
  int data, dia_seguinte;

  scanf("%d", &data);
  dia_seguinte = diaSeguinte(data);
  imprimirDataFormatada(dia_seguinte);

  return 0;
}