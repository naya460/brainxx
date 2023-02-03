.intel_syntax noprefix
.globl main
main:
    mov rbp, rsp
    sub rsp, 8
    push 15
    mov rsp, rbp
    mov rax, 0
    ret

