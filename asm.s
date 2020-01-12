
task0.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <example_func>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	b8 00 00 00 00       	mov    $0x0,%eax
   9:	e8 00 00 00 00       	callq  e <example_func+0xe>
   e:	5d                   	pop    %rbp
   f:	c3                   	retq   

0000000000000010 <create_task>:
  10:	55                   	push   %rbp
  11:	48 89 e5             	mov    %rsp,%rbp
  14:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  18:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  1c:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
  20:	48 c7 45 f8 00 00 00 	movq   $0x0,-0x8(%rbp)
  27:	00 
  28:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  2c:	48 c7 00 14 00 00 00 	movq   $0x14,(%rax)
  33:	48 8d 04 25 00 00 00 	lea    0x0,%rax
  3a:	00 
  3b:	48 89 20             	mov    %rsp,(%rax)
  3e:	48 89 60 08          	mov    %rsp,0x8(%rax)
  42:	48 89 60 10          	mov    %rsp,0x10(%rax)
  46:	5d                   	pop    %rbp
  47:	c3                   	retq   

0000000000000048 <task0>:
  48:	55                   	push   %rbp
  49:	48 89 e5             	mov    %rsp,%rbp
  4c:	5d                   	pop    %rbp
  4d:	c3                   	retq   

000000000000004e <main>:
  4e:	55                   	push   %rbp
  4f:	48 89 e5             	mov    %rsp,%rbp
  52:	e8 00 00 00 00       	callq  57 <main+0x9>
  57:	48 8b 05 00 00 00 00 	mov    0x0(%rip),%rax        # 5e <main+0x10>
  5e:	48 89 c1             	mov    %rax,%rcx
  61:	48 8b 05 00 00 00 00 	mov    0x0(%rip),%rax        # 68 <main+0x1a>
  68:	ba 00 00 00 00       	mov    $0x0,%edx
  6d:	48 89 ce             	mov    %rcx,%rsi
  70:	48 89 c7             	mov    %rax,%rdi
  73:	e8 00 00 00 00       	callq  78 <main+0x2a>
  78:	5d                   	pop    %rbp
  79:	c3                   	retq   

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	00 47 43             	add    %al,0x43(%rdi)
   3:	43 3a 20             	rex.XB cmp (%r8),%spl
   6:	28 55 62             	sub    %dl,0x62(%rbp)
   9:	75 6e                	jne    79 <main+0x2b>
   b:	74 75                	je     82 <main+0x34>
   d:	20 34 2e             	and    %dh,(%rsi,%rbp,1)
  10:	38 2e                	cmp    %ch,(%rsi)
  12:	34 2d                	xor    $0x2d,%al
  14:	32 75 62             	xor    0x62(%rbp),%dh
  17:	75 6e                	jne    87 <main+0x39>
  19:	74 75                	je     90 <main+0x42>
  1b:	31 7e 31             	xor    %edi,0x31(%rsi)
  1e:	34 2e                	xor    $0x2e,%al
  20:	30 34 2e             	xor    %dh,(%rsi,%rbp,1)
  23:	34 29                	xor    $0x29,%al
  25:	20 34 2e             	and    %dh,(%rsi,%rbp,1)
  28:	38 2e                	cmp    %ch,(%rsi)
  2a:	34 00                	xor    $0x0,%al

Disassembly of section .eh_frame:

0000000000000000 <.eh_frame>:
   0:	14 00                	adc    $0x0,%al
   2:	00 00                	add    %al,(%rax)
   4:	00 00                	add    %al,(%rax)
   6:	00 00                	add    %al,(%rax)
   8:	01 7a 52             	add    %edi,0x52(%rdx)
   b:	00 01                	add    %al,(%rcx)
   d:	78 10                	js     1f <.eh_frame+0x1f>
   f:	01 1b                	add    %ebx,(%rbx)
  11:	0c 07                	or     $0x7,%al
  13:	08 90 01 00 00 1c    	or     %dl,0x1c000001(%rax)
  19:	00 00                	add    %al,(%rax)
  1b:	00 1c 00             	add    %bl,(%rax,%rax,1)
  1e:	00 00                	add    %al,(%rax)
  20:	00 00                	add    %al,(%rax)
  22:	00 00                	add    %al,(%rax)
  24:	10 00                	adc    %al,(%rax)
  26:	00 00                	add    %al,(%rax)
  28:	00 41 0e             	add    %al,0xe(%rcx)
  2b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  31:	4b 0c 07             	rex.WXB or $0x7,%al
  34:	08 00                	or     %al,(%rax)
  36:	00 00                	add    %al,(%rax)
  38:	1c 00                	sbb    $0x0,%al
  3a:	00 00                	add    %al,(%rax)
  3c:	3c 00                	cmp    $0x0,%al
  3e:	00 00                	add    %al,(%rax)
  40:	00 00                	add    %al,(%rax)
  42:	00 00                	add    %al,(%rax)
  44:	38 00                	cmp    %al,(%rax)
  46:	00 00                	add    %al,(%rax)
  48:	00 41 0e             	add    %al,0xe(%rcx)
  4b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  51:	73 0c                	jae    5f <.eh_frame+0x5f>
  53:	07                   	(bad)  
  54:	08 00                	or     %al,(%rax)
  56:	00 00                	add    %al,(%rax)
  58:	1c 00                	sbb    $0x0,%al
  5a:	00 00                	add    %al,(%rax)
  5c:	5c                   	pop    %rsp
  5d:	00 00                	add    %al,(%rax)
  5f:	00 00                	add    %al,(%rax)
  61:	00 00                	add    %al,(%rax)
  63:	00 06                	add    %al,(%rsi)
  65:	00 00                	add    %al,(%rax)
  67:	00 00                	add    %al,(%rax)
  69:	41 0e                	rex.B (bad) 
  6b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  71:	41 0c 07             	rex.B or $0x7,%al
  74:	08 00                	or     %al,(%rax)
  76:	00 00                	add    %al,(%rax)
  78:	1c 00                	sbb    $0x0,%al
  7a:	00 00                	add    %al,(%rax)
  7c:	7c 00                	jl     7e <.eh_frame+0x7e>
  7e:	00 00                	add    %al,(%rax)
  80:	00 00                	add    %al,(%rax)
  82:	00 00                	add    %al,(%rax)
  84:	2c 00                	sub    $0x0,%al
  86:	00 00                	add    %al,(%rax)
  88:	00 41 0e             	add    %al,0xe(%rcx)
  8b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  91:	67 0c 07             	addr32 or $0x7,%al
  94:	08 00                	or     %al,(%rax)
	...
