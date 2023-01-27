.intel_syntax noprefix
.globl main
main:
    mov rbp, rsp
    push 3
    pop rax
    mov rsp, rbp
    ret
    mov rsp, rbp
    mov rax, 0
    ret

