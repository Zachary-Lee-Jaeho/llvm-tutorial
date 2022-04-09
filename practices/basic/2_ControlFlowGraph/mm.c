#include <stdio.h>
#include <stdlib.h>

#define MATSIZE 512

int main () {
  int i, j, k;

  int a[MATSIZE][MATSIZE];
  int b[MATSIZE][MATSIZE];
  int c[MATSIZE][MATSIZE];
  
  for (i = 0; i < MATSIZE; i++) {
    for (j = 0; j < MATSIZE; j++) {
      a[i][j] = i;
      b[i][j] = j;
    }
  }
  
  // TODO: Optimize this loop
  for (i = 0; i < MATSIZE; i++) {
    for (k = 0; k < MATSIZE; k++) {
      for (j = 0; j < MATSIZE; j++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  return 0;
}
