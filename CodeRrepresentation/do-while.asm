
do-while.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <fact>:
# n in %rdi
long fact(long n) {
  long result = 1;
   0:	b8 01 00 00 00       	mov    $0x1,%eax
  
  do {
    result *= n;
   5:	48 0f af c7          	imul   %rdi,%rax
    n = n - 1;
   9:	48 83 ef 01          	sub    $0x1,%rdi
  } while (n > 1);
   d:	48 83 ff 01          	cmp    $0x1,%rdi
  # 0xf2 = 242 - 256 = -14 + 0x13 (19) = 5
  11:	7f f2                	jg     5 <fact+0x5>

  return result;
}
  13:	c3                   	retq   
