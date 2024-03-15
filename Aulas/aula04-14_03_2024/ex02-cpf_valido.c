// Autor: Gabriel Centeio Freitas
// Data: 14/03/2024
// Descrição: Programa que verifica a validade de um CPF

#include <stdio.h>

int calculaDV(long long cpf) {
  int soma1 = 0, soma2 = 0, dv1 = 0, dv2 = 0, dv=0;
  long long cpf_copia;
  cpf_copia=cpf;

  for (int i=9;i>0;i--){
    soma1+=(cpf_copia%10)*i;
    soma2+=(cpf_copia%10)*(i-1);
    cpf_copia/=10;
  }

  dv1 = soma1%11;
  if (dv1==10){
    dv1=0;
  }
  soma2+=dv1*9;
  dv2 = soma2%11;
  if (dv2==10){
    dv2=0;
  }

  dv = dv1*10+dv2;
  return dv;
}

int validaCPF(long long cpf, long long cpf_sem_DV) {
  return calculaDV(cpf_sem_DV) == cpf%100;
}

int main() {
  long long cpf, cpf_sem_DV;
  printf("Insira o CPF: ");
  scanf("%lld", &cpf);
  cpf_sem_DV = cpf/100;

  if(validaCPF(cpf, cpf_sem_DV) == 1){
    printf("\nO CPF %lld.%lld.%lld-%lld é válido", cpf_sem_DV/1000000, (cpf_sem_DV/1000)%1000, cpf_sem_DV%1000, cpf%100);
  }
  else {
    printf("\nO CPF %lld.%lld.%lld-%lld NÃO é válido", cpf_sem_DV/1000000, (cpf_sem_DV/1000)%1000, cpf_sem_DV%1000, cpf%100);
  }

  return 0;
}