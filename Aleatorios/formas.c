#include <stdio.h>

int main() {
    printf("[1] Retângulo\n[2] Losango\nEscolha uma forma: ");
    int num;
    scanf("%d", &num);

    while(num != 1 && num != 2){
        printf("[1] Retângulo\n[2] Losango\nEscolha uma forma: ");
        scanf("%d", &num);
    }

    if(num == 1) {
        int largura, altura;
        printf("Escolha a largura do retângulo: ");
        scanf("%d", &largura);
        while(largura < 1){
            printf("Escolha a largura do retângulo: ");
            scanf("%d", &largura);
        }
        printf("Escolha a altura do retângulo: ");
        scanf("%d", &altura);
        while(altura < 1){
            printf("Escolha a altura do retângulo: ");
            scanf("%d", &altura);
        }

        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < largura; j++) {
                printf("[]");
            }
            printf("\n");
        }
    }
    if(num == 2) {
        int largura;
        printf("Escolha a largura do losango(min: 3): ");
        scanf("%d", &largura);
        while(largura < 3 || largura%2 == 0){
            printf("Escolha a largura do losango(min: 3; apenas ímpares): ");
            scanf("%d", &largura);
        }

        int a, e, z;
        a = 1;
        e = largura/2;
        z = 0;
        for(int i = 1; i <= largura; i++){
            if(i <= (largura+1)/2) {
                for(int j = e; j > 0 ;j--) {
                    printf(" ");
                }
                e--;
                for(int n = 0; n < a; n++){
                    printf("*");
                }
                a+=2;
            }
            else {
                if (z == 0) {
                    e = 1;
                    a-=4;
                }
                for(int j = 0; j < e ;j++) {
                    printf(" ");
                }
                e++;
                for(int n = 0; n < a; n++){
                    printf("*");
                }
                a-=2;
                z++;
            }
            printf("\n");
        }
    }



    return 0;
}