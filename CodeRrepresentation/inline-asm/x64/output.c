#include <stdio.h>

int plus(int a, int b) {
    asm volatile(
        "mov %edi, %eax;"
        "add %esi, %eax;");
}

int plusii(int a, int b) {
    int c = 0;
    asm volatile(
        "mov %1, %0;"
        "add %2, %0;"
        : "=r"(c)
        : "r"(a), "r"(b));
    return c;
}

int plusiii(int a, int b) {
    int c;
    asm volatile(
        "mov %1, %%eax;"
        "add %2, %%eax;"
        "add $1, %%eax;"
        "mov %%eax, %0;"
        : "=r"(c)
        : "r"(a), "r"(b));
    return c;
}

void plusiv(int a, int b) {
    asm volatile(
        "mov %0, %%eax;"
        "add %1, %%eax;"
        "pop %%rbp; ret;"
        : /* no ouput */
        : "r"(a), "r"(b));
}

int main(int argc, char *argv[]) {
    int a = 1;
    int b = 2;
    int c = 0;

    printf("%d + %d = %d\n", a, b, plus(a, b));
    printf("%d + %d = %d\n", a, b, plusii(a, b));
    printf("%d + %d + 1 = %d\n", a, b, plusiii(a, b));

    plusiv(a, b);   // return from eax
    asm volatile(
        "mov %%eax, %0;"
        : "=r"(c)
    );
    printf("%d + %d = %d\n", a, b, c);

    return 0;
}
