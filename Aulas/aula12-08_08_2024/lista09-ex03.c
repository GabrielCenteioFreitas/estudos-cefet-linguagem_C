#include <stdio.h>

struct _Aluno {
  char nome[31];
  float nota1, nota2;
};

typedef struct _Aluno Aluno;

#define TURMA 3

void exibe(Aluno turma[TURMA], float media_turma) {
  for (int i = 0; i < TURMA; i++) {
    float media_aluno = (turma[i].nota1 + turma[i].nota2)/2;
    printf("=-----=\n");
    printf("Nome: %s\n", turma[i].nome);          
    printf("Média: %.2f\n", media_aluno);

    if (media_aluno > media_turma) {
      printf("Acima\n");
    } else if (media_aluno == media_turma) {
      printf("Igual\n");
    } else {
      printf("Abaixo\n");
    }
  }
}

int main() {
  Aluno turma[TURMA];
  float media_turma = 0;

  for (int i = 0; i < TURMA; i++) {
    printf("Nome: ");
    scanf("%s", turma[i].nome);
    printf("Notas: ");
    scanf("%f %f", &turma[i].nota1, &turma[i].nota2);
    printf("\n");

    media_turma += ((turma[i].nota1 + turma[i].nota2)/2)/TURMA;
  }

  exibe(turma, media_turma);
  return 0;
}