extern _ft_strlen
extern _ft_bzero

;void	ft_strclr(char *s)

global _ft_strclr
section .text

_ft_strclr:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	; push rdi
	call _ft_strlen
	; pop rdi
	mov rsi, rax
	call _ft_bzero
	add rsp, 16
	pop rbp
	ret
