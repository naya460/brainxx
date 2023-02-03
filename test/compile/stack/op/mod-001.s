.intel_syntax noprefix
.globl main
main:
    mov rbp, rsp
    push 7
    push 2
    pop rdi
    pop rax
    cqo
    idiv rdi
    push rdx
    mov rsp, rbp
    mov rax, 0
    ret

