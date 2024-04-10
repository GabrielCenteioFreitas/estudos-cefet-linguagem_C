#include <stdio.h>

int leDadosResidencia(num_moradores) {
  int qntd_comodos, idade, qntd_menores = 0, maior_idade;

  printf("Quantos cômodos? ");
  scanf("%d", &qntd_comodos);

  for (int i = 0; i < num_moradores; i++) {
    printf("Idade do morador %d: ", i);
    scanf("%d", &idade);
    if(i == 0 || idade > maior_idade) {
      maior_idade = idade;
    }
    if (idade < 18) {
      qntd_menores++;
    }
  }
  printf("Qntd menores: %d\n", qntd_menores);
  printf("Maior idade: %d\n", maior_idade);
  return qntd_comodos;
}

int main() {
  int qntd_moradores, total_casas = 0, casas_mais_que_3 = 0, num_comodos;

  do {
    printf("Qntd moradores: ");
    scanf("%d", &qntd_moradores);
    if(qntd_moradores != 0) {
      num_comodos = leDadosResidencia(qntd_moradores);
      if(num_comodos > 3) {
        casas_mais_que_3++;
      }
      total_casas++;
    }
  } while (qntd_moradores != 0);

  printf("Total visitado: %d\n", total_casas);
  printf("Casas com mais de 3 cômodos: %d", casas_mais_que_3);

  return 0;
}