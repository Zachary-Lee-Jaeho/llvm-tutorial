#include <stdio.h>
#include <stdlib.h>

#define MALLOC_SIZE 10

int main () {
    int *mat = (int *) malloc(MALLOC_SIZE);
    
    for (int i = 0; i < MALLOC_SIZE; i++) {
        mat[i] = rand();
    }

    for (int i = 0; i < MALLOC_SIZE; i++) {
        printf("%p\n", &mat[i]);
    }

    return 0;
}


