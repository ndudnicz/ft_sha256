%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT				1
%define WRITE				4

extern _ft_strlen

global _ft_putstr
section .text

_ft_putstr:
	; push rdi
	call _ft_strlen
	; pop rdi
	push rax
	mov rsi, rdi
	mov rdi, STDOUT
	mov rdx, rax
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	pop rax
	ret
