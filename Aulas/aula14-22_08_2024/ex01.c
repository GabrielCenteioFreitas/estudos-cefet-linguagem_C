#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[100];
  int idade;
  float peso, altura;
  char atividade[100];
} Aluno;

#define QTD_MAX_ALUNOS 200
Aluno alunos[QTD_MAX_ALUNOS];
int qtd_alunos = 0;

void saida() {
  char caractere; 
  printf("Sair: ");
  scanf(" %c", &caractere);
}

void leDadosAluno(Aluno *aluno) {
  printf("Nome: ");
  scanf("%s", (*aluno).nome);
  printf("Idade: ");
  scanf("%d", &(*aluno).idade);
  printf("Peso(kg): ");
  scanf("%f", &(*aluno).peso);
  printf("Altura(m): ");
  scanf("%f", &(*aluno).altura);
  printf("Atividade: ");
  scanf("%s", (*aluno).atividade);
}

void exibeAluno(Aluno aluno, int i) {
  printf("-- Aluno %d\n", i+1);
  printf("Nome: %s\n", aluno.nome);
  printf("Idade: %d anos\n", aluno.idade);
  printf("Peso: %.2f kg\n", aluno.peso);
  printf("Altura: %.2f m\n", aluno.altura);
  printf("Atividade: %s\n\n", aluno.atividade);
}

void leDados() {
  system("clear");
  printf("==--- Lendo dados ---==\n\n");
  for (int i = 0; i < QTD_MAX_ALUNOS; i++) {
    printf("----- Aluno %d -----\n", i+1);
    leDadosAluno(&alunos[i]);
    printf("\n");
    qtd_alunos++;
  }
  
  printf("\n");
  saida();
}

void imprimeDados() {
  system("clear");
  printf("==--- Imprimindo Dados ---==\n\n");
  for (int i = 0; i < qtd_alunos; i++) {
    exibeAluno(alunos[i], i);
  }

  saida();
}

float calculaIMC(float peso, float altura) {
  return peso / (altura*altura);
}

void ordenaAlunos(Aluno  alunos_ordenados[qtd_alunos]) {
  int trocou;
  do {
    trocou = 0;
    for (int i = 0; i < qtd_alunos-1; i++) {
      if (strcmp(alunos_ordenados[i].nome, alunos_ordenados[i+1].nome) > 0) {
        Aluno aux = alunos_ordenados[i];
        alunos_ordenados[i] = alunos_ordenados[i+1];
        alunos_ordenados[i+1] = aux;
        trocou = 1;
      }
    }
  } while(trocou);
}

void geraRelatorio() {
  system("clear");
  printf("==--- Relatório de Dados ---==\n\n");
  
  Aluno alunos_ord[qtd_alunos];
  for (int i = 0; i < qtd_alunos; i++) {
    alunos_ord[i] = alunos[i];
  }
  ordenaAlunos(alunos_ord);
  
  for (int i = 0; i < qtd_alunos; i++) {
    exibeAluno(alunos_ord[i], i);
    printf("IMC: %.2f\n", calculaIMC(alunos_ord[i].peso, alunos_ord[i].altura));
  }

  saida();
}

void atualizaAluno() {
  system("clear");
  printf("==--- Atualizando aluno ---==\n\n");
  
  char busca[100];
  printf("Qual aluno você deseja atualizar? ");
  scanf("%s", busca);

  int index;
  for (int i = 0; i < qtd_alunos; i++) {
    if (strcmp(busca, alunos[i].nome) == 0) {
      index = i;
      break;
    }
  }

  printf("\n\n");
  leDadosAluno(&alunos[index]);
  printf("\n\n");
  saida();
}

void removeAluno() {
  system("clear");
  printf("==--- Removendo aluno ---==\n\n");
  
  char busca[100];
  printf("Qual aluno você deseja remover? ");
  scanf("%s", busca);

  int index;
  for (int i = 0; i < qtd_alunos; i++) {
    if (strcmp(busca, alunos[i].nome) == 0) {
      index = i;
      break;
    }
  }

  for (int i = index; i < qtd_alunos-1; i++) {
    alunos[i] = alunos[i+1];
  }
  qtd_alunos--;

  printf("Removido!\n\n");
  saida();
}

void exibeMenu() {
  system("clear");
  printf("==--- Menu ---==\n\n");
  int escolha;

  if (!qtd_alunos) {
    printf("[1] Ler dados\n");
    printf("\nDigite sua ação: ");
    scanf("%d", &escolha);

    if (escolha == 1)  {
      leDados();
    }

    return;
   }
  
  printf("[1] Imprimir dados\n");
  printf("[2] Gerar relatório\n");
  printf("[3] Atualizar aluno\n");
  printf("[4] Remover aluno\n");
  printf("\nDigite sua ação: ");
  scanf("%d", &escolha);
  
  switch (escolha) {
    case 1:
      imprimeDados();
      break;
    case 2:
      geraRelatorio();
      break;
    case 3:
      atualizaAluno();
      break;
    case 4:
      removeAluno();
      break;
    default:
      break;
  }
}

int main() {
  while (1) {
    exibeMenu();
  }
  return 0;
}