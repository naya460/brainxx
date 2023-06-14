#include "compiler/compiler.h"

#include <stdlib.h>

#include "compiler/consume.h"
#include "compiler/output.h"

// declare variables
static char *program;

// ========================================

void Compile(char *program_text){
    program = program_text;

    CompileTo(arch_x86_64);

    Output(StartAssembly);

    // Interpret every char in the program
    while(*program != '\0') {
        // About Stack
        if (ConsumeE(&program, '+', StackInc)) continue;
        if (ConsumeE(&program, '-', StackDec)) continue;
        if (Consume(&program, '$')) {
            if (ConsumeNum(&program, OutputStackPush)) continue; // push __num__
            if (ConsumeE(&program, '+', StackAdd)) continue;  // stack add
            if (ConsumeE(&program, '-', StackSub)) continue;  // stack sub
            if (ConsumeE(&program, '*', StackMul)) continue;  // stack mul
            if (ConsumeE(&program, '/', StackDiv)) continue;  // stack div
            if (ConsumeE(&program, '%', StackMod)) continue;  // stack mod
            if (ConsumeE(&program, '$', StackDup)) continue;  // stack dup
            if (ConsumeE(&program, '#', PushArg)) continue;   // push arg
            if (ConsumeE(&program, '<', StackCl)) continue;   // stack cl
            if (ConsumeE(&program, '>', StackCg)) continue;   // stack cg
            // About Stack Equal
            if (Consume(&program, '=')) {                    
                if (ConsumeE(&program, '=', StackEq)) continue; // stack eq
                if (ConsumeE(&program, '<', StackEl)) continue; // stack el
                if (ConsumeE(&program, '>', StackEg)) continue; // stack eg
                if (ConsumeE(&program, '!', StackNe)) continue; // stack ne
                exit(1); // if not found, err and exit
            }
            // About Stack Ptr
            if (Consume(&program, ':')) {
                if (ConsumeE(&program, '^', PushCptr)) continue; // push cptr
                if (ConsumeE(&program, '~', PushBptr)) continue; // push bptr
                if (ConsumeE(&program, '+', PtrAdd)) continue;   // ptr add
                if (ConsumeE(&program, '-', PtrSub)) continue;   // ptr sub
                if (ConsumeE(&program, '>', PtrGet)) continue;   // ptr get
                exit(1); // if not found, err and exit
            }
            exit(1); // if not found, err and exit
        }
        // About Ctrl
        if (ConsumeE(&program, '<', CtrlSpl)) continue;  // ctrl spl
        if (ConsumeE(&program, '>', CtrlSpr)) continue;  // ctrl spl
        if (ConsumeE(&program, '[', CtrlRepb)) continue; // ctrl repb
        if (ConsumeE(&program, ']', CtrlRepe)) continue; // ctrl repe
        if (ConsumeE(&program, '@', MovCptr)) continue;  // mov  cptr
        // About Tag
        if (Consume(&program, ':')) {
            if (Consume(&program, ':')) {
                if (ConsumeNum(&program, OutputTagDef)) continue; // tag def
                exit(1); // if not found, err and exit
            }
            if (Consume(&program, '>')) {
                if (ConsumeNum(&program, OutputTagJmp)) continue; // tag jmp
                exit(1); // if not found, err and exit
            }

            exit(1); // if not found, err and exit
        }
        // About Fn
        if (Consume(&program, '#')) {
            if (Consume(&program, ':')) {
                if (ConsumeNum(&program, OutputFnDef)) continue;  // fn def
                exit(1); // if not found, err and exit
            }
            // fn call
            if (Consume(&program, '>')) {
                int fid = 0, argc = 0;
                if (!ReadNum(&program, &fid)) exit(1);
                if (!Consume(&program, ':')) exit(1);
                if (!ReadNum(&program, &argc)) exit(1);
                OutputFnCall(fid, argc);
                continue;
            }
            if (ConsumeE(&program, '<', FnRet)) continue;      // fn ret
            exit(1); // if not found, err and exit
        }
        // About IO
        if (ConsumeE(&program, '.', IoCout)) continue;   // io cout
        if (ConsumeE(&program, ',', IoCin)) continue;    // io cin
        // if other character
        ++program;
    }

    Output(EndAssembly);
}