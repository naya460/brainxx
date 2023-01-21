.intel_syntax noprefix
.globl main
main:
    mov rbp, rsp
    push 4
    push 6
    pop rdi
    pop rax
    mul rax, rdi
    push rax
    mov rsp, rbp
    mov rax, 0
    ret

