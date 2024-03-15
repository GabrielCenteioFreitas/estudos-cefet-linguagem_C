// Autor: Gabriel Centeio Freitas
// Data: 07/03/2024
// Descrição: Programa que verifica a existência de um triângulo e o classifica a partir da medida de seus lados.

#include <stdio.h>

int main() {
    int lado1, lado2, lado3;

    printf("Digite o comprimento do primeiro lado: ");
    scanf("%d", &lado1);
    printf("Digite o comprimento do segundo lado: ");
    scanf("%d", &lado2);
    printf("Digite o comprimento do terceiro lado: ");
    scanf("%d", &lado3);

    if(lado1+lado2>lado3 && lado1+lado3>lado2 && lado2+lado3>lado1) {
        printf("\nÉ possível formar um triângulo.\n");
        if(lado1==lado2 && lado2==lado3){
            printf("O triângulo é equilátero.\n");
        }
        else if (lado1!=lado2 && lado1!=lado3 && lado2!=lado3){
            printf("O triângulo é escaleno.\n");
        }
        else {
            printf("O triângulo é isósceles.\n");
        }
    }
    else {
        printf("\nNão é possível formar um triângulo com esses valores.");   
    }

  return 0;
}