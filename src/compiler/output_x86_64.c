#include "compiler/output_x86_64.h"

#include <stdio.h>

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
    printf("    mul rax, rdi\n");
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

void x86_64_StackEqual(){
    printf("    pop rdi\n");
    printf("    pop rax\n");
    printf("    cmp rax, rdi\n");
    printf("    sete al\n");
    printf("    movzb rax, al\n");
    printf("    push rax\n");
}