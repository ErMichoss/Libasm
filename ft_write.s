section .text
global ft_write

extern ___error

ft_write:
    mov rax, 1

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