#include <stdio.h>

#define QTD_ATLETAS 3

typedef struct _Atleta Atleta;
struct _Atleta {
  int codigo, idade, codigoModalidade, classificacao;
};

void exibe(Atleta campeoes[], int qtdCampeoes, float idadeMediaCampeoes) {
  for (int i = 0; i < qtdCampeoes; i++) {
    if (campeoes[i].idade < idadeMediaCampeoes) {
      printf("%5d %5d %5d\n", campeoes[i].codigo, campeoes[i].codigoModalidade, campeoes[i].idade);
    }
  }
}

int main() {
  Atleta campeoes[QTD_ATLETAS];
  int somaDasIdades = 0, qtdCampeoes = 0;

  int codigo, idade, codigoModalidade, classificacao;
  for (int i = 0; i < QTD_ATLETAS; i++) {
    scanf("%d", &codigo);
    scanf("%d", &idade);
    scanf("%d", &codigoModalidade);
    scanf("%d", &classificacao);

    if (classificacao == 1) {
      campeoes[qtdCampeoes].codigo = codigo;
      campeoes[qtdCampeoes].idade = idade;
      campeoes[qtdCampeoes].codigoModalidade = codigoModalidade;
      campeoes[qtdCampeoes].classificacao = classificacao;
      somaDasIdades += idade;
      qtdCampeoes++;
    }
  }

  exibe(campeoes, qtdCampeoes, ((float)somaDasIdades) / qtdCampeoes);

  return 0;
}