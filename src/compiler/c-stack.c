#include "compiler/c-stack.h"

#include <stdio.h>
#include <stdlib.h>

#include "compiler/output.h"

// prototype declaration
void CompileAboutStackEqual(char **program_ptr);

void CompileAboutStack(char **program_ptr){
    char *program = *program_ptr;
    // move next char of '$'
    ++program;
    // push number when current char is number
    if ('0' <= *program && *program <= '9') {
        long num = strtol(program, &program, 10);
        OutputStackPush(num);
    }
    // operation
    switch (*program) {
        case '+':
            OutputStackAdd();
            ++program;
            break;
        case '-':
            OutputStackSub();
            ++program;
            break;
        case '*':
            OutputStackMul();
            ++program;
            break;
        case '/':
            OutputStackDiv();
            ++program;
            break;
        case '%':
            OutputStackMod();
            ++program;
            break;
        // == or => or =< or =!
        case '=':
            CompileAboutStackEqual(&program);
            ++program;
            break;
    }
    *program_ptr = program;
}

void CompileAboutStackEqual(char **program_ptr){
    char *program = *program_ptr;
    // move next char of '='
    ++program;
    // operation
    switch (*program) {
        // ==
        case '=':
            OutputStackEqual();
            break;
    }

    *program_ptr = program;
}