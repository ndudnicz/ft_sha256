%define STDOUT				1
%define WRITE				1

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
	mov rax, WRITE
	syscall
	pop rax
	ret
