extern _ft_isinrange

global _ft_isascii
section .text

_ft_isascii:
	mov rsi, 0
	mov rdx, 0x7f
	call _ft_isinrange
	ret
