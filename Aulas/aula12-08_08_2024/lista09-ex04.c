#include <stdio.h>
#include <string.h>

struct _Produto {
  float preco;
  int qntd;
};

typedef struct _Produto Produto;

int leitura(char nomes[][31], Produto estoque[]) {
  int i = 0;
  char nome_atual[31] = "";

  while (strcmp(nome_atual, "Fim") != 0) {
    printf("Nome: ");
    scanf("%s", nome_atual);

    if (strcmp(nome_atual, "Fim") != 0) {
      strcpy(nomes[i], nome_atual);
      printf("Preço: ");
      scanf("%f", &estoque[i].preco);
      printf("Qntd: ");
      scanf("%d", &estoque[i].qntd);

      i++;
    }

    printf("\n");
  }

  return i;
}

int main() {
  Produto estoque[1000];
  char nomes[1000][31];
  int qntd = leitura(nomes, estoque);

  char busca[31];
  while (strcmp(busca, "Fim") != 0) {
    printf("\nBusca: ");
    scanf("%s", busca);

    if (strcmp(busca, "Fim") == 0) {
      return 0;
    }

    int encontrado = 0;
    for (int i = 0; i < qntd; i++) {
      if (strcmp(nomes[i], busca) == 0) {
        printf("Qntd: %d\n", estoque[i].qntd);
        printf("Preço: R$ %.2f\n", estoque[i].preco);
          encontrado = 1;
      }
    }

    if (!encontrado) {
      printf("Produto inexistente\n");
    }
  }
  
  return 0;
}