%define STDOUT				1
%define WRITE				1

global _ft_putchar
section .text

_ft_putchar:
	push rdi
	mov rsi, rsp
	mov rdi, STDOUT
	mov rdx, 1
	mov rax, WRITE
	syscall
	pop rdi
	ret
