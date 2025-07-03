section .text
global ft_strlen

ft_strlen:
    xor rax, rax

.loop:
    cmp BYTE [rdi], 0
    je  .end_loop

    inc rax
    inc rdi

    jmp .loop
.end_loop:
    ret