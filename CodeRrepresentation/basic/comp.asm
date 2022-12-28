
comp.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <comp>:
typedef int data_t;

int comp(data_t a, data_t b) {
  return a > b;
   0:	39 f7                	cmp    %esi,%edi
   2:	0f 9f c0             	setg   %al
   5:	0f b6 c0             	movzbl %al,%eax
}
   8:	c3                   	retq   
