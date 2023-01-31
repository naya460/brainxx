.intel_syntax noprefix
.globl main
main:
    mov rbp, rsp
    push 3
.Lbegin0:
    pop rax
    push rax
    cmp rax, 0
    je .Lend0
    push 1
    pop rdi
    pop rax
    sub rax, rdi
    push rax
    jmp .Lbegin0
.Lend0:
    pop rax
    mov rsp, rbp
    ret
    mov rsp, rbp
    mov rax, 0
    ret

