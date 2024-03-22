// Autor: Gabriel Centeio Freitas
// Data: 21/03/2024
// Descrição: Programa que recebe uma data no formato DDMMAAAA e verifica sua validade

#include <stdio.h>

int validaData(int data) {
  int diasDoMes, dia, mes, ano;

  dia = data/1000000;
  mes = (data/10000)%100;
  ano = data%10000;

  if(mes > 12 || mes < 1) {
    return 0;
  } 
  else {
    if (mes == 2) {
      if(ano%4 == 0 && (ano%100 != 0 || ano%400 == 0)) {
          diasDoMes = 29;
      }
      else {
          diasDoMes = 28;
      }
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        diasDoMes = 30;
    }
    else {
        diasDoMes = 31;
    }
  }

  if (dia >= 1 && dia <= diasDoMes) {
    return 1; 
  }
  else {
    return 0;
  } 
}

int main() {
  int data;
  
  do  {
    printf("Digite uma data (DDMMAAAA) ou -1 para encerrar: ");
    scanf("%d", &data);

    if (data != -1) {
      if (validaData(data)) {
        if ((data/10000)%100 < 10) {
          printf("Data válida: %d/0%d/%d\n\n", data/1000000, (data/10000)%100, data%10000);
        } else {
          printf("Data válida: %d/%d/%d\n\n", data/1000000, (data/10000)%100, data%10000);
        }
      }
      else {
        if ((data/10000)%100 < 10) {
          printf("Data inválida: %d/0%d/%d\n\n", data/1000000, (data/10000)%100, data%10000);
        } else {
          printf("Data inválida: %d/%d/%d\n\n", data/1000000, (data/10000)%100, data%10000);
        }
      }
    }
  } while (data != -1);
  
  return 0;
}