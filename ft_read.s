section .text
global  ft_read

extern __errno_location

ft_read:
    mov rax, 0
    syscall

    cmp rax, 0
    jc  .handle_error

    ret

.handle_error:
    push    rax
    call    __errno_location wrt ..plt
    pop     rdi
    mov     [rax], rdi
    mov     rax, -1

    ret