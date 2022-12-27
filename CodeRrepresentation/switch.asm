
switch.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <switch_eg>:
void switch_eg(long x, long n, long *dest) {
  long val = x;
  switch (n) {
   0:	48 83 ee 64          	sub    $0x64,%rsi
   4:	48 83 fe 06          	cmp    $0x6,%rsi
   8:	77 2c                	ja     36 <switch_eg+0x36>
   a:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # 11 <switch_eg+0x11>
  11:	48 63 04 b1          	movslq (%rcx,%rsi,4),%rax
  15:	48 01 c8             	add    %rcx,%rax
  18:	ff e0                	jmpq   *%rax
  case 100:
    val *= 13;
  1a:	48 8d 04 7f          	lea    (%rdi,%rdi,2),%rax
  1e:	48 8d 3c 87          	lea    (%rdi,%rax,4),%rdi
    break;
  22:	eb 08                	jmp    2c <switch_eg+0x2c>
  case 102:
    val += 10;
  24:	48 83 c7 0a          	add    $0xa,%rdi
    // fall through
  case 103:
    val += 11;
  28:	48 83 c7 0b          	add    $0xb,%rdi
    break;
  default:
    val = 0;
  }

  *dest = val;
  2c:	48 89 3a             	mov    %rdi,(%rdx)
}
  2f:	c3                   	retq   
    val *= val;
  30:	48 0f af ff          	imul   %rdi,%rdi
    break;
  34:	eb f6                	jmp    2c <switch_eg+0x2c>
void switch_eg(long x, long n, long *dest) {
  36:	bf 00 00 00 00       	mov    $0x0,%edi
  3b:	eb ef                	jmp    2c <switch_eg+0x2c>
