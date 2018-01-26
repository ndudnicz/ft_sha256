extern _ft_strlen
extern _ft_isdigit

; long int	ft_atol(char const *s)

global _ft_atol
section .text

_ft_atol:
	lea r9, [rel rdi]      ; input str
	xor r10, r10           ; sign
	xor r11, r11           ; result
	xor r13, r13           ; get_number var tmp
	xor r14, r14           ; count
	call _ft_strlen
	mov r12, rax           ; strlen
	call jump_spaces
	call get_sign
	ret

jump_spaces:
	cmp r14, r12
	jge return
	cmp [r9 + r14], byte 0x20    ; ' '
	je inc_r14_jump_spaces
	cmp [r9 + r14], byte 0x09    ; '\t'
	je inc_r14_jump_spaces
	cmp [r9 + r14], byte 0x0a    ; '\n'
	je inc_r14_jump_spaces
	cmp [r9 + r14], byte 0x0d    ; '\r'
	je inc_r14_jump_spaces
	cmp [r9 + r14], byte 0x0b    ; '\v'
	je inc_r14_jump_spaces
	cmp [r9 + r14], byte 0x0c    ; '\f'
	je inc_r14_jump_spaces
	ret

inc_r14_jump_spaces:
	inc r14
	jmp jump_spaces
	;call jump_spaces
	;ret

get_sign:
	cmp [r9 + r14], byte 0x2d    ; '-'
	je set_negative_sign
	cmp [r9 + r14], byte 0x2b    ; '+'
	je set_positive_sign
	mov r10, 0x1
	jmp myloop

set_negative_sign:
	mov r10, 0xffffffffffffffff   ; -1L
	inc r14
	jmp myloop

set_positive_sign:
	mov r10, 0x1
	inc r14
	jmp myloop

myloop:
	cmp r14, r12
	je return
	movzx rdi, byte [r9 + r14]
	call _ft_isdigit
	test rax, rax
	jz return

	; GET NUMBER
	imul r11, byte 0x0a
	movzx r13, byte [r9 + r14]
	sub r13b, byte 0x30
	add r11, r13
	inc r14
	jmp myloop

return:
	mov rax, r11
	imul rax, r10
	ret
