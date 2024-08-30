#include <stdio.h>
#include <string.h>

#define QTD_CARGOS 20
#define QTD_CANDIDATOS 10500

typedef struct {
  char nome[31], cargo[31], motivo_desclassificacao[100];
  float media;
} Candidato;

int busca(char nome[31], char nomes[QTD_CARGOS][31]) {
  for (int i = 0; i < QTD_CARGOS; i++) {
    if (!strcmp(nome, nomes[i])) {
      return i+1;
    }
  }

  return 0;
}

void leDadosCargos(char nomes[QTD_CARGOS][31], float notas[QTD_CARGOS][2]) {
  printf("===--- LENDO CARGOS ---===\n\n");
  for (int i = 0; i < QTD_CARGOS; i++) {
    printf("-- Cargo %0d\n", i+1);
    printf("Nome: ");
    scanf("%s", nomes[i]);
    printf("Nota mínima na prova de títulos: ");
    scanf("%f", &notas[i][0]);
    printf("Nota mínima nas provas específicas: ");
    scanf("%f", &notas[i][1]);
    printf("\n");
  }
  printf("\n");
}

int calculaNotaFinal(Candidato* candidato, float minima_titulo, float minima_especifica) {
  float notas[5];
  int qtd_zeros = 0;
  for (int i = 0; i < 5; i++) {
    if (!i) {
      printf("Nota na prova de títulos: ");
    } else {
      printf("Nota na %dª prova específica: ", i);
    }

    scanf("%f", &notas[i]);

    if (!notas[i]) {
      qtd_zeros++;
    }
  }

  (*candidato).media = 0;
  if (!qtd_zeros) {
    for (int i = 0; i < 5; i++) {
      if (!i && notas[i] < minima_titulo) {
        strcpy((*candidato).motivo_desclassificacao, "A nota mínima na prova de títulos não foi atingida.");
        (*candidato).media = 0;
        break;
      } else if (notas[i] < minima_especifica) {
        strcpy((*candidato).motivo_desclassificacao, "A nota mínima nas provas específicas não foi atingida.");
        (*candidato).media = 0;
        break;
      }

      (*candidato).media += notas[i]/5;
    }
  }

  return qtd_zeros;
}

void exibirResultado(Candidato candidatos[QTD_CANDIDATOS], char nomes_cargos[QTD_CARGOS][31], float notas_minimas[QTD_CARGOS][2]) {
  printf("===--- EXIBINDO RESULTADOS ---===\n\n");
  for (int i = 0; i < QTD_CANDIDATOS; i++) {
    printf("-- Candidato %0d\n", i+1);
    printf("Nome: %s\n", candidatos[i].nome);

    int index = busca(candidatos[i].cargo, nomes_cargos);
    if (!candidatos[i].media || strcmp(candidatos[i].motivo_desclassificacao, "")) {
      printf("Desclassificado pelo motivo: %s\n", candidatos[i].motivo_desclassificacao);
    } else {
      printf("Cargo desejado: %s\n", candidatos[i].cargo);
      printf("Média: %.2f\n", candidatos[i].media);
    }

    printf("\n");
  }
}

int main() {
  // Cargos
  char nomes_cargos[QTD_CARGOS][31];
  float notas_minimas[QTD_CARGOS][2];
  leDadosCargos(nomes_cargos, notas_minimas);

  // Candidatos
  Candidato candidatos[QTD_CANDIDATOS];
  printf("===--- LENDO CANDIDATOS ---===\n\n");
  for (int i = 0; i < QTD_CANDIDATOS; i++) {
    printf("-- Candidato %0d\n", i+1);
    strcpy(candidatos[i].motivo_desclassificacao, "");
    printf("Nome: ");
    scanf("%s", candidatos[i].nome);


    printf("Cargo: ");
    scanf("%s", candidatos[i].cargo);
    int resultado_busca = busca(candidatos[i].cargo, nomes_cargos);
    if (!resultado_busca) {
      strcpy(candidatos[i].motivo_desclassificacao, "Cargo inválido.");
    } else {
      if (
        calculaNotaFinal(
          &candidatos[i],
          notas_minimas[resultado_busca-1][0],
          notas_minimas[resultado_busca-1][1]
        )
      ) {
        strcpy(candidatos[i].motivo_desclassificacao, "Pelo menos uma das notas foi 0.");
      }
    }
    
    printf("\n");
  }
  printf("\n");

  // Resultado
  exibirResultado(candidatos, nomes_cargos, notas_minimas);

  return 0;
}