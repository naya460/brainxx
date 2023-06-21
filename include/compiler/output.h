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
    // header of assembly
    Header,
    // start of assembly
    StartAssembly,
    // c-stack
    StackInc,
    StackDec,
    StackAdd,
    StackSub,
    StackMul,
    StackDiv,
    StackMod,
    StackDup,
    PushArg,
    StackCl,
    StackCg,
    StackEq,
    StackEl,
    StackEg,
    StackNe,
    StackOr,
    PushCptr,
    PushBptr,
    MovCptr,
    PtrAdd,
    PtrSub,
    PtrGet,
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

extern void (*OutputFnPub)(int num);