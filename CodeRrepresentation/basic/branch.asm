
branch.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <absdiff_se>:
long lt_cnt = 0;
long ge_cnt = 0;

# x in %rdi, y in %rsi, from right to left
long absdiff_se(long x, long y) {
  long result;
  if (x < y) {
   0:	48 39 f7             	cmp    %rsi,%rdi             # rdi - rsi (dst - src)
   3:	7d 0f                	jge    14 <absdiff_se+0x14>
    lt_cnt++;
   5:	48 83 05 00 00 00 00 	addq   $0x1,0x0(%rip)        # d <absdiff_se+0xd>
   c:	01 
    result = y - x;
   d:	48 89 f0             	mov    %rsi,%rax
  10:	48 29 f8             	sub    %rdi,%rax
  13:	c3                   	retq   
  } else {
    ge_cnt++;
  14:	48 83 05 00 00 00 00 	addq   $0x1,0x0(%rip)        # 1c <absdiff_se+0x1c>
  1b:	01 
    result = x - y;
  1c:	48 89 f8             	mov    %rdi,%rax
  1f:	48 29 f0             	sub    %rsi,%rax
  }

  return result;
}
  22:	c3                   	retq   
