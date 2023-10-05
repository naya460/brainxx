// Copyright 2023 naya460
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

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
    StackAnd,
    StackXor,
    StackNot,
    StackShl,
    StackShr,
    PushCptr,
    PushBptr,
    MovCptr,
    PtrAdd,
    PtrSub,
    PtrGet,
    PtrSet,
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
extern void (*OutputTagDef)(char *num_str);

extern void (*OutputTagJmp)(char *num_str);

// c-fn
extern void (*OutputFnDef)(char *num_str);

extern void (*OutputFnCall)(char *fid, int argc);

extern void (*OutputFnPub)(char *num_str);