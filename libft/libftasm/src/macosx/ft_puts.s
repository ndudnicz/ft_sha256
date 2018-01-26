%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT				1
%define WRITE				4

extern _ft_strlen
extern _ft_putstr

global _ft_puts
section .data
endline:	db "", 10
null:		db "(null)", 10

section .text

_ft_puts:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	test rdi, rdi
	jz null_str
	; push rdi
	call _ft_strlen
	; pop rdi
	call _ft_putstr
	lea rsi, [rel endline]
	mov rdi, STDOUT
	mov rdx, 1
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	add rsp, 16
	pop rbp
	ret

null_str:
	lea rsi, [rel null]
	mov rdi, STDOUT
	mov rdx, 7
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	add rsp, 16
	pop rbp
	ret
