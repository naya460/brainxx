#include "compiler/c-stack.h"

#include <stdlib.h>

#include "compiler/read_num.h"
#include "compiler/consume.h"
#include "compiler/output.h"

// prototype declaration
void CompileAboutStackEqual(char **program_ptr);
void CompileAboutStackPtr(char **program_ptr);

// ========================================

void CompileAboutStack(char **program_ptr){
    // Push number when current char is number (push __num__)
    if (ReadNum(program_ptr, OutputStackPush)) return;
    // Operation
    if (ConsumeE(program_ptr, '$', StackDup)) return; // stack dup
    if (ConsumeE(program_ptr, '+', StackAdd)) return; // stack add
    if (ConsumeE(program_ptr, '-', StackSub)) return; // stack sub
    if (ConsumeE(program_ptr, '*', StackMul)) return; // stack mul
    if (ConsumeE(program_ptr, '/', StackDiv)) return; // stack div
    if (ConsumeE(program_ptr, '%', StackMod)) return; // stack mod
    if (ConsumeE(program_ptr, '<', StackCl)) return;  // stack cl
    if (ConsumeE(program_ptr, '>', StackCg)) return;  // stack cg
    // About Stack Equal
    if (Consume(program_ptr, '=', CompileAboutStackEqual)) return;
    // About Stack Ptr
    if (Consume(program_ptr, ':', CompileAboutStackPtr)) return;
    exit(1);
}

void CompileAboutStackEqual(char **program_ptr){
    // Operation
    if (ConsumeE(program_ptr, '=', StackEq)) return; // stack eq
    if (ConsumeE(program_ptr, '<', StackEl)) return; // stack el
    if (ConsumeE(program_ptr, '>', StackEg)) return; // stack eg
    if (ConsumeE(program_ptr, '!', StackNe)) return; // stack ne
    exit(1);
}

void CompileAboutStackPtr(char **program_ptr){
    // Operation
    if (ConsumeE(program_ptr, '^', PushCptr)) return; // push cptr
    if (ConsumeE(program_ptr, '~', PushBptr)) return; // push bptr
    if (ConsumeE(program_ptr, '<', MovCptr)) return;  // mov  cptr
    exit(1);
}