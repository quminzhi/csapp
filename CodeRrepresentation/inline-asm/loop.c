#include <stdio.h>

int sum_c(int n) {
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += i;   // m[sum] = %eax has been optimized. check asm code for details.
    }
    return sum;   // m[sum] = %eax when addition finished.
}

/**
 * @brief asm logic of loop
 *
 *      +--------+
 *      |  init  |
 *  +-> |--------| --+
 *  |   |  body  |   |
 *  |   |--------|   |
 *  |   |  add   |   |
 *  |   |--------| <-'
 *  |   |  cond  |
 *  `-- +--------+
 *
 * @param n
 * @return int
 */
int sum_asmi(int n) {
    int sum = 0;
    asm volatile(
        "xorl %%eax, %%eax;"
        "movl $0x0, %%ecx;"   // i
        "jmp Cond1;"
        "Loop1:"
        "addl %%ecx, %%eax;"
        "addl $0x1, %%ecx;"
        "Cond1:"
        "cmp %1, %%ecx;"
        "jle Loop1;"
        "movl %%eax, %0;"
        : "=r"(sum)
        : "r"(n)
        : "%eax", "%ecx");

    return sum;
}

int sum_asmii(int n) { return 0; }

int main(int argc, char *argv[]) {
    fprintf(stdout, "sum from 0 to 10 is %d\n", sum_c(10));
    fprintf(stdout, "sum from 0 to 10 is %d\n", sum_asmi(10));
    return 0;
}