global _ft_strcmp
section .text

_ft_strcmp:
	xor rax, rax
	xor rcx, rcx
	call myloop
	ret

myloop:
	mov al, byte [rsi + rcx]
	cmp byte [rdi + rcx], al
	jne ret_ne
	test al, al
	jz end
	inc rcx
	jmp myloop

ret_ne:
	movzx r10, byte [rdi + rcx]
	movzx r11, byte [rsi + rcx]
	sub r10, r11
	mov rax, r10
	jmp end

end:
	ret
