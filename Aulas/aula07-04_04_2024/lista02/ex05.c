#include <stdio.h>

float calcula_media(float num1, float num2) {
  return (num1 + num2)/2;
}

int main() {
  int matricula;
  float nota_prova1, nota_prova2, nota_trab1, nota_trab2,
        media_provas, media_trabs, media_final;

  printf("Insira a matrícula do aluno: ");
  scanf("%d", &matricula);
  printf("Insira a nota da primeira prova: ");
  scanf("%f", &nota_prova1);
  printf("Insira a nota da segunda prova: ");
  scanf("%f", &nota_prova2);
  printf("Insira a nota do primeiro trabalho: ");
  scanf("%f", &nota_trab1);
  printf("Insira a nota do segundo trabalho: ");
  scanf("%f", &nota_trab2);

  media_provas = calcula_media(nota_prova1, nota_prova2);
  media_trabs = calcula_media(nota_trab1, nota_trab2);
  media_final = calcula_media(media_provas, media_trabs);

  printf("\nA matrícula do aluno é: %d", matricula);
  printf("\nA média das provas é: %.2f", media_provas);
  printf("\nA média dos trabalhos é: %.2f", media_trabs);
  printf("\nA média final é: %.2f", media_final);

  
  return 0;
}