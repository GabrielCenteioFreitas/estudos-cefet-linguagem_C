#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

int pagina_inicial(void **lista, int qntd_produtos);

void mostrar_lista(void **lista, int qntd_produtos) {
  system(CLEAR);

  printf("------------------------\n   Lista de Produtos\n------------------------\n\n");

  for (int i = 0; i < qntd_produtos; i++) {
    printf("[%d] %s\n", i+1, (char *)(lista[0]+i*100)); 
  }
  if (qntd_produtos == 0) {
    printf("Não há produtos na lista\n");
  }
  printf("\n------------------------\n");

}

void pagina_adicionar_produto(void **lista, int qntd_produtos) {
  system(CLEAR);

  printf("Digite o nome do produto: ");
  scanf("%s", (char *)(lista[0] + qntd_produtos*100));
  printf("Digite o preço do produto: ");
  scanf("%f", (float *)&lista[1][qntd_produtos]);
  printf("Digite a quantidade do produto: ");
  scanf("%d", (int *)&lista[2][qntd_produtos]);
  printf("------------------------\n");
  qntd_produtos++;

  pagina_inicial(lista, qntd_produtos);
}

int pagina_ver_produtos(void **lista, int qntd_produtos) {
  system(CLEAR);
  int escolha;
  char voltar;

  mostrar_lista(lista, qntd_produtos);

  printf("\nQual produto deseja ver?\nDigite o número ao lado dele ou 0 para voltar: ");
  scanf("%d", &escolha);

  if (escolha > 0 && escolha <= qntd_produtos) {
    system(CLEAR);
    printf("Nome: %s\n", (char *)(lista[0] + (escolha-1)*100));
    printf("Preco: R$ %.2f\n", *(float *)&lista[1][(escolha-1)]);
    printf("Quantidade: %d\n", *(int *)&lista[2][(escolha-1)]);
    printf("Preço para comprar todos: R$ %.2f\n", (*(int *)&lista[2][(escolha-1)]) * (*(float *)&lista[1][(escolha-1)]));
    printf("\n------------------------\n");
    printf("\nInsira qualquer caractere para voltar\n");
    scanf(" %c", &voltar);

    if (voltar) {
      pagina_inicial(lista, qntd_produtos);
      return 0;
    }
  }

  pagina_inicial(lista, qntd_produtos);
  return 0;
}

int pagina_inicial(void **lista, int qntd_produtos) {
  system(CLEAR);
  int escolha;  

  mostrar_lista(lista, qntd_produtos);

  printf("\n[1] Adicionar um produto\n[2] Ver um produto\n[3] Sair\nDigite o que deseja fazer: ");
  scanf("%d", &escolha);
  if (escolha == 1) {
    pagina_adicionar_produto(lista, qntd_produtos);
  }
  else if (escolha == 2){
    pagina_ver_produtos(lista, qntd_produtos);
  }
  else {
    return 0;
  }


  return 0;  
}

int main() {
  void *lista[3] = {NULL};
  char produtos[100][100];
  float precos[100];
  int qntds[100], qntd_produtos=0;
  lista[0] = produtos; lista[1] = precos; lista[2] = qntds;

  pagina_inicial(lista, qntd_produtos);

  return 0;
}