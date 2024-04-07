#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

int exibirMenu() {
  int escolha;

  system(CLEAR);
  printf("[1] Questão 1\n    - Gabarito não confirmado, mas encontrado igual por 3 pessoas\n\n");
  printf("[2] Questão 2\n    - Gabarito não confirmado, mas encontrado igual por 2 pessoas\n\n");
  printf("[3] Questão 3\n    - Gabarito da letra A não confirmado\n    - Gabarito da letra B confirmado\n\n");
  printf("[4] Questão 4\n    - Gabarito não confirmado\n\n");
  printf("[5] Questão 5\n    - Gabarito confirmado\n\n");
  printf("[6] Questão 6\n    - Gabarito não confirmado\n    - Vc precisa ter resolvido o sistema antes para a letra A\n\n");
  printf("\nQual questão deseja resolver? ");
  scanf("%d", &escolha);

  return escolha;
}

void sair() {
  char saida;

  printf("\n\nInsira qualquer caractere para voltar: ");  
  scanf(" %c", &saida);
}

void exibirAviso() {
  printf("--- IMPORTANTE ---\n\nInsira as coordenadas no formato X Y Z\nCaso haja uma fração, realize a divisão e insira o número com ponto (ex: 1.5)\nCaso seja uma dízima periódica, insira pelo menos 5 casas decimais para garantir a precisão (ex: 0.13333)\n\n------------------\n\n");
}

float calcularNorma(float ponto[], int tamanho) {
  float soma = 0;
  
  for (int i = 0; i < tamanho; i++) {
    soma += pow(ponto[i], 2);
  }
  
  return sqrt(soma);
}

void calcularProdutoVetorial(float coords1[], float coords2[], float produto_vetorial[]) {
  float i, j, k;  
  i = (coords1[1]*coords2[2])-(coords1[2]*coords2[1]);
  j = (coords1[2]*coords2[0])-(coords1[0]*coords2[2]);
  k = (coords1[0]*coords2[1])-(coords1[1]*coords2[0]);
  
  produto_vetorial[0] = i;
  produto_vetorial[1] = j;
  produto_vetorial[2] = k;
}

float calcularProdutoMisto(float coords1[], float coords2[], float coords3[]) {
  float produto_misto;

  produto_misto = (
    (coords1[1]*coords2[2]*coords3[0]) +
    (coords1[0]*coords2[1]*coords3[2]) +
    (coords1[2]*coords2[0]*coords3[1])
  ) - (
    (coords1[1]*coords2[0]*coords3[2]) +
    (coords1[2]*coords2[1]*coords3[0]) +
    (coords1[0]*coords2[2]*coords3[1])
  );

  return produto_misto;
}

float calcularProdutoInterno(float coords1[], float coords2[], int tamanho) {
  float produto_interno = 0;

  for (int i = 0; i < tamanho; i++) {
    produto_interno += coords1[i] * coords2[i];
  }

  return produto_interno;
}

void calcularProdutoPorUmEscalar(float escalar, float coords[], float resultado[], int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    resultado[i] = coords[i] * escalar;
  }
}

void calcularAB(float coordsA[], float coordsB[], float coordsAB[] , int tamanho) {
  for (int i = 0; i < tamanho; i++) {
      coordsAB[i] = coordsB[i] - coordsA[i];
  }
}

void calcularProjecao(float coordsU[], float coordsV[], float projecao[], int tamanho) {
  float produto_intero_UV = calcularProdutoInterno(coordsU, coordsV, tamanho),
        produto_intero_UU = calcularProdutoInterno(coordsU, coordsU, tamanho),
        escalar = produto_intero_UV / produto_intero_UU;

  calcularProdutoPorUmEscalar(escalar, coordsU, projecao, tamanho);
}

float calcularDistancia(float N[], float ponto[], int tamanho) {
  float distancia, numerador = 0, denominador = 0;
  
  for (int i = 0; i < tamanho; i++) {
    if (i == tamanho-1) {
      numerador += N[i];
    } else {
      numerador += N[i]*ponto[i];
      denominador += pow(N[i], 2);
    }
  }

  if (numerador < 0) {
    numerador *= -1;
  }

  distancia = numerador/sqrt(denominador);
  return distancia;
}

float converterRadParaGraus(float rad) {
  float graus;
  graus = rad * (180/3.14159);
  return graus;
}

void resolverQuestao1() {
  float n;
  
  system(CLEAR);
  printf("Na questão está escrito que:\nAX = N.XB\n\nInsira o valor de \"N\": ");
  scanf("%f", &n);

  printf("\n\nA resposta é: %.3f", 1/(1+n));
  
  sair();
}

void resolverQuestao2() {
  float pontoA[3] = {}, pontoB[3] = {}, pontoC[3] = {},
        pontoAlinha[3] = {}, pontoBlinha[3] = {},
        produto_vetorial[3] = {},
        area_do_triangulo;

  system(CLEAR);
  exibirAviso();
  printf("Coordenadas do Ponto A: ");
  scanf("%f %f %f", &pontoA[0], &pontoA[1], &pontoA[2]);
  printf("Coordenadas do Ponto B: ");
  scanf("%f %f %f", &pontoB[0], &pontoB[1], &pontoB[2]);
  printf("Coordenadas do Ponto C: ");
  scanf("%f %f %f", &pontoC[0], &pontoC[1], &pontoC[2]);

  pontoAlinha[0] = pontoA[0] + pontoB[0];
  pontoAlinha[1] = pontoA[1] + pontoB[1];
  pontoAlinha[2] = pontoA[2] + pontoB[2];
  pontoBlinha[0] = pontoB[0] + pontoC[0];
  pontoBlinha[1] = pontoB[1] + pontoC[1];
  pontoBlinha[2] = pontoB[2] + pontoC[2];

  calcularProdutoVetorial(pontoAlinha, pontoBlinha, produto_vetorial);

  area_do_triangulo = calcularNorma(produto_vetorial, 3)/2;
  
  printf("\n\nA resposta é: %.3f", area_do_triangulo*2);

  sair();
}

void resolverQuestao3() {
  int tamanho;
  float pontoA[3] = {}, pontoB[3] = {}, pontoC[3] = {},
        pontoAlinha[3] = {}, pontoBlinha[3] = {}, pontoClinha[3] = {},
        pontoN[3] = {}, pontoNcomD[4] = {},
        distancia, volume;

  system(CLEAR);
  exibirAviso();
  printf("Coordenadas do Ponto A: ");
  scanf("%f %f %f", &pontoA[0], &pontoA[1], &pontoA[2]);
  printf("Coordenadas do Ponto B: ");
  scanf("%f %f %f", &pontoB[0], &pontoB[1], &pontoB[2]);
  printf("Coordenadas do Ponto C: ");
  scanf("%f %f %f", &pontoC[0], &pontoC[1], &pontoC[2]);

  pontoAlinha[0] = pontoA[0] + pontoB[0];
  pontoAlinha[1] = pontoA[1] + pontoB[1];
  pontoAlinha[2] = pontoA[2] + pontoB[2];
  
  pontoBlinha[0] = pontoB[0] + pontoC[0];
  pontoBlinha[1] = pontoB[1] + pontoC[1];
  pontoBlinha[2] = pontoB[2] + pontoC[2];
  
  pontoClinha[0] = pontoA[0] + pontoC[0];
  pontoClinha[1] = pontoA[1] + pontoC[1];
  pontoClinha[2] = pontoA[2] + pontoC[2];

  calcularProdutoVetorial(pontoAlinha, pontoBlinha, pontoN);

  pontoNcomD[0] = pontoN[0];
  pontoNcomD[1] = pontoN[1];
  pontoNcomD[2] = pontoN[2];
  pontoNcomD[3] = pontoN[0]*pontoAlinha[0] + pontoN[1]*pontoAlinha[1] + pontoN[2]*pontoAlinha[2];

  distancia = calcularDistancia(pontoNcomD, pontoClinha, 4);
  
  printf("\n\nA resposta da letra A é: %.2f", distancia);
  
  volume = calcularProdutoMisto(pontoA, pontoB, pontoC);
  printf("\n\nA resposta da letra B é: %.2f", volume);

  sair();
}

void resolverQuestao4() {
  float pontoA[4] = {}, pontoB[4] = {},
        normaB, normaA, X, Y, a;

  system(CLEAR);
  exibirAviso();
  printf("UM FATOR CRUCIAL:\nNa questão, o valor de X de A deve ser 1 e o Y -1\nNa questão, o valor de X de B deve ser -1 e o Y 3\nCaso isso não seja verdade, a resposta exibida aqui estará incorreta\n\n");
  printf("Coordenadas do Ponto A: ");
  scanf("%f %f %f %f", &pontoA[0], &pontoA[1], &pontoA[2], &pontoA[3]);
  printf("Coordenadas do Ponto B: ");
  scanf("%f %f %f %f", &pontoB[0], &pontoB[1], &pontoB[2], &pontoB[3]);

  normaA = calcularNorma(pontoA, 4);
  normaB = calcularNorma(pontoB, 4);
  X = (normaB-normaA)/(normaB+normaA);
  Y = ((3*normaA)-normaB)/(normaB+normaA);
  a = ((X+Y)/2)+X;

  printf("\n\nA resposta é: %.3f", a);

  sair();
}

void resolverQuestao5() {
  float pontoA[4] = {}, pontoB[4] = {}, pontoP[4] = {},
        pontoAB[4] = {}, pontoAP[4] = {}, pontoAQ[4] = {},
        pontoQ[4] = {};

  system(CLEAR);
  exibirAviso();
  printf("Coordenadas do Ponto A: ");
  scanf("%f %f %f %f", &pontoA[0], &pontoA[1], &pontoA[2], &pontoA[3]);
  printf("Coordenadas do Ponto B: ");
  scanf("%f %f %f %f", &pontoB[0], &pontoB[1], &pontoB[2], &pontoB[3]);
  printf("Coordenadas do Ponto P: ");
  scanf("%f %f %f %f", &pontoP[0], &pontoP[1], &pontoP[2], &pontoP[3]);  

  calcularAB(pontoA, pontoB, pontoAB, 4);
  calcularAB(pontoA, pontoP, pontoAP, 4);
  
  calcularProjecao(pontoAB, pontoAP, pontoAQ, 4);

  for (int i = 0; i < 4; i++) {
    pontoQ[i] = pontoAQ[i]+pontoA[i];
  }

  printf("\n\nA resposta é:\nQ(%.3f, %.3f, %.3f, %.3f)", pontoQ[0], pontoQ[1], pontoQ[2], pontoQ[3]);

  sair();
}

void resolverQuestao6() {
  float vetorV[3] = {}, vetorK[3] = {},
        vetorPlano1[3] = {}, vetorPlano2[3] = {}, dPlano1, dPlano2,
        anguloRetasEmRad, anguloRetasEmGraus,
        anguloPlanosEmRad, anguloPlanosEmGraus;

  system(CLEAR);
  exibirAviso();
  printf("Para a resolução da letra A, é preciso que você já tenho resolvido o sistema e encontrado o vetor diretor da reta\n");
  printf("Insira as coordenadas do vetor diretor: ");
  scanf("%f %f %f", &vetorV[0], &vetorV[1], &vetorV[2]);
  printf("Insira as coordenadas do vetor K: ");
  scanf("%f %f %f", &vetorK[0], &vetorK[1], &vetorK[2]);

  anguloRetasEmRad = acosf(
      calcularProdutoInterno(vetorV, vetorK, 3) /
      (calcularNorma(vetorV, 3)*calcularNorma(vetorK, 3))
  );
  anguloRetasEmGraus = converterRadParaGraus(anguloRetasEmRad);

  printf("\nA resposta da letra A é: %.2f°\n\n\n", anguloRetasEmGraus);
  
  printf("Agora vamos para a letra B\nNa questão temos:\nS: { A.x + B.y + C.z = D\n   { E.x + F.y + G.z = H\n\n");
  printf("Insira os valores de A B C D: ");
  scanf("%f %f %f %f", &vetorPlano1[0], &vetorPlano1[1], &vetorPlano1[2], &dPlano1);
  printf("Insira os valores de E F G H: ");
  scanf("%f %f %f %f", &vetorPlano2[0], &vetorPlano2[1], &vetorPlano2[2], &dPlano2);

  anguloPlanosEmRad = acosf(
      calcularProdutoInterno(vetorPlano1, vetorPlano2, 3) /
      (calcularNorma(vetorPlano1, 3)*calcularNorma(vetorPlano2, 3))
  );
  anguloPlanosEmGraus = converterRadParaGraus(anguloPlanosEmRad);
  
  printf("\nA resposta da letra B é: %.2f°\n", anguloPlanosEmGraus);

  sair();
}

int main() {
  int escolha;

  do {
    escolha = exibirMenu();

    switch (escolha) {
      case 1:
        resolverQuestao1();
        break;
      case 2:
        resolverQuestao2();
        break;
      case 3:
        resolverQuestao3();
        break;
      case 4:
        resolverQuestao4();
        break;
      case 5:
        resolverQuestao5();
        break;
      case 6:
        resolverQuestao6();
        break;
      default:
        break;
    }
  } while (escolha >= 1 && escolha <= 6);
  
  return 0;
}