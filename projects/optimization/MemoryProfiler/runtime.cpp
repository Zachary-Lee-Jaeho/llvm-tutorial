#include <stdio.h>

extern "C"
void traceMalloc(void *addr, size_t size) {
    //========--------  Answer --------==========
    printf("[Memory Allocation] Addr: %p Size: %zu\n", addr, size);
    //========--------  Answer --------==========
}

extern "C"
void traceLoad(void *addr, size_t size) {
    //========--------  Answer --------==========
    printf("[Load] Addr: %p Size: %zu\n", addr, size);
    //========--------  Answer --------==========
}

extern "C"
void traceStore(void *addr, size_t size) {
    //========--------  Answer --------==========
    printf("[Store] Addr: %p Size: %zu\n", addr, size);
    //========--------  Answer --------==========
}

