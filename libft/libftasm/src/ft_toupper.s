extern _ft_isinrange

global _ft_toupper
section .text

_ft_toupper:
	mov rsi, 0x61    ; 'a'
	mov rdx, 0x7a    ; 'z'
	call _ft_isinrange
	test rax, rax
	jz end
	sub rdi, 0x20
	mov rax, rdi
	ret

end:
	xor rax, rdi
	ret
