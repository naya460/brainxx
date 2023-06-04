#include "compiler/output_x86_64.h"

#include <stdio.h>

static int rep_depth = 0;
static int rep_c = 0;
static int rep_c_ed[100] = {0};

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

void x86_64_StackDup(){
    printf("    push [rsp]\n");
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
    printf("    push rdx\n");
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

void x86_64_StackInc(){
    printf("    pop rax\n");
    printf("    add rax, 1\n");
    printf("    push rax\n");
}

void x86_64_StackDec(){
    printf("    pop rax\n");
    printf("    sub rax, 1\n");
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

void x86_64_StackNe(){
    printf("    pop rdi\n");
    printf("    pop rax\n");
    printf("    cmp rax, rdi\n");
    printf("    setne al\n");
    printf("    movzb rax, al\n");
    printf("    push rax\n");
}

void x86_64_PushCptr(){
    printf("    push rsp\n");
}

void x86_64_PushBptr(){
    printf("    mov rax, rbp\n");
    printf("    sub rax, 8\n");
    printf("    push rax\n");
}

void x86_64_MovCptr(){
    printf("    pop rax\n");
    printf("    mov rsp, rax\n");
}

void x86_64_CtrlRet(){
    printf("    pop rax\n");
    printf("    mov rsp, rbp\n");
    printf("    ret\n");
}

void x86_64_CtrlSpl(){
    printf("    add rsp, 8\n");
}

void x86_64_CtrlSpr(){
    printf("    sub rsp, 8\n");
}

void x86_64_CtrlRepb(){
    printf(".Lbegin%d:\n", rep_c);
    printf("    pop rax\n");
    printf("    push rax\n");
    printf("    cmp rax, 0\n");
    printf("    je .Lend%d\n", rep_c);
    rep_c_ed[rep_depth++] = rep_c++;
}

void x86_64_CtrlRepe(){
    int dep = rep_c_ed[--rep_depth];
    printf("    jmp .Lbegin%d\n", dep);
    printf(".Lend%d:\n", dep);
}

void x86_64_IoCout(){
    printf("    mov rax, 1\n");
    printf("    mov rdi, 1\n");
    printf("    mov rsi, rsp\n");
    printf("    mov rdx, 1\n");
    printf("    syscall\n");
}

void x86_64_IoCin(){
    printf("    mov rax, 0\n");
    printf("    mov rdi, 0\n");
    printf("    mov rsi, rsp\n");
    printf("    mov rdx, 1\n");
    printf("    syscall\n");
}