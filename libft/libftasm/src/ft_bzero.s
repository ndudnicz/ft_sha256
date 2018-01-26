extern _ft_memset

; void	ft_bzero(char *mem)

global _ft_bzero
section .text

_ft_bzero:
	mov rdx, rsi
	xor rsi, rsi    ; memset(rdi, 0, rdx)
	call _ft_memset
	ret
