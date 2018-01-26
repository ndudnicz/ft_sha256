%define WRITE				1

global _ft_putchar_fd
section .text

_ft_putchar_fd:
	push rdi
	mov rdi, rsi
	mov rsi, rsp
	mov rdx, 1
	mov rax, WRITE
	syscall
	pop rdi
	ret
