	.file	"task0.c"
	.comm	os,528,32
	.comm	t,8,8
	.text
	.globl	example_func
	.type	example_func, @function
example_func:
.LFB0:
	#.cfi_startproc
	#pushq	%rbp
	#.cfi_def_cfa_offset 16
	#.cfi_offset 6, -16
	#movq	%rsp, %rbp
	#.cfi_def_cfa_register 6
#APP
# 22 "task0.c" 1
	nop 
	#ret 
	
# 0 "" 2
#NO_APP
	#popq	%rbp
	#.cfi_def_cfa 7, 8
	#ret
	#.cfi_endproc
.LFE0:
	.size	example_func, .-example_func
	.globl	create_task
	.type	create_task, @function
create_task:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	$os, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$20, (%rax)
#APP
# 46 "task0.c" 1
	lea os, %rax 
	mov %rsp, 0x0(%rax) 
	mov %rsp, 0x8(%rax) 
	mov %rsp, 0x10(%rax) 
	
# 0 "" 2
#NO_APP
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	create_task, .-create_task
	.globl	task0
	.type	task0, @function
task0:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	task0, .-task0
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
#APP
# 58 "task0.c" 1
	call example_func
# 0 "" 2
#NO_APP
	movq	t(%rip), %rax
	movq	%rax, %rcx
	movq	t(%rip), %rax
	movl	$task0, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	create_task
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.4) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
