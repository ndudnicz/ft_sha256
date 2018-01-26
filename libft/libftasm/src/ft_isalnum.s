extern _ft_isalpha
extern _ft_isdigit

global _ft_isalnum
section .text

_ft_isalnum:
	mov r10, rax
	call _ft_isdigit
	test rax, rax      ; cmp rax, 0
	jnz end            ; it's a digit => end
	xor rax, r10
	call _ft_isalpha
	ret

end:
	ret
