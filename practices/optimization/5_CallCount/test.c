#include "stdio.h"

int add (int a, int b) {
  return a+b;
}

int mul (int a, int b) {
  int i;
  int acc = 0;
  for (i = 0; i < b; ++i) {
    acc = add(acc, a);
  }

  return acc;
}

int main () {
  int result = mul(10, 10);
  printf("Result: %d\n", result);
  return 0;
}


