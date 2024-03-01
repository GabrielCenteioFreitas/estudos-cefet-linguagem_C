#include <stdio.h>

int main()
{
    float valor, perc_desconto, valor_desconto, valor_final;
    printf("Bem-vindo à loja XYZ!\n\nPor favor, insira o valor total de suas compras: ");
    scanf("%f",&valor);
    printf("\n");
    if(valor>=600){
        perc_desconto=20;
    }
    else if(valor>=400){
        perc_desconto=15;
    }
    else if(valor>=200){
        perc_desconto=10;
    }
    else{
        perc_desconto=0;
    }
    
    if(perc_desconto!=0){
        printf("Você recebeu um desconto de %.0f%%.\n", perc_desconto);
        perc_desconto = perc_desconto/100;
        valor_desconto=valor*perc_desconto;
        printf("Valor do desconto: R$ %.2f\n", valor_desconto);
        valor_final=valor-valor_desconto;
        printf("Total a ser pago: R$ %.2f", valor_final);
    }
    else{
        printf("Total a ser pago: R$ %.2f", valor);
    }
    return 0;
}