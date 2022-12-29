
parameters.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <proc>:
   0:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
   5:	48 01 3e             	add    %rdi,(%rsi)
   8:	01 11                	add    %edx,(%rcx)
   a:	66 45 01 01          	add    %r8w,(%r9)
   e:	8b 54 24 08          	mov    0x8(%rsp),%edx
  12:	00 10                	add    %dl,(%rax)
  14:	c3                   	retq   

0000000000000015 <call_proc>:
  15:	48 83 ec 10          	sub    $0x10,%rsp
  # since we need get the address of local variable, it should be saved in
  # memory
  19:	48 c7 44 24 08 01 00 	movq   $0x1,0x8(%rsp)   # x1
  20:	00 00 
  22:	c7 44 24 04 02 00 00 	movl   $0x2,0x4(%rsp)   # x2
  29:	00 
  2a:	66 c7 44 24 02 03 00 	movw   $0x3,0x2(%rsp)   # x3
  31:	c6 44 24 01 04       	movb   $0x4,0x1(%rsp)   # x4
  36:	48 8d 4c 24 04       	lea    0x4(%rsp),%rcx   # &x2
  3b:	48 8d 74 24 08       	lea    0x8(%rsp),%rsi   # &x1
  40:	48 8d 44 24 01       	lea    0x1(%rsp),%rax   # &x4
  45:	50                   	push   %rax             # push &x4 into memory
  46:	6a 04                	pushq  $0x4             # push x4 into memory
  48:	4c 8d 4c 24 12       	lea    0x12(%rsp),%r9   # &x3
  4d:	41 b8 03 00 00 00    	mov    $0x3,%r8d
  53:	ba 02 00 00 00       	mov    $0x2,%edx
  58:	bf 01 00 00 00       	mov    $0x1,%edi
  5d:	e8 00 00 00 00       	callq  62 <call_proc+0x4d>
  62:	48 63 44 24 14       	movslq 0x14(%rsp),%rax
  67:	48 03 44 24 18       	add    0x18(%rsp),%rax
  6c:	0f bf 54 24 12       	movswl 0x12(%rsp),%edx
  71:	0f be 4c 24 11       	movsbl 0x11(%rsp),%ecx
  76:	29 ca                	sub    %ecx,%edx
  78:	48 63 d2             	movslq %edx,%rdx
  7b:	48 0f af c2          	imul   %rdx,%rax
  7f:	48 83 c4 20          	add    $0x20,%rsp
  83:	c3                   	retq   
