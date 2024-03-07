// Autor: Gabriel Centeio Freitas
// Data: 29/02/2024
// Descrição: Programa que verifica se uma determinada data é válida.

#include <stdio.h>

int main() {
    int dia, mes, ano, diasFevereiro;

    printf("Bem-vindo ao Verificador de Data!\nPor favor, insira a data no formato dia mês ano (exemplo: 25 02 2023): ");
    scanf("%d%d%d", &dia, &mes, &ano);
    printf("\n");

    if(mes > 12 || mes < 1) {
        printf("O mês inserido está errado.");
    }
    else if(mes == 2) {
        if(ano%4 == 0 && (ano%100 != 0 || ano%400 == 0)) {
            diasFevereiro = 29;
        }
        else {
            diasFevereiro = 28;
        }
      
        if(dia >= 1 && dia <= diasFevereiro){
            printf("Data válida!");
        }
        else {
            printf("O dia está errado.");
        }
    }
    else if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
        if(dia >= 1 && dia <= 31){
            printf("Data válida!");
        }
        else {
            printf("O dia está errado.");
        }
    }
    else {
        if(dia >= 1 && dia <= 30){
            printf("Data válida!");
        }
        else {
            printf("O dia está errado.");
        }
    }

    return 0;
}
