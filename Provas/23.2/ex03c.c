#include <stdio.h>

int mediana(int a, int b, int c) {
  if ((a > b && a < c) || (a < b && a > c)) {
    return a;
  } else if ((b > a && b < c) || (b < a && b > c)) {
    return b;
  } else {
    return c;
  }
}

int main(void) {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  printf("%d", mediana(a, b, c));
  
  return 0;
}