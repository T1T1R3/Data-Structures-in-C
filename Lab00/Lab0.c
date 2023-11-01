#include <stdio.h>

typedef enum { true, false } bool;

int sum(int a) {
  int sumN = 0;
  ;
  for (int i = 1; i < a; i++) {
    if (a % i == 0) {
      sumN += i;
    }
  }
  return sumN;
}

bool verify(int a, int b) {
  int sumA = sum(a);
  int sumB = sum(b);
  if (sumA == b && sumB == a)
    return true;
  else
    return false;
}

int main() {
  int a, b;

  scanf("%d %d", &a, &b);
  if (a < 1 || a > 20000 || b < 1 || b > 20000) {
    return 0;
  } else {
    if (verify(a, b) == true)
      printf("amigos\n");
    else
      printf("nao amigos\n");
    return 0;
  }
}