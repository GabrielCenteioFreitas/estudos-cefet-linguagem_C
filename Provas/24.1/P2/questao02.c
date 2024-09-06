#include <stdio.h>
#include <string.h>

int obterIndice(char ufs[][3], char uf[]) {
  for (int i = 0; i < 27; i++) {
    if (strcmp(ufs[i], uf) == 0) {
      return i;
    }
  }
  return -1;
}

void leDadosETotaliza(int contadores[][27], char ufs[][3]) {
  char uf[3];
  int ano, peso, indice_uf;
  do {
    scanf(" %s", uf);
    indice_uf = obterIndice(ufs, uf);
    if (indice_uf != -1) {
      scanf("%d", &ano);
      scanf("%d", &peso);
      if (peso < 2500) {
        contadores[ano-2010][indice_uf]++;
      }
    }
  } while (indice_uf != -1);
}

void apresentaDadosDeUmAno(int contadores[][27], char ufs[][3], int ano) {
  for (int i = 0; i < 27; i++) {
    printf("%s: %d\n", ufs[i], contadores[ano-2010][i]);
  }
}

void apresentaDadosPorUF(int contadores[][27], char ufs[][3], char uf[]) {
  int indice = obterIndice(ufs, uf), total = 0;
  for (int i = 0; i < 14; i++) {
    printf("%d: %d\n", i+2010, contadores[i][indice]);
    total += contadores[i][indice];
  }
  printf("Total: %d\n", total);
}

int main() {
  char ufs[][3] = {
    "AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA", 
    "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN", 
    "RS", "RO", "RR", "SC", "SP", "SE", "TO"
  };

  int contadores[14][27];
  for (int i = 0; i < 14; i++) {
    for (int j = 0; j < 27; j++) {
      contadores[i][j] = 0;
    }
  }

  leDadosETotaliza(contadores, ufs);

  int ano_solicitado;
  scanf("%d", &ano_solicitado);
  apresentaDadosDeUmAno(contadores, ufs, ano_solicitado);

  char uf_solicitada[3];
  scanf(" %s", uf_solicitada);
  apresentaDadosPorUF(contadores, ufs, uf_solicitada);

  return 0;
}