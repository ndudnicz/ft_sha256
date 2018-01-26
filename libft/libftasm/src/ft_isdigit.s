extern _ft_isinrange

global _ft_isdigit
section .text

_ft_isdigit:
	mov rsi, 0x30
	mov rdx, 0x39
	call _ft_isinrange
	ret
