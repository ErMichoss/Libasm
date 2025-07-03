section .text
global ft_strcmp

ft_strcmp:
    xor rax, rax

.loop:
    mov     cl, BYTE [rdi]
    cmp     cl, BYTE [rsi]
    jne     .calculate

    cmp     BYTE [rdi], 0
    je     .calculate

    inc rdi
    inc rsi
    jmp .loop

.calculate:
    mov     al, BYTE [rdi]
    mov     bl, BYTE [rsi]
    sub     al, bl        
    movsx   rax, al       
    jmp     .end_loop

.end_loop:
    ret