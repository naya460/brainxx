#include <stdio.h>

#include "compiler/c-stack.h"

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
                CompileAboutStack(&program);
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