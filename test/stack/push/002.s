.intel_syntax noprefix
.globl main
main:
    mov rbp, rsp
    push 1234567890
    mov rsp, rbp
    mov rax, 0
    ret

