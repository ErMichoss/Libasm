section .text
global  ft_read

extern ___error

ft_read:
    mov rax, 0
    syscall

    cmp rax, 0
    jc  .handle_error

    ret

.handle_error:
    push    rax
    call    ___error
    pop     rdi
    mov     [rax], rdi
    mov     rax, -1

    ret