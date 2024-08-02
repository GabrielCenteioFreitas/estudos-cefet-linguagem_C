#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
  #define CLEAR "cls"
#else
  #define CLEAR "clear"
#endif

void clearTerminal() {
  system(CLEAR);
}

int elementoIntEstaNoArray(int tamanho, int elemento, int array[]) {
  for (int i = 0; i < tamanho; i++) {
    if (array[i] == elemento) {
      return 1;
    }
  }

  return 0;
}

int elementoStringEstaNoArray(int tamanho1, int tamanho2, char elemento[tamanho1], char array[tamanho1][tamanho2]) {
  for (int i = 0; i < tamanho1; i++) {
    if (strcmp(array[i], elemento) == 0) {
      return 1;
    }
  }

  return 0;
}

int arrayIntEstaNoArray(int tamanho1, int tamanho2, int elemento[tamanho2], int array[tamanho1][tamanho2]) {
  for (int i = 0; i < tamanho1; i++) {
    if (array[i][0] == elemento[0] && array[i][1] == elemento[1]) {
      return 1;
    }
  }

  return 0;
}

int arraysIntSaoIguais(int tamanho, int array1[tamanho], int array2[tamanho]) {
  for (int i = 0; i < tamanho; i++) {
    if (array1[i] != array2[i]) {
      return 0;
    }
  }

  return 1;
}

int stringsSaoIguais(char str1[], char str2[]) {
  return (strcmp(str1, str2) == 0);
}

void definirStringIgualAString(char strEsquerda[], char strDireita[]) {
  strcpy(strEsquerda, strDireita);
}