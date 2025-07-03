section .text
global ft_strcpy

ft_strcpy:
    xor rax, rax
    mov rax, rdi

.loop:
    mov cl, BYTE [rsi]
    mov BYTE [rdi], cl

    cmp cl, 0
    je .end_loop

    inc rdi
    inc rsi

    jmp .loop
.end_loop:

    ret