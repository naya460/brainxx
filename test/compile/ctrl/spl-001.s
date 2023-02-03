.intel_syntax noprefix
.globl main
main:
    mov rbp, rsp
    push 4
    add rsp, 8
    mov rsp, rbp
    mov rax, 0
    ret

