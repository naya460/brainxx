#include "compiler/c-stack.h"

#include <stdio.h>
#include <stdlib.h>

#include "compiler/consume.h"
#include "compiler/output.h"

// prototype declaration
void CompileAboutStackEqual(char **program_ptr);

// ========================================

void CompileAboutStack(char **program_ptr){
    char *program = *program_ptr;
    // Push number when current char is number (push __num__)
    if ('0' <= *program && *program <= '9') {
        long num = strtol(program, &program, 10);
        OutputStackPush(num);
    }
    // Operation
    if (ConsumeE(program_ptr, '+', OutputStackAdd)) return; // stack add
    if (ConsumeE(program_ptr, '-', OutputStackSub)) return; // stack sub
    if (ConsumeE(program_ptr, '*', OutputStackMul)) return; // stack mul
    if (ConsumeE(program_ptr, '/', OutputStackDiv)) return; // stack div
    if (ConsumeE(program_ptr, '%', OutputStackMod)) return; // stack mod
    // About Stack Equal
    if (Consume(program_ptr, '=', CompileAboutStackEqual)) return;
    
    *program_ptr = program;
}

void CompileAboutStackEqual(char **program_ptr){
    char *program = *program_ptr;
    // operation
    switch (*program) {
        // ==
        case '=':
            OutputStackEqual();
            break;
        // =<
        case '<':
            OutputStackEqLess();
            break;
        // =>
        case '>':
            OutputStackEqGreater();
            break;
    }

    *program_ptr = program;
}