// Autor: Gabriel Centeio Freitas
// Data: 22/02/2024
// Descrição: Programa que calcula as raízes de uma equação do segundo grau.

#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, delta, x1, x2, x;

    printf("Entre com os valores de a, b e c: ");
    scanf("%f%f%f",&a,&b,&c);

    delta = (b*b)-(4*a*c);
    if(delta > 0) {
        x1 = (-b+sqrt(delta)) / (2*a);
        x2 = (-b-sqrt(delta)) / (2*a);
        printf("Raízes são: %.2f e %.2f",x1,x2);
    }
    if(delta < 0) {
        printf("Não existe raiz real");
    }
    if(delta == 0) {
        x = (-b)/(2*a);
        printf("Uma raiz: %.2f", x);
    }

    return 0;
}