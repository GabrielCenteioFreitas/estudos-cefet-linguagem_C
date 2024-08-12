#include <stdio.h>
#include <string.h>

void leDadosCandidatos(char candidatos[15][21]) {
  for (int i = 0; i < 15; i++) {
    printf("Digite o nome do candidato %d: ", i + 1);
    scanf("%s", candidatos[i]);
  }
  printf("\n");
}

void ordena(char candidatos[15][21]) {
  for (int i = 0; i < 14; i++) {
    for (int j = 0; j < 14 - i; j++) {
      if (strcmp(candidatos[j], candidatos[j + 1]) > 0) {
        char temp[21];
        strcpy(temp, candidatos[j]);
        strcpy(candidatos[j], candidatos[j + 1]);
        strcpy(candidatos[j + 1], temp);
      }
    }
  }
}

void leVotos(char candidatos[15][21], int votos[15][2]) {
  for (int i = 0; i < 10; i++) {
    char nome_candidato[21];
    int local;
    printf("Digite o nome do candidato que deseja votar: ");
    scanf("%s", nome_candidato);
    printf("Local de residência: ");
    scanf("%d", &local);

    for (int j = 0; j < 15; j++) {
      if (strcmp(nome_candidato, candidatos[j]) == 0) {
        votos[j][local]++;
      }
    }
  }
  printf("\n");
}

int descobreEleito(int votos[15][2]) {
  int max_votos = votos[0][0] + votos[0][1], eleito = 0;
  for (int i = 0; i < 15; i++) {
    int total = votos[i][0] + votos[i][1];
    if (total > max_votos) {
      max_votos = total;
      eleito = i;
    }
  }

  return eleito;
}

void geraRelatorio(char candidatos[15][21], int votos[15][2],
                   int candidato_eleito) {
  printf("------------------------------------------------\n");
  printf("|         Nome         | Local | Exte. | Total |\n");
  printf("------------------------------------------------\n");
  for (int i = 0; i < 15; i++) {
    printf("| %*s | %*d | %*d | %*d |\n", 20, candidatos[i], 5, votos[i][0], 5,
           votos[i][1], 5, votos[i][0] + votos[i][1]);
  }
  printf("------------------------------------------------\n");

  printf("\nPresidente eleito: %s", candidatos[candidato_eleito]);
}

int main() {
  char candidatos[15][21];
  leDadosCandidatos(candidatos);
  ordena(candidatos);

  int votos[15][2] = {0};
  leVotos(candidatos, votos);

  int candidato_eleito = descobreEleito(votos);

  geraRelatorio(candidatos, votos, candidato_eleito);

  return 0;
}