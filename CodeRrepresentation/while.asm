
while.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <fact>:
long fact(long n) {
  long result = 1;
   0:	b8 01 00 00 00       	mov    $0x1,%eax
  while (n > 1) {
   5:	eb 08                	jmp    f <fact+0xf>
    result *= n;
   7:	48 0f af c7          	imul   %rdi,%rax
    n = n - 1;
   b:	48 83 ef 01          	sub    $0x1,%rdi
  while (n > 1) {
   f:	48 83 ff 01          	cmp    $0x1,%rdi
  13:	7f f2                	jg     7 <fact+0x7>
  }

  return result;
}
  15:	c3                   	retq   
