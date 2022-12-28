
scale.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <scale>:
# x in rdi, y in rsi, z in rdx
long scale(long x, long y, long z) {
  long t = x + 4 * y + 12 * z;
   0:	48 8d 04 b7          	lea    (%rdi,%rsi,4),%rax
   4:	48 8d 14 52          	lea    (%rdx,%rdx,2),%rdx
   8:	48 8d 04 90          	lea    (%rax,%rdx,4),%rax
  return t;
}
   c:	c3                   	retq   
