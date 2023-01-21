#include "compiler/output.h"

#include <stdio.h>

void OutputStartAssembly(){
    printf(".intel_syntax noprefix\n");
    printf(".globl main\n");
    printf("main:\n");
    printf("    mov rbp, rsp\n");
}

void OutputEndAssembly(){
    printf("    mov rsp, rbp\n");
    printf("    mov rax, 0\n");
    printf("    ret\n");
}

void OutputStackPush(long num){
    printf("    push %d\n", num);
}

void OutputStackAdd(){
    printf("    pop rdi\n");
    printf("    pop rax\n");
    printf("    add rax, rdi\n");
    printf("    push rax\n");
}

void OutputStackSub(){
    printf("    pop rdi\n");
    printf("    pop rax\n");
    printf("    sub rax, rdi\n");
    printf("    push rax\n");
}

void OutputStackMul(){
    printf("    pop rdi\n");
    printf("    pop rax\n");
    printf("    mul rax, rdi\n");
    printf("    push rax\n");
}