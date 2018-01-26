%define MACH_SYSCALL(nb)	0x2000000 | nb
%define WRITE				4

global _ft_putchar_fd
section .text

_ft_putchar_fd:
	push rdi
	mov rdi, rsi
	mov rsi, rsp
	mov rdx, 1
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	pop rdi
	ret
