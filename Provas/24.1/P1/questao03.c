#include <stdio.h>

void exibeTipo(int percentual) {
  if (percentual < 40) {
    printf("Chocolate ao leite\n");
  } else if (percentual <= 50) {
    printf("Chocolate meio amargo\n");
  } else if (percentual <= 75) {
    printf("Chocolate amargo\n");
  } else {
    printf("Chocolate extra amargo\n");
  }
}

int main() {
  int codigo, percentual;

  do {
    printf("Código: ");
    scanf("%d", &codigo);
    if (codigo != 0) {
      printf("Percentual de cacau(ex: 75): ");
      scanf("%d", &percentual);
      exibeTipo(percentual);
    }
  } while (codigo != 0);

  return 0;
}