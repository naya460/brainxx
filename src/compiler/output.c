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
    Output[StackCl]       = x86_64_StackCl;
    Output[StackCg]       = x86_64_StackCg;
    Output[StackInc]      = x86_64_StackInc;
    Output[StackDec]      = x86_64_StackDec;
    Output[StackEq]       = x86_64_StackEq;
    Output[StackEl]       = x86_64_StackEl;
    Output[StackEg]       = x86_64_StackEg;
    Output[StackNe]       = x86_64_StackNe;
    Output[PushCptr]      = x86_64_PushCptr;
    Output[PushBptr]      = x86_64_PushBptr;
    Output[MovCptr]       = x86_64_MovCptr;
    Output[CtrlRet]       = x86_64_CtrlRet;
    Output[CtrlSpl]       = x86_64_CtrlSpl;
    Output[CtrlSpr]       = x86_64_CtrlSpr;
    Output[CtrlRepb]      = x86_64_CtrlRepb;
    Output[CtrlRepe]      = x86_64_CtrlRepe;
}

void (*Output[EndAssembly + 1])(void) = { NULL };

// c-stack
void (*OutputStackPush)(long num) = NULL;