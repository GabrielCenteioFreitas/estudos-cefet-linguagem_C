// Autor: Gabriel Centeio Freitas
// Data: 29/02/2024
// Descrição: Programa que verifica se uma determinada data é válida.

#include <stdio.h>

int main() {
    int dia, mes, ano, diasDoMes;

    printf("Bem-vindo ao Verificador de Data!\nPor favor, insira a data no formato dia mês ano (exemplo: 25 02 2023): ");
    scanf("%d%d%d", &dia, &mes, &ano);
    printf("\n");

    if(mes > 12 || mes < 1) {
        printf("O mês inserido está errado.");
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
        printf("Data válida!");      
    }
    else {
        printf("O dia está errado.");
    }

    return 0;
}
