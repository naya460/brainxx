#include "compiler/c-stack.h"

#include <stdio.h>
#include <stdlib.h>

void CompileAboutStack(char **program_ptr){
    char *program = *program_ptr;
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
    *program_ptr = program;
}