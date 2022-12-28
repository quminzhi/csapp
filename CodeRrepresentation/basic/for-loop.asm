
for-loop.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <forloop>:
long long forloop(long long n) {
  long long sum = 0;
  
  for (long long i = 0; i < n; i++) {
   0:	b8 00 00 00 00       	mov    $0x0,%eax   # i in rax
  long long sum = 0;
   5:	ba 00 00 00 00       	mov    $0x0,%edx   # sum in rdx
  for (long long i = 0; i < n; i++) {
   a:	eb 07                	jmp    13 <forloop+0x13>
    sum += i;
   c:	48 01 c2             	add    %rax,%rdx
  for (long long i = 0; i < n; i++) {
   f:	48 83 c0 01          	add    $0x1,%rax
  13:	48 39 f8             	cmp    %rdi,%rax
  16:	7c f4                	jl     c <forloop+0xc>
  }

  return sum;
}
  18:	48 89 d0             	mov    %rdx,%rax
  1b:	c3                   	retq   
