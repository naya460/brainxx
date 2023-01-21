.intel_syntax noprefix
.globl main
main:
    mov rbp, rsp
    push 1
    push 2
    pop rdi
    pop rax
    add rax, rdi
    push rax
    push 3
    push 4
    pop rdi
    pop rax
    sub rax, rdi
    push rax
    mov rsp, rbp
    mov rax, 0
    ret

