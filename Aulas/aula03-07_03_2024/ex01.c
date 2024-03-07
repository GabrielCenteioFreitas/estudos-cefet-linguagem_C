// Autor: Gabriel Centeio Freitas
// Data: 07/03/2024
// Descrição: Programa que calcula salário líquido com base no salário inserido.

#include <stdio.h>

int main() {
    float bruto, irpf;
    printf("Digite o seu salário: ");
    scanf("%f", &bruto);
    if(bruto > 4664.68){
        irpf = (bruto*0.275)-869.36;
    }
    else if(bruto >= 3751.06){
        irpf = (bruto*0.225)-636.13;
    }
    else if(bruto >= 2826.66) {
        irpf = (bruto*0.15)-354.80;
    }
    else if(bruto >= 1903.99) {
        irpf = (bruto*0.075)-142.80;
    }
    else {
        irpf = 0;
    }
    printf("IRPF: R$ %.2f\n", irpf);
    printf("Salário líquido: R$ %.2f", bruto-irpf);
    return 0;
}