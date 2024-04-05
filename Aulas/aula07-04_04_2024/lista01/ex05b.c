#include <stdio.h>

int calculaValor(int horas, int minutos) {
  return (horas*60)+minutos;
}

int main() {
  int horas_previsao, minutos_previsao, horas_chegada, minutos_chegada;
  
  printf("Digite as horas do horário previsto de chegada: ");
  scanf("%d", &horas_previsao);  
  printf("Digite os minutos do horário previsto de chegada: ");
  scanf("%d", &minutos_previsao);  
  printf("\nDigite as horas do horário efetivo de chegada: ");
  scanf("%d", &horas_chegada);  
  printf("Digite os minutos do horário efetivo de chegada: ");
  scanf("%d", &minutos_chegada);

  printf("\nA diferença foi de %d minutos", calculaValor(horas_chegada, minutos_chegada)-calculaValor(horas_previsao, minutos_previsao));
  
  return 0;
}