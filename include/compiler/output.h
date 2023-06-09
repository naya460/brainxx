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
    StackDup,
    StackAdd,
    StackSub,
    StackMul,
    StackDiv,
    StackMod,
    StackCl,
    StackCg,
    StackInc,
    StackDec,
    StackEq,
    StackEl,
    StackEg,
    StackNe,
    PushCptr,
    PushBptr,
    MovCptr,
    CtrlRet,
    CtrlSpl,
    CtrlSpr,
    CtrlRepb,
    CtrlRepe,
    TagAsfn,
    IoCout,
    IoCin,
    // end of assembly
    EndAssembly
};
extern void (*Output[EndAssembly + 1])(void);

// set up
void CompileTo(ARCH architecture);

// c-stack
extern void (*OutputStackPush)(long num);

// c-ctrl
extern void (*OutputCtrlCall)(long num);

// c-tag
extern void (*OutputTagDef)(long num);

extern void (*OutputTagJmp)(long num);