global _ft_strlen
section .text

_ft_strlen:
	push rdi
	; scasb will search a 0 char in rdi
	xor al, al    ; => optimized mov al, 0
	mov rcx, -1
	cld           ; inc rdi each turn of scasb
	repnz scasb   ; scasb = SCan A String & compare each char with al

	; rcx starts at -1 and dec when al is found
	; real length = -2 + (rcx * -1)
	mov rax, -2
	sub rax, rcx
	pop rdi
	ret
