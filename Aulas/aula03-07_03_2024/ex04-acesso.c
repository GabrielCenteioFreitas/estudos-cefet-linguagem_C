// Autor: Gabriel Centeio Freitas
// Data: 07/03/2024
// Descrição: Programa que simula um processo de verificação de acesso

#include <stdio.h>

int main() {
    int matricula, senha, tentativas=0;

    printf("Bem-vindo ao Sistema de Autenticação!\n");
    while(tentativas<3){
        tentativas++;
        printf("Insira a matrícula do usuário: ");
        scanf("%d", &matricula);
        printf("Insira a senha do usuário: ");
        scanf("%d", &senha);
        if (matricula == 7892457 && senha == 123321) {
            printf("\nBem-vindo, Anakin Skywalker! Acesso concedido.\n");
            break;
        }
        else if (matricula == 5425376 && senha == 812837) {
            printf("\nBem-vinda, Leia Organa! Acesso concedido.\n");
            break;
        }
        else if (matricula == 2736252 && senha == 273625) {
            printf("\nBem-vindo, Luke Skywalker! Acesso concedido.");
            break;
        }
        else {
            printf("\nCredenciais incorretas. Tente novamente. Tentativas restantes: %d\n\n", 3-tentativas);
        }
    }

    return 0;
}