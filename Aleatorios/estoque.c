#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

void mostrar_lista(char produtos[][100], float precos[], int qntds[], int qntd_produtos) {
  system(CLEAR);

  printf("------------------------\n   Lista de Produtos\n------------------------\n\n");

  for (int i = 0; i < qntd_produtos; i++) {
    printf("[%d] %s\n", i+1, produtos[i]); 
  }
  if (qntd_produtos == 0) {
    printf("Não há produtos na lista\n");
  }
  printf("\n------------------------\n");

}

void pagina_adicionar_produto(char produtos[][100], float precos[], int qntds[], int *qntd_produtos){
  system(CLEAR);

  printf("Digite o nome do produto: ");
  scanf("%s", produtos[*qntd_produtos]);
  printf("Digite o preço do produto: ");
  scanf("%f", &precos[*qntd_produtos]);
  printf("Digite a quantidade do produto: ");
  scanf("%d", &qntds[*qntd_produtos]);
  printf("------------------------\n");
  (*qntd_produtos)++;
}

void pagina_editar_produtos(char produtos[][100], float precos[], int qntds[], int qntd_produtos) {
  system(CLEAR);
  int escolha;
  char voltar;

  mostrar_lista(produtos, precos, qntds, qntd_produtos);

  printf("\nQual produto deseja editar?\nDigite o número ao lado dele ou 0 para voltar: ");
  scanf("%d", &escolha);

  if (escolha > 0 && escolha <= qntd_produtos) {
    system(CLEAR);

    printf("Digite o nome do produto: ");
    scanf("%s", produtos[escolha-1]);
    printf("Digite o preço do produto: ");
    scanf("%f", &precos[escolha-1]);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &qntds[escolha-1]);
    printf("------------------------\n");
  }
}

void pagina_ver_produtos(char produtos[][100], float precos[], int qntds[], int qntd_produtos) {
  system(CLEAR);
  int escolha;
  char voltar;

  mostrar_lista(produtos, precos, qntds, qntd_produtos);

  printf("\nQual produto deseja ver?\nDigite o número ao lado dele ou 0 para voltar: ");
  scanf("%d", &escolha);

  if (escolha > 0 && escolha <= qntd_produtos) {
    system(CLEAR);
    printf("Nome: %s\n", produtos[escolha-1]);
    printf("Preco: R$ %.2f\n", precos[escolha-1]);
    printf("Quantidade: %d\n", qntds[escolha-1]);
    printf("Preço para comprar todos: R$ %.2f\n", qntds[escolha-1] * precos[escolha-1]);
    printf("\n------------------------\n");
    printf("\nInsira qualquer caractere para voltar\n");
    scanf(" %c", &voltar);
  }
}

void pagina_deletar_produto(char produtos[][100], float precos[], int qntds[], int *qntd_produtos) {
  system(CLEAR);
  int escolha;

  mostrar_lista(produtos, precos, qntds, *qntd_produtos);

  printf("\nQual produto deseja deletar?\nDigite o número ao lado dele ou 0 para voltar: ");
  scanf("%d", &escolha);

  if (escolha > 0 && escolha <= *qntd_produtos) {
    for (int i = escolha - 1; i < *qntd_produtos - 1; i++) {
      strcpy(produtos[i], produtos[i + 1]);
      precos[i] = precos[i + 1];
      qntds[i] = qntds[i + 1];
    }
    (*qntd_produtos)--;
  }
}

int pagina_inicial(char (*produtos)[100], float *precos, int *qntds, int *qntd_produtos) {
  system(CLEAR);
  int escolha;  

  mostrar_lista(produtos, precos, qntds, *qntd_produtos);

  printf("\n[1] Adicionar um produto\n[2] Ver um produto\n[3] Editar um produto\n[4] Deletar um produto\n[5] Sair\n\nDigite o que deseja fazer: ");
  scanf("%d", &escolha);
  switch (escolha) {
    case 1:
      pagina_adicionar_produto(produtos, precos, qntds, qntd_produtos);
      return 1;
    case 2:
      pagina_ver_produtos(produtos, precos, qntds, *qntd_produtos);
      return 1;
    case 3:
      pagina_editar_produtos(produtos, precos, qntds, *qntd_produtos);
      return 1;
    case 4:
      pagina_deletar_produto(produtos, precos, qntds, qntd_produtos);
      return 1;
    default:
      return 0; 
  }  
}

int main() {
  char produtos[100][100];
  float precos[100];
  int qntds[100], qntd_produtos=0;

  while(pagina_inicial(produtos, precos, qntds, &qntd_produtos)==1);

  return 0;
}