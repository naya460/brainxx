.intel_syntax noprefix
.globl main
main:
    mov rbp, rsp
    push 2
    push 3
    pop rdi
    pop rax
    cmp rax, rdi
    sete al
    movzb rax, al
    push rax
    mov rsp, rbp
    mov rax, 0
    ret

