#include <stdio.h>
#include <stdlib.h>

int recur(int i);

volatile int stuff = 7; // static data

int main(int argc, char *argv[]) {
    volatile int i = 0; // stack variable

    volatile char *buf1 = malloc(100); // heap
    volatile char *buf2 = malloc(100); // heap

    printf("_main @ %p\n", (void*)main);
    printf("recur @ %p\n", (void*)recur);
    printf("_main stack: %p\n", (void*)&i);
    printf("static data: %p\n", (void*)&stuff);
    printf("Heap: malloc 1: %p\n", (void*)buf1);
    printf("Heap: malloc 2: %p\n", (void*)buf2);

    recur(3);
    return 0;
}

int recur(int i) {
    volatile int x = 0;
    printf("recur call %d: stack@ %p\n", i, (void*)&x);
    if (i > 0) recur(i-1);
    return 0;
}