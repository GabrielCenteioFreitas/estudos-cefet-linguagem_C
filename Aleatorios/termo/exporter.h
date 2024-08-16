#ifndef EXPORTER_H
#define EXPORTER_H

void clearTerminal();
int elementoIntEstaNoArray(int tamanho, int elemento, int array[tamanho]);
int arrayIntEstaNoArray(int tamanho1, int tamanho2, int elemento[tamanho2], int array[tamanho1][tamanho2]);
int elementoStringEstaNoArray(int tamanho1, int tamanho2, char elemento[tamanho2], char array[tamanho1][tamanho2]);
int arraysIntSaoIguais(int tamanho, int array1[tamanho], int array2[tamanho]);

void sortearPalavra(char palavra[6]);

#endif