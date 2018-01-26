extern _ft_isinrange

global _ft_tolower
section .text

_ft_tolower:
	mov rsi, 0x41    ; 'A'
	mov rdx, 0x5a    ; 'Z'
	call _ft_isinrange
	test rax, rax
	jz end
	add rdi, 0x20
	mov rax, rdi
	ret

end:
	xor rax, rdi
	ret
