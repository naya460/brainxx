#include "compiler/c-stack.h"

#include <stdlib.h>

#include "compiler/consume.h"
#include "compiler/output.h"

// prototype declaration
void CompileAboutStackEqual(char **program_ptr);
void CompileAboutStackPtr(char **program_ptr);

// ========================================

void CompileAboutStack(char **program_ptr){
    // Push number when current char is number (push __num__)
    char *program = *program_ptr;
    if ('0' <= *program && *program <= '9') {
        long num = strtol(program, &program, 10);
        OutputStackPush(num);
        return;
    }
    // Operation
    if (ConsumeE(program_ptr, '$', Output[StackDup])) return; // stack dup
    if (ConsumeE(program_ptr, '+', Output[StackAdd])) return; // stack add
    if (ConsumeE(program_ptr, '-', Output[StackSub])) return; // stack sub
    if (ConsumeE(program_ptr, '*', Output[StackMul])) return; // stack mul
    if (ConsumeE(program_ptr, '/', Output[StackDiv])) return; // stack div
    if (ConsumeE(program_ptr, '%', Output[StackMod])) return; // stack mod
    if (ConsumeE(program_ptr, '<', Output[StackCl])) return;  // stack cl
    if (ConsumeE(program_ptr, '>', Output[StackCg])) return;  // stack cg
    // About Stack Equal
    if (Consume(program_ptr, '=', CompileAboutStackEqual)) return;
    // About Stack Ptr
    if (Consume(program_ptr, ':', CompileAboutStackPtr)) return;
    exit(1);
}

void CompileAboutStackEqual(char **program_ptr){
    // Operation
    if (ConsumeE(program_ptr, '=', Output[StackEq])) return; // stack eq
    if (ConsumeE(program_ptr, '<', Output[StackEl])) return; // stack el
    if (ConsumeE(program_ptr, '>', Output[StackEg])) return; // stack eg
    if (ConsumeE(program_ptr, '!', Output[StackNe])) return; // stack ne
    exit(1);
}

void CompileAboutStackPtr(char **program_ptr){
    // Operation
    if (ConsumeE(program_ptr, '^', Output[PushCptr])) return; // push cptr
    if (ConsumeE(program_ptr, '~', Output[PushBptr])) return; // push bptr
    if (ConsumeE(program_ptr, '<', Output[MovCptr])) return;  // mov  cptr
    exit(1);
}