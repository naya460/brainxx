.intel_syntax noprefix
.globl main
main:
    mov rbp, rsp
    push 2
.Lbegin0:
    pop rax
    push rax
    cmp rax, 0
    je .Lend0
    jmp .Lbegin0
.Lend0:
    mov rsp, rbp
    mov rax, 0
    ret

