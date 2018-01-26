global _ft_isinrange
section .text

; is rdi in [ rsi, rdx [ ?
; return 0 if false or 1 if true, in rax

_ft_isinrange:
	xor rax, rax
	cmp rdi, rsi
	jl end
	mov rax, rdx
	sub rax, rdi
	test rax, rax
	jl end
	mov rax, 1
	ret

end:
	xor rax, rax
	ret
