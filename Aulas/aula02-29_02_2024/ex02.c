// Autor: Gabriel Centeio Freitas
// Data: 29/02/2024
// Descrição: Programa que calcula salário líquido com base no salário inserido.

#include <stdio.h>

int main() {
    float bruto;
    printf("Digite o seu salário: ");
    scanf("%f", &bruto);
    if(bruto > 4664.68){
        printf("Salário líquido: R$ %.2f", bruto-(bruto*0.275)+869.36);
    }
    else if(bruto >= 3751.06){
        printf("Salário líquido: R$ %.2f", bruto-(bruto*0.225)+636.13);
    }
    else if(bruto >= 2826.66) {
        printf("Salário líquido: R$ %.2f", bruto-(bruto*0.15)+354.80);
    }
    else if(bruto >= 1903.99) {
        printf("Salário líquido: R$ %.2f", bruto-(bruto*0.075)+142.80);
    }
    else {
        printf("Salário líquido: R$ %.2f", bruto);
    }
    return 0;
}