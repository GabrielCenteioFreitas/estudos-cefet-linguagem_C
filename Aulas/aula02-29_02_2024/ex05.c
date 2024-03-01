#include <stdio.h>

int main() {
    float nota1, nota2, notaFinal, media;

    printf("Bem-vindo ao Sistema de Verificação de Situação Acadêmica!\n\n");
    printf("Por favor, insira a nota da prova 1: ");
    scanf("%f", &nota1);
    printf("Por favor, insira a nota da prova 2: ");
    scanf("%f", &nota2);

    media = (nota1+nota2) / 2;

    if(media >= 7){
        printf("Aprovado!");
    }
    else {
        printf("Por favor, insira a nota da prova final: ");
        scanf("%f", &notaFinal);

        media = (media + notaFinal) / 2;
        if (media >= 5){
            printf("Aprovado!");
        }
        else {
            printf("Reprovado!");
        }
    }

    return 0;
}