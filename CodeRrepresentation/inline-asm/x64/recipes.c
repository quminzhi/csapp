#include <stdint.h>
#include <stdio.h>

void add_asm() {
    int a = 1;
    int b = 2;
    asm volatile("addl %%ebx, %%eax;"
                 : "=a"(a)   // a: %eax
                 : "0"(a),   // 0: same as 0th operand,
                   "b"(b)    // b: %ebx
    );
    fprintf(stdout, "1 + 2 = %d\n", a);
}

void add_asm_atomic() {
    int a = 1;
    int b = 2;
    asm volatile(
        "lock;"   // lock to achieve atomic opt
        "addl %1, %0;"
        : "+m"(a)
        : "r"(b));
    fprintf(stdout, "1 + 2 = %d\n", a);
}

void check_zero() {
    uint32_t a = 1;
    uint8_t cond = 0;   // false
    asm volatile(
        "lock;"
        "decl %0;"
        "sete %1;"              // set if zero flag (ZF) is set
        : "+m"(a), "=q"(cond)   // q: eax, ebx, ecx, edx
        :                       // a is readable and writeable
        : "memory"              // inform of gcc that content of memory may be changed
    );
    if (cond) {
        fprintf(stdout, "a becomes 0\n");
    }
}

void multiply_asm() {
    /* without overwriting inputs */
    int x = 1;
    int x_mul_5;
    asm volatile("lea (%1, %1, 4), %0;"   // 1 + 1 * 4
                 : "=r"(x_mul_5)
                 : "r"(x));
    fprintf(stdout, "%d multiplied by 5 is %d\n", x, x_mul_5);

    /* overwrite input */
    int b = 1;
    asm volatile("lea (%0, %0, 4), %0;"   // 1 + 1 * 4
                 : "+r"(b));
    fprintf(stdout, "1 multiplied by 5 is %d\n", b);
}

void bit_set_clear() {
    uint32_t val = 0b0101;
    uint32_t *addr = &val;
    fprintf(stdout, "before: addr = %lx, val = %x\n", (uint64_t)addr, val);
    uint32_t pos = 0;   // set 0th bit to 1 and others 0
    asm volatile(
        "btsl %1, %0;"   // store selected bit in CF flag and set
        // "btrl %1, %0;"   // store selected bit in CF flag and unset
        : "=b"(val)
        : "Ic"(pos)   // Ir: pos is in a register, and it’s value ranges from 0-31
        : "cc");      // condition codes will be changed
    fprintf(stdout, "after: addr = %lx, val = %o\n", (uint64_t)addr, val);
}

static inline char *strcpy(char *dst, char *src) {   // edi, esi
    uint64_t d0, d1, d2;
    asm volatile(
        "1: lodsb;"           // load byte at address DS:(E)SI into AL.
        "stosb;"              // store AL (1 byte) at address DST:(E)DI or RDI.
        "testb %%al, %%al;"   // ZF = 1 if equal, 0 otherwise.
        "jne 1b;"
        : "=&S"(d0), "=&D"(d1), "=&a"(d2)   // S: esi, D: edi, a: eax, &: clobbered regs
        : "0"(src), "1"(dst));

    return dst;
}

/**
 * ASM function in macro form:
 * - clear direction flag (DF), when the DF flag is set to 0, string operations increment
 * the index registers (ESI and/or EDI),
 * - movsl: move dword (4-byte) string for ecx times
 */

#define mov_blk(src, dst, numwords)         \
    asm volatile(                           \
        "cld;"                              \
        "rep;"                              \
        "movsl;"                            \
        :                                   \
        : "S"(src), "D"(dst), "c"(numwords) \
        : "%ecx", "%edi", "%esi");

/**
 * how syscall in linux is defined:
 * - eax, ebx, ecx, edx are used as inputs to invoke a syscall.
 * - return value is collected with eax.
 */
#define _syscall3(type, name, type1, arg1, type2, arg2, type3, arg3)               \
    type name(type1 arg1, type2 arg2, type3 arg3) {                                \
        long __res;                                                                \
        __asm__ volatile("int $0x80"                                               \
                         : "=a"(__res)                                             \
                         : "0"(__NR_##name), "b"((long)(arg1)), "c"((long)(arg2)), \
                           "d"((long)(arg3)));                                     \
        __syscall_return(type, __res);                                             \
    }

int main(int argc, char *argv[]) {
    add_asm();
    add_asm_atomic();
    check_zero();
    multiply_asm();
    bit_set_clear();

    char src[] = "abc";
    char dst[] = "";
    char *ret = strcpy(dst, src);
    fprintf(stdout, "dst = %s\n", ret);

    // return 0;
    asm volatile(
        "movl $1,%eax;"    // symbol of sys_exit is 1
        "xorl %ebx,%ebx;" // exit value is in ebx, it is 0
        "int  $0x80;"        // invoke syscall
    );
}