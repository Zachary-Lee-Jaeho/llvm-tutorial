#include <stdio.h>

extern "C"
void traceMalloc(void *addr, size_t size) {
}

extern "C"
void traceLoad(void *addr, size_t size) {
}

extern "C"
void traceStore(void *addr, size_t size) {
}
