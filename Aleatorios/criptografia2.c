#include <stdio.h>
#include <string.h>

int main() {
  int qtd_linhas;

  printf("Número de linhas: ");
  scanf("%d", &qtd_linhas);

  getchar();
  
  char strings[qtd_linhas][1000];

  for (int i = 0; i < qtd_linhas; i++) {
    printf("Linha %d: ", i+1);
    scanf("%[^\n]s",strings[i]);
    getchar();
    
    strings[i][strcspn(strings[i], "\n")] = '\0';
  }

  printf("\n");
  for (int i = 0; i < qtd_linhas; i++) {
    char string_atual[1000];
    strcpy(string_atual, strings[i]);
    int tamanho = strlen(string_atual);

    // Passada 1
    for (int j = 0; j < tamanho; j++) {
      char caractere_atual = string_atual[j];
      
      if (
        (caractere_atual >= 65 && caractere_atual <= 90) ||
        (caractere_atual >= 97 && caractere_atual <= 122)
      ) {
        string_atual[j] = caractere_atual + 3;
      }
    }

    // Passada 2
    for (int j = 0; j < tamanho/2; j++) {
      char aux = string_atual[j];

      string_atual[j] = string_atual[tamanho-1-j];
      string_atual[tamanho-1-j] = aux;
    }

    // Passada 3
    for (int j = 0; j < (tamanho/2) + (tamanho%2); j++) {
      string_atual[tamanho-1-j] = string_atual[tamanho-1-j] - 1;
    }

    printf("Linha %d criptografada: %s\n", i+1, string_atual);
  }
  
  return 0;
}