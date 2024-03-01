#include <stdio.h> //não precisa de ';' em include
#include <math.h>

int main() {
    float a, b, c, delta, x1, x2, x; //declarando as variáveis

    printf("Entre com os valores de a, b e c: ");
    scanf("%f%f%f",&a,&b,&c); //lendo as variáveis

    delta = (b*b)-(4*a*c); //atribuindo valor à variável delta
    if(delta > 0) {
        x1 = (-b+sqrt(delta)) / (2*a);
        x2 = (-b-sqrt(delta)) / (2*a);
        printf("Raízes são: %.2f e %.2f",x1,x2); //".2" formata para 2 casas decimais
    }
    if(delta < 0) {
        printf("Não existe raiz real");
    }
    if(delta == 0) {
        x = (-b)/(2*a);
        printf("Uma raiz: %.2f", x);
    }

    return 0;
} //não precisa de ';' em {}