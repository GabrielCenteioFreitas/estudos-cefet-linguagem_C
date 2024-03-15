// Autor: Gabriel Centeio Freitas
// Data: 14/03/2024
// Descrição: Programa que calcula o dígito verificador de um CPF e retorna o CPF completo

#include <stdio.h>

int calculaDV(int cpf) {
  int cpf_copia, soma1 = 0, soma2 = 0, dv1 = 0, dv2 = 0, dv;
  cpf_copia=cpf;

  for (int i=9;i>0;i--){
    soma1+=(cpf_copia%10)*i;
    soma2+=(cpf_copia%10)*(i-1);
    cpf_copia/=10;
  }

  dv1 = soma1%11;
  if (dv1==10) {
    dv1=0;
  }
  soma2+=dv1*9;
  dv2 = soma2%11;
  if (dv2==10) {
    dv2=0;
  }

  dv = dv1*10 + dv2;
  return dv;
}

int main(void) {
  int cpf, dv;
  printf("Insira o CPF: ");
  scanf("%d", &cpf);

  dv = calculaDV(cpf);
  
  printf("\nO CPF é: %d.%d.%d-%d", cpf/1000000, (cpf/1000)%1000, cpf%1000, dv);
    
  return 0;
}