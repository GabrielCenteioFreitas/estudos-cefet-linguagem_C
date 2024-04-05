#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

float calcularAreaTrapezio() {
  float base_maior, base_menor, altura;

  printf("Digite o valor da base maior: ");
  scanf("%f", &base_maior);
  printf("Digite o valor da base menor: ");
  scanf("%f", &base_menor);
  printf("Digite o valor da altura: ");
  scanf("%f", &altura);

  return ((base_maior+base_menor)*altura)/2;
}

float calcularAreaTriangulo() {
  float base, altura;

  printf("Digite o valor da base: ");
  scanf("%f", &base);
  printf("Digite o valor da altura: ");
  scanf("%f", &altura);

  return (base*altura)/2;
}

float calcularAreaRetangulo() {
  float base, altura;

  printf("Digite o valor da base: ");
  scanf("%f", &base);
  printf("Digite o valor da altura: ");
  scanf("%f", &altura);

  return base*altura;
}

float calcularAreaQuadrado() {
  float lado;

  printf("Digite o valor do lado do quadrado: ");
  scanf("%f", &lado);

  return lado*lado;
}

int exibirMenu() {
  int escolha;

  system(CLEAR);
  printf("[1] Quadrado\n[2] Retângulo\n[3] Triângulo\n[4] Trapézio\n[5] Fim\n\nEscolha uma opção: ");
  scanf("%d", &escolha);
  
  return escolha;
}

int main() {
  int escolha;
  float area;
  char saida;

  do {
    escolha = exibirMenu();

    system(CLEAR);
    switch (escolha) {
      case 1:
        area = calcularAreaQuadrado();
        break;
      case 2:
        area = calcularAreaRetangulo();
        break;
      case 3:
        area = calcularAreaTriangulo();
        break;
      case 4:
        area = calcularAreaTrapezio();
        break;
      default:
        break;    
    }    

    if (escolha > 1 && escolha < 5) {
      printf("\nA área do polígono é: %.2f\n", area);
      printf("\nInsira qualquer caractere para sair: ");
      scanf(" %c", &saida);
    }
    
  } while (escolha > 1 && escolha < 5);
  
  return 0;
}