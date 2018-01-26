global _ft_memcpy
section .text

_ft_memcpy:
	mov r10, rdi
	mov rcx, rdx
	cld
	rep movsb
	mov rax, r10
	ret
