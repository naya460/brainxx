#include "compiler/output_x86_64.h"

#include <stdio.h>

static int rep_depth = 0;
static int rep_c = 0;
static int rep_c_ed[100] = {0};

void x86_64_Output(Operation operation){
    switch (operation) {
    // start of assembly
    case StartAssembly:
        printf(".intel_syntax noprefix\n");
        printf(".globl main\n");
        printf("main:\n");
        printf("    push rbp\n");
        printf("    mov rbp, rsp\n");
        break;
    
    // end of assembly
    case EndAssembly:
        printf("    mov rsp, rbp\n");
        printf("    pop rbp\n");
        printf("    mov rax, 0\n");
        printf("    ret\n");
        break;
    
    // c-stack
    case StackInc:
        printf("    pop rax\n");
        printf("    add rax, 1\n");
        printf("    push rax\n");
        break;
    
    case StackDec:
        printf("    pop rax\n");
        printf("    sub rax, 1\n");
        printf("    push rax\n");
        break;
    
    case StackAdd:
        printf("    pop rdi\n");
        printf("    pop rax\n");
        printf("    add rax, rdi\n");
        printf("    push rax\n");
        break;
    
    case StackSub:
        printf("    pop rdi\n");
        printf("    pop rax\n");
        printf("    sub rax, rdi\n");
        printf("    push rax\n");
        break;
    
    case StackMul:
        printf("    pop rdi\n");
        printf("    pop rax\n");
        printf("    imul rax, rdi\n");
        printf("    push rax\n");
        break;
    
    case StackDiv:
        printf("    pop rdi\n");
        printf("    pop rax\n");
        printf("    cqo\n");
        printf("    idiv rdi\n");
        printf("    push rax\n");
        break;
    
    case StackMod:
        printf("    pop rdi\n");
        printf("    pop rax\n");
        printf("    cqo\n");
        printf("    idiv rdi\n");
        printf("    push rdx\n");
        break;
    
    case StackDup:
        printf("    push [rsp]\n");
        break;

    case PushArg:
        printf("    pop rdi\n");
        printf("    imul rdi, 8\n");
        printf("    mov rax, rbp\n");
        printf("    sub rax, 56\n");
        printf("    add rax, rdi\n");
        printf("    push [rax]\n");
        break;
    
    case StackCl:
        printf("    pop rdi\n");
        printf("    pop rax\n");
        printf("    cmp rax, rdi\n");
        printf("    setl al\n");
        printf("    movzb rax, al\n");
        printf("    push rax\n");
        break;
    
    case StackCg:
        printf("    pop rdi\n");
        printf("    pop rax\n");
        printf("    cmp rdi, rax\n");
        printf("    setl al\n");
        printf("    movzb rax, al\n");
        printf("    push rax\n");
        break;
    
    case StackEq:
        printf("    pop rdi\n");
        printf("    pop rax\n");
        printf("    cmp rax, rdi\n");
        printf("    sete al\n");
        printf("    movzb rax, al\n");
        printf("    push rax\n");
        break;
    
    case StackEl:
        printf("    pop rdi\n");
        printf("    pop rax\n");
        printf("    cmp rax, rdi\n");
        printf("    setle al\n");
        printf("    movzb rax, al\n");
        printf("    push rax\n");
        break;
    
    case StackEg:
        printf("    pop rdi\n");
        printf("    pop rax\n");
        printf("    cmp rdi, rax\n");
        printf("    setle al\n");
        printf("    movzb rax, al\n");
        printf("    push rax\n");
        break;
    
    case StackNe:
        printf("    pop rdi\n");
        printf("    pop rax\n");
        printf("    cmp rax, rdi\n");
        printf("    setne al\n");
        printf("    movzb rax, al\n");
        printf("    push rax\n");
        break;
    
    case PushCptr:
        printf("    push rsp\n");
        break;
    
    case PushBptr:
        printf("    mov rax, rbp\n");
        printf("    sub rax, 8\n");
        printf("    push rax\n");
        break;
    
    case MovCptr:
        printf("    pop rax\n");
        printf("    mov rsp, rax\n");
        break;
    
    case PtrAdd:
        printf("    pop rdi\n");
        printf("    pop rax\n");
        printf("    imul rdi, 8\n");
        printf("    sub rax, rdi\n");
        printf("    push rax\n");
        break;

    case PtrSub:
        printf("    pop rdi\n");
        printf("    pop rax\n");
        printf("    imul rdi, 8\n");
        printf("    add rax, rdi\n");
        printf("    push rax\n");
        break;

    case PtrGet:
        printf("    pop rax\n");
        printf("    push [rax]\n");
        break;
    
    // c-ctrl
    case CtrlSpl:
        printf("    add rsp, 8\n");
        break;
    
    case CtrlSpr:
        printf("    sub rsp, 8\n");
        break;
    
    case CtrlRepb:
        printf(".Lbegin%d:\n", rep_c);
        printf("    pop rax\n");
        printf("    push rax\n");
        printf("    cmp rax, 0\n");
        printf("    je .Lend%d\n", rep_c);
        rep_c_ed[rep_depth++] = rep_c++;
        break;
    
    case CtrlRepe:
        --rep_depth;
        printf("    jmp .Lbegin%d\n", rep_c_ed[rep_depth]);
        printf(".Lend%d:\n", rep_c_ed[rep_depth]);
        break;

    // c-fn
    case FnRet:
        printf("    pop rax\n");
        printf("    mov rsp, rbp\n");
        printf("    pop rbp\n");
        printf("    ret\n");
        break;
    
    // c-io
    case IoCout:
        printf("    mov rax, 1\n");
        printf("    mov rdi, 1\n");
        printf("    mov rsi, rsp\n");
        printf("    mov rdx, 1\n");
        printf("    syscall\n");
        break;
    
    case IoCin:
        printf("    mov rax, 0\n");
        printf("    mov rdi, 0\n");
        printf("    mov rsi, rsp\n");
        printf("    mov rdx, 1\n");
        printf("    syscall\n");
        break;
    }
}

// c-stack
void x86_64_StackPush(int num){
    printf("    push %d\n", num);
}

// c-tag
void x86_64_TagDef(int num){
    printf(".Ltag%d:\n", num);
}

void x86_64_TagJmp(int num){
    printf("    jmp .Ltag%d\n", num);
}

// c-fn
void x86_64_FnDef(int num){
    printf(".Lfn%d:\n", num);
    printf("    push rbp\n");
    printf("    mov rbp, rsp\n");
    printf("    push r9\n");
    printf("    push r8\n");
    printf("    push rcx\n");
    printf("    push rdx\n");
    printf("    push rsi\n");
    printf("    push rdi\n");
}

void x86_64_FnCall(int fid, int argc){
    if (argc >= 1) printf("    pop rdi\n");
    if (argc >= 2) printf("    pop rsi\n");
    if (argc >= 3) printf("    pop rdx\n");
    if (argc >= 4) printf("    pop rcx\n");
    if (argc >= 5) printf("    pop r8\n");
    if (argc >= 6) printf("    pop r9\n");
    printf("    call .Lfn%d\n", fid);
    printf("    push rax\n");
}