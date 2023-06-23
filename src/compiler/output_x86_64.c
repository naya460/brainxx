// Copyright 2023 naya460
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "compiler/output_x86_64.h"

#include <stdio.h>

#include "file.h"

static int rep_depth = 0;
static int rep_c = 0;
static int rep_c_ed[100] = {0};

void x86_64_Output(Operation operation){
    switch (operation) {
    // header of assembly
    case Header:
        QueueContent(".intel_syntax noprefix\n");
        break;

    // start of assembly
    case StartAssembly:
        QueueContent(".globl main\n");
        QueueContent("main:\n");
        QueueContent("    push rbp\n");
        QueueContent("    mov rbp, rsp\n");
        QueueContent("    push r9\n");
        QueueContent("    push r8\n");
        QueueContent("    push rcx\n");
        QueueContent("    push rdx\n");
        QueueContent("    push rsi\n");
        QueueContent("    push rdi\n");
        break;
    
    // end of assembly
    case EndAssembly:
        QueueContent("    mov rsp, rbp\n");
        QueueContent("    pop rbp\n");
        QueueContent("    mov rax, 0\n");
        QueueContent("    ret\n");
        break;
    
    // c-stack
    case StackInc:
        QueueContent("    pop rax\n");
        QueueContent("    inc rax\n");
        QueueContent("    push rax\n");
        break;
    
    case StackDec:
        QueueContent("    pop rax\n");
        QueueContent("    dec rax\n");
        QueueContent("    push rax\n");
        break;
    
    case StackAdd:
        QueueContent("    pop rdi\n");
        QueueContent("    pop rax\n");
        QueueContent("    add rax, rdi\n");
        QueueContent("    push rax\n");
        break;
    
    case StackSub:
        QueueContent("    pop rdi\n");
        QueueContent("    pop rax\n");
        QueueContent("    sub rax, rdi\n");
        QueueContent("    push rax\n");
        break;
    
    case StackMul:
        QueueContent("    pop rdi\n");
        QueueContent("    pop rax\n");
        QueueContent("    imul rax, rdi\n");
        QueueContent("    push rax\n");
        break;
    
    case StackDiv:
        QueueContent("    pop rdi\n");
        QueueContent("    pop rax\n");
        QueueContent("    cqo\n");
        QueueContent("    idiv rdi\n");
        QueueContent("    push rax\n");
        break;
    
    case StackMod:
        QueueContent("    pop rdi\n");
        QueueContent("    pop rax\n");
        QueueContent("    cqo\n");
        QueueContent("    idiv rdi\n");
        QueueContent("    push rdx\n");
        break;
    
    case StackDup:
        QueueContent("    push [rsp]\n");
        break;

    case PushArg:
        QueueContent("    pop rdi\n");
        QueueContent("    imul rdi, 8\n");
        QueueContent("    mov rax, rbp\n");
        QueueContent("    sub rax, 56\n");
        QueueContent("    add rax, rdi\n");
        QueueContent("    push [rax]\n");
        break;
    
    case StackCl:
        QueueContent("    pop rdi\n");
        QueueContent("    pop rax\n");
        QueueContent("    cmp rax, rdi\n");
        QueueContent("    setl al\n");
        QueueContent("    movzb rax, al\n");
        QueueContent("    push rax\n");
        break;
    
    case StackCg:
        QueueContent("    pop rdi\n");
        QueueContent("    pop rax\n");
        QueueContent("    cmp rdi, rax\n");
        QueueContent("    setl al\n");
        QueueContent("    movzb rax, al\n");
        QueueContent("    push rax\n");
        break;
    
    case StackEq:
        QueueContent("    pop rdi\n");
        QueueContent("    pop rax\n");
        QueueContent("    cmp rax, rdi\n");
        QueueContent("    sete al\n");
        QueueContent("    movzb rax, al\n");
        QueueContent("    push rax\n");
        break;
    
    case StackEl:
        QueueContent("    pop rdi\n");
        QueueContent("    pop rax\n");
        QueueContent("    cmp rax, rdi\n");
        QueueContent("    setle al\n");
        QueueContent("    movzb rax, al\n");
        QueueContent("    push rax\n");
        break;
    
    case StackEg:
        QueueContent("    pop rdi\n");
        QueueContent("    pop rax\n");
        QueueContent("    cmp rdi, rax\n");
        QueueContent("    setle al\n");
        QueueContent("    movzb rax, al\n");
        QueueContent("    push rax\n");
        break;
    
    case StackNe:
        QueueContent("    pop rdi\n");
        QueueContent("    pop rax\n");
        QueueContent("    cmp rax, rdi\n");
        QueueContent("    setne al\n");
        QueueContent("    movzb rax, al\n");
        QueueContent("    push rax\n");
        break;

    case StackOr:
        QueueContent("    pop rdi\n");
        QueueContent("    pop rax\n");
        QueueContent("    or rax, rdi\n");
        QueueContent("    push rax\n");
        break;
    
    case StackAnd:
        QueueContent("    pop rdi\n");
        QueueContent("    pop rax\n");
        QueueContent("    and rax, rdi\n");
        QueueContent("    push rax\n");
        break;
    
    case StackXor:
        QueueContent("    pop rdi\n");
        QueueContent("    pop rax\n");
        QueueContent("    xor rax, rdi\n");
        QueueContent("    push rax\n");
        break;
    
    case StackNot:
        QueueContent("    pop rax\n");
        QueueContent("    not rax\n");
        QueueContent("    push rax\n");
        break;
    
    case StackShl:
        QueueContent("    pop rcx\n");
        QueueContent("    pop rax\n");
        QueueContent("    shl rax, cl\n");
        QueueContent("    push rax\n");
        break;
    
    case StackShr:
        QueueContent("    pop rcx\n");
        QueueContent("    pop rax\n");
        QueueContent("    shr rax, cl\n");
        QueueContent("    push rax\n");
        break;
    
    case PushCptr:
        QueueContent("    push rsp\n");
        break;
    
    case PushBptr:
        QueueContent("    mov rax, rbp\n");
        QueueContent("    sub rax, 48\n");
        QueueContent("    push rax\n");
        break;
    
    case MovCptr:
        QueueContent("    pop rax\n");
        QueueContent("    mov rsp, rax\n");
        break;
    
    case PtrAdd:
        QueueContent("    pop rdi\n");
        QueueContent("    pop rax\n");
        QueueContent("    imul rdi, 8\n");
        QueueContent("    sub rax, rdi\n");
        QueueContent("    push rax\n");
        break;

    case PtrSub:
        QueueContent("    pop rdi\n");
        QueueContent("    pop rax\n");
        QueueContent("    imul rdi, 8\n");
        QueueContent("    add rax, rdi\n");
        QueueContent("    push rax\n");
        break;

    case PtrGet:
        QueueContent("    pop rax\n");
        QueueContent("    push [rax]\n");
        break;
    
    // c-ctrl
    case CtrlSpl:
        QueueContent("    add rsp, 8\n");
        break;
    
    case CtrlSpr:
        QueueContent("    sub rsp, 8\n");
        break;
    
    case CtrlRepb:
        QueueContent(".Lbegin%d:\n", rep_c);
        QueueContent("    pop rax\n");
        QueueContent("    push rax\n");
        QueueContent("    cmp rax, 0\n");
        QueueContent("    je .Lend%d\n", rep_c);
        rep_c_ed[rep_depth++] = rep_c++;
        break;
    
    case CtrlRepe:
        --rep_depth;
        QueueContent("    jmp .Lbegin%d\n", rep_c_ed[rep_depth]);
        QueueContent(".Lend%d:\n", rep_c_ed[rep_depth]);
        break;

    // c-fn
    case FnRet:
        QueueContent("    pop rax\n");
        QueueContent("    mov rsp, rbp\n");
        QueueContent("    pop rbp\n");
        QueueContent("    ret\n");
        break;
    
    // c-io
    case IoCout:
        QueueContent("    mov rax, 1\n");
        QueueContent("    mov rdi, 1\n");
        QueueContent("    mov rsi, rsp\n");
        QueueContent("    mov rdx, 1\n");
        QueueContent("    syscall\n");
        break;
    
    case IoCin:
        QueueContent("    mov rax, 0\n");
        QueueContent("    mov rdi, 0\n");
        QueueContent("    mov rsi, rsp\n");
        QueueContent("    mov rdx, 1\n");
        QueueContent("    syscall\n");
        break;
    }
}

// c-stack
void x86_64_StackPush(int num){
    QueueContent("    push %d\n", num);
}

// c-tag
void x86_64_TagDef(int num){
    QueueContent(".Ltag%d:\n", num);
}

void x86_64_TagJmp(int num){
    QueueContent("    jmp .Ltag%d\n", num);
}

// c-fn
void x86_64_FnDef(int num){
    QueueContent("fn%d:\n", num);
    QueueContent("    push rbp\n");
    QueueContent("    mov rbp, rsp\n");
    QueueContent("    push r9\n");
    QueueContent("    push r8\n");
    QueueContent("    push rcx\n");
    QueueContent("    push rdx\n");
    QueueContent("    push rsi\n");
    QueueContent("    push rdi\n");
}

void x86_64_FnCall(int fid, int argc){
    if (argc >= 1) QueueContent("    pop rdi\n");
    if (argc >= 2) QueueContent("    pop rsi\n");
    if (argc >= 3) QueueContent("    pop rdx\n");
    if (argc >= 4) QueueContent("    pop rcx\n");
    if (argc >= 5) QueueContent("    pop r8\n");
    if (argc >= 6) QueueContent("    pop r9\n");
    QueueContent("    call fn%d\n", fid);
    QueueContent("    push rax\n");
}

void x86_64_FnPub(int num){
    QueueContent(".global fn%d\n", num);
}