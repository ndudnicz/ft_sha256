extern _ft_tolower

global _ft_strcmp_nocase
section .text

_ft_strcmp_nocase:
	xor rax, rax
	xor rcx, rcx
	mov r10, rdi
	mov r11, rsi
	call myloop
	ret

myloop:
; get tolower of r10
movzx rdi, byte [r10 + rcx]
call _ft_tolower
mov r12, rax
; get tolower of r11
movzx rdi, byte [r11 + rcx]
call _ft_tolower
mov r13, rax
; cmp each lowbit
cmp r13b, r12b
jne ret_ne
test al, al
jz end
inc rcx
jmp myloop

ret_ne:
movzx r10, byte [r10 + rcx]
movzx r11, byte [r11 + rcx]
sub r10, r11
mov rax, r10
jmp end

end:
ret
