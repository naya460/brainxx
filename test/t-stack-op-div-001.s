.intel_syntax noprefix
.globl main
main:
    mov rbp, rsp
    push 8
    push 3
    pop rdi
    pop rax
    cqo
    idiv rdi
    push rax
    mov rsp, rbp
    mov rax, 0
    ret

