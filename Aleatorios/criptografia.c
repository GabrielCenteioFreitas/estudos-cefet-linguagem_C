#include <stdio.h>
#include <string.h>

int main() {
    int i, escolha;
    char texto[100];

    printf("[1] Criptografar um texto\n[2] Descriptografar um texto\nEscolha o que deseja fazer: ");
    scanf("%d", &escolha);

    while (escolha != 1 && escolha != 2) {
        printf("[1] Criptografar um texto\n[2] Descriptografar um texto\nEscolha o que deseja fazer: ");
        scanf("%d", &escolha);
    }

    if(escolha == 1) {
        printf("Digite o texto para ser criptografado: ");
        scanf("%s", &texto);
        printf("Resultado: ");
        for(i = 0; i < strlen(texto); i++){
            printf("%c", texto[i]-60);
        }
    }
    else {
        printf("Digite o texto para ser descriptografado: ");
        scanf("%s", &texto);
        printf("Resultado: ");
        for(i = 0; i < strlen(texto); i++){
            printf("%c", texto[i]+60);
        }
    }
    printf("\n");
    return 0;
}