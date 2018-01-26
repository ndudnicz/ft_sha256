global _ft_strchr
section .text

_ft_strchr:
	mov r10, rsi
	xor rcx, rcx
	call myloop
	ret

myloop:
	cmp [rdi + rcx], r10b
	je return
	cmp [rdi + rcx], byte 0
	je end
	inc rcx
	jmp myloop
	;call myloop
	;ret

return:
	lea rax, [rel rdi + rcx]
	ret

end:
	mov rax, 0
	ret
