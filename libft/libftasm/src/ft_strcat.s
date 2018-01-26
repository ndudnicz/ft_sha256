extern _ft_strlen

global _ft_strcat
section .text

_ft_strcat:
	mov r10, rdi
	; get strlen(rdi)
	call _ft_strlen
	mov r11, rax
	; init count
	; mov rcx, 0
	xor rcx, rcx
	call copy
	mov rax, r10
	ret

copy:
	; al = rsi[rcx]
	mov al, byte [rsi + rcx]
	; rdi[r11] = al
	mov byte [r10 + r11], al
	inc rcx
	inc r11
	test al, al
	jnz copy
	ret
