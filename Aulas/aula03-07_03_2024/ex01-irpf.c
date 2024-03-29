// Autor: Gabriel Centeio Freitas
// Data: 07/03/2024
// Descrição: Programa que calcula salário líquido com base no salário inserido.

#include <stdio.h>

float IRPF(float bruto) {
    float irpf = 0;
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
    return irpf;
}

int main() {
    float bruto, irpf;

    printf("Digite o seu salário: ");
    scanf("%f", &bruto);
    irpf = IRPF(bruto);

    printf("IRPF: R$ %.2f\n", irpf);
    printf("Salário líquido: R$ %.2f\n", bruto-irpf);

    return 0;
}