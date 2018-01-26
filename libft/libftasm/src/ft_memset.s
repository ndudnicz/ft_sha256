global _ft_memset
section .text

_ft_memset:
	test rdx, rdx
	jz end
	mov r11, rdi
	mov r10, rsi
	mov rcx, rdx
	mov al, r10b    ; r10b = (r10 & 0x000000ff)
	dec rcx
	cld
	rep stosb
	stosb
	mov rax, r11
	ret

end:
	mov rax, rdi
	ret
