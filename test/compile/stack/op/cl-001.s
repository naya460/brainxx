.intel_syntax noprefix
.globl main
main:
    mov rbp, rsp
    push 5
    push 4
    pop rdi
    pop rax
    cmp rax, rdi
    setl al
    movzb rax, al
    push rax
    mov rsp, rbp
    mov rax, 0
    ret

