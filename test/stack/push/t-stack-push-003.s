.intel_syntax noprefix
.globl main
main:
    mov rbp, rsp
    push 0
    push 1
    push 2
    push 3
    push 4
    push 5
    push 6
    push 7
    push 8
    push 9
    mov rsp, rbp
    mov rax, 0
    ret

