#include "compiler/output.h"

#include "compiler/output_x86_64.h"

// prototype declaration
void CompileTo_x86_64();

// ========================================

void CompileTo(ARCH architecture){
    switch (architecture) {
        case arch_x86_64:
            CompileTo_x86_64();
            break;
    }
}

void CompileTo_x86_64(){
    // general
    Output[StartAssembly] = x86_64_StartAssembly;
    Output[EndAssembly]   = x86_64_EndAssembly;
    // c-stack
    OutputStackPush       = x86_64_StackPush;
    Output[StackAdd]      = x86_64_StackAdd;
    Output[StackSub]      = x86_64_StackSub;
    Output[StackMul]      = x86_64_StackMul;
    Output[StackDiv]      = x86_64_StackDiv;
    Output[StackMod]      = x86_64_StackMod;
    Output[StackEq]       = x86_64_StackEq;
    Output[StackEl]       = x86_64_StackEl;
    Output[StackEg]       = x86_64_StackEg;
}

void (*Output[EndAssembly + 1])(void) = { NULL };

// c-stack
void (*OutputStackPush)(long num) = NULL;