section .text
global ft_write

extern __errno_location

ft_write:
    mov rax, 1

    syscall

    cmp rax, 0
    jc  .handle_error

    ret

.handle_error:
    push    rax
    call    __errno_location wrt ..plt ;wrt ..plt Para llamar a cosas desde librerias dinamicas
    pop     rdi
    mov     [rax], rdi
    mov     rax, -1

    ret