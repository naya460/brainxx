#pragma once

#include <stddef.h>

// Architecture
typedef enum ARCH ARCH;
enum ARCH {
    arch_x86_64,
};

// Output Functions
typedef enum OutputFunctions OFs;
enum OutputFunctions {
    // start of assembly
    StartAssembly = 0,
    // c-stack
    StackAdd,
    StackSub,
    StackMul,
    StackDiv,
    StackMod,
    StackCl,
    StackCg,
    StackEq,
    StackEl,
    StackEg,
    StackNe,
    CtrlRet,
    CtrlRepb,
    CtrlRepe,
    // end of assembly
    EndAssembly
};
extern void (*Output[EndAssembly + 1])(void);

// set up
void CompileTo(ARCH architecture);

// c-stack
extern void (*OutputStackPush)(long num);