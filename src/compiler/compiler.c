#include <stdio.h>
#include <stdlib.h>

// prototype declaration
static void CompileAboutStack();

// declare variables
static char *program;

// ========================================

void Compile(char *program_text){
    program = program_text;

    // output base assembly
    printf(".intel_syntax noprefix\n");
    printf(".globl main\n");
    printf("main:\n");
    printf("    mov rbp, rsp\n");

    // operation each text in program
    while(*program != '\0') {
        switch (*program) {
            // about stack process
            case '$':
                CompileAboutStack();
                break;
            // move next char
            default:
                ++program;
                break;
        }
    }

    // output end assembly
    printf("    mov rsp, rbp\n");
    printf("    mov rax, 0\n");
    printf("    ret\n");
}

void CompileAboutStack(){
    // move next char of '$'
    ++program;
    // stack number when current char is number
    if ('0' <= *program && *program <= '9') {
        long n = strtol(program, &program, 10);
        printf("    push %d\n", n);
    }
    // single operation
    switch (*program) {
        case '+':
            printf("    pop rdi\n");
            printf("    pop rax\n");
            printf("    add rax, rdi\n");
            printf("    push rax\n");
            ++program;
            break;
        case '-':
            printf("    pop rdi\n");
            printf("    pop rax\n");
            printf("    sub rax, rdi\n");
            printf("    push rax\n");
            ++program;
            break;
    }
}