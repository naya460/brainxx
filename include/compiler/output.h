#pragma once

#include <stddef.h>

// Architecture
typedef enum ARCH ARCH;
enum ARCH {
    arch_x86_64,
};

// Operations
typedef enum Operation Operation;
enum Operation {
    // start of assembly
    StartAssembly = 0,
    // c-stack
    StackInc,
    StackDec,
    StackDup,
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
    PushCptr,
    PushBptr,
    MovCptr,
    // c-fn
    FnRet,
    // c-ctrl
    CtrlSpl,
    CtrlSpr,
    CtrlRepb,
    CtrlRepe,
    // c-io
    IoCout,
    IoCin,
    // end of assembly
    EndAssembly
};
extern void (*Output)(Operation operation);

// set up
void CompileTo(ARCH architecture);

// c-stack
extern void (*OutputStackPush)(int num);

// c-tag
extern void (*OutputTagDef)(int num);

extern void (*OutputTagJmp)(int num);

// c-fn
extern void (*OutputFnDef)(int num);

extern void (*OutputFnCall)(int fid, int argc);