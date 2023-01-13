#include <stdio.h>
#include <stdlib.h>

// prototype declaration
static void CompileAboutStack();

// declare variables
static char *program;
static long stack_count = 0;

// ========================================

void Compile(char *program_text){
    program = program_text;

    // output base assembly
    printf(".intel_syntax noprefix\n");
    printf(".globl main\n");
    printf("main:\n");

    // process each text in program
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
    while (stack_count-- != 0) {
        printf("    pop rax\n");
    }
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
        ++stack_count;
    }
}