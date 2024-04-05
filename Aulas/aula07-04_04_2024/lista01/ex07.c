#include <stdio.h>

void calcularQntdCelulas(int valor) {
  int qntdCedulas100 = valor/100;
  int qntdCedulas50 = (valor%100)/50;
  int qntdCedulas20 = (valor%100%50)/20;
  int qntdCedulas10 = (valor%100%50%20)/10;
  int qntdCedulas5 = (valor%100%50%20%10)/5;
  int qntdCedulas2 = (valor%100%50%20%10%5)/2;
  int qntdCedulas1 = valor%2;

  printf("\nA quantidade de cédulas é:\n");
  if(qntdCedulas100 != 0) {
    printf("%d nota(s) de R$100.00\n", qntdCedulas100);
  }
  if(qntdCedulas50 != 0) {
    printf("%d nota(s) de R$50.00\n", qntdCedulas50);    
  }
  if(qntdCedulas20 != 0) {
    printf("%d nota(s) de R$20.00\n", qntdCedulas20);    
  }
  if(qntdCedulas10 != 0) {
    printf("%d nota(s) de R$10.00\n", qntdCedulas10);    
  }
  if(qntdCedulas5 != 0) {
    printf("%d nota(s) de R$5.00\n", qntdCedulas5);    
  }
  if(qntdCedulas2 != 0) {
    printf("%d nota(s) de R$2.00\n", qntdCedulas2);    
  }
  if(qntdCedulas1 != 0) {
    printf("%d nota(s) de R$1.00\n", qntdCedulas1);    
  }
}

int main() {
  int valor;

  printf("Digite o valor a ser sacado: ");
  scanf("%d", &valor);

  calcularQntdCelulas(valor);  
  
  return 0;
}