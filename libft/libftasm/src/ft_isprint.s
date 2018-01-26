extern _ft_isinrange

global _ft_isprint
section .text

_ft_isprint:
	mov rsi, 0x20        ; ' '
	mov rdx, 0x7e        ; '~'
	call _ft_isinrange
	ret
