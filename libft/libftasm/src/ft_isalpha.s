extern _ft_isinrange

global _ft_isalpha
section .text

_ft_isalpha:
	mov rsi, 0x41    ; 'A'
	mov rdx, 0x5a    ; 'Z'
	call _ft_isinrange
	test rax, rax    ; cmp rax, 0
	jz cmp_lower
	ret

cmp_lower:
	mov rdx, 0x7a    ; 'Z'
	mov rsi, 0x61    ; 'A'
	call _ft_isinrange
	ret
