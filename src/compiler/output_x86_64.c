#include "compiler/output_x86_64.h"

#include <stdio.h>

static int rep_depth = 0;

void x86_64_StartAssembly(){
    printf(".intel_syntax noprefix\n");
    printf(".globl main\n");
    printf("main:\n");
    printf("    mov rbp, rsp\n");
}

void x86_64_EndAssembly(){
    printf("    mov rsp, rbp\n");
    printf("    mov rax, 0\n");
    printf("    ret\n");
}

void x86_64_StackPush(long num){
    printf("    push %d\n", num);
}

void x86_64_StackAdd(){
    printf("    pop rdi\n");
    printf("    pop rax\n");
    printf("    add rax, rdi\n");
    printf("    push rax\n");
}

void x86_64_StackSub(){
    printf("    pop rdi\n");
    printf("    pop rax\n");
    printf("    sub rax, rdi\n");
    printf("    push rax\n");
}

void x86_64_StackMul(){
    printf("    pop rdi\n");
    printf("    pop rax\n");
    printf("    imul rax, rdi\n");
    printf("    push rax\n");
}

void x86_64_StackDiv(){
    printf("    pop rdi\n");
    printf("    pop rax\n");
    printf("    cqo\n");
    printf("    idiv rdi\n");
    printf("    push rax\n");
}

void x86_64_StackMod(){
    printf("    pop rdi\n");
    printf("    pop rax\n");
    printf("    cqo\n");
    printf("    idiv rdi\n");
    printf("    push rdi\n");
}

void x86_64_StackCl(){
    printf("    pop rdi\n");
    printf("    pop rax\n");
    printf("    cmp rax, rdi\n");
    printf("    setl al\n");
    printf("    movzb rax, al\n");
    printf("    push rax\n");
}

void x86_64_StackCg(){
    printf("    pop rdi\n");
    printf("    pop rax\n");
    printf("    cmp rdi, rax\n");
    printf("    setl al\n");
    printf("    movzb rax, al\n");
    printf("    push rax\n");
}

void x86_64_StackEq(){
    printf("    pop rdi\n");
    printf("    pop rax\n");
    printf("    cmp rax, rdi\n");
    printf("    sete al\n");
    printf("    movzb rax, al\n");
    printf("    push rax\n");
}

void x86_64_StackEl(){
    printf("    pop rdi\n");
    printf("    pop rax\n");
    printf("    cmp rax, rdi\n");
    printf("    setle al\n");
    printf("    movzb rax, al\n");
    printf("    push rax\n");
}

void x86_64_StackEg(){
    printf("    pop rdi\n");
    printf("    pop rax\n");
    printf("    cmp rdi, rax\n");
    printf("    setle al\n");
    printf("    movzb rax, al\n");
    printf("    push rax\n");
}

void x86_64_CtrlRet(){
    printf("    pop rax\n");
    printf("    mov rsp, rbp\n");
    printf("    ret\n");
}

void x86_64_CtrlRepb(){
    printf(".Lbegin%d:\n", rep_depth);
    printf("    pop rax\n");
    printf("    push rax\n");
    printf("    cmp rax, 0\n");
    printf("    je .Lend%d\n", rep_depth++);
}

void x86_64_CtrlRepe(){
    printf("    jmp .Lbegin%d\n", --rep_depth);
    printf(".Lend%d:\n", rep_depth);
}