%define WRITE				1

extern _ft_strlen

global _ft_putstr_fd
section .text

_ft_putstr_fd:
	; push rdi
	call _ft_strlen
	; pop rdi
	push rax
	xor rsi, rdi    ; swap
	xor rdi, rsi    ; swap
	xor rsi, rdi    ; swap
	mov rdx, rax
	mov rax, WRITE
	syscall
	pop rax
	ret
