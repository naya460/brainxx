#include "compiler/compiler.h"

#include <stdlib.h>

#include "compiler/consume.h"
#include "compiler/read_num.h"
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
        if (Consume(&program, '$')) {
            if (ReadNum(&program, OutputStackPush)) continue; // push __num__
            if (ConsumeE(&program, '$', StackDup)) continue;  // stack dup
            if (ConsumeE(&program, '+', StackAdd)) continue;  // stack add
            if (ConsumeE(&program, '-', StackSub)) continue;  // stack sub
            if (ConsumeE(&program, '*', StackMul)) continue;  // stack mul
            if (ConsumeE(&program, '/', StackDiv)) continue;  // stack div
            if (ConsumeE(&program, '%', StackMod)) continue;  // stack mod
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
                if (ConsumeE(&program, '<', MovCptr)) continue;  // mov  cptr
                exit(1); // if not found, err and exit
            }
            exit(1); // if not found, err and exit
        }
        if (ConsumeE(&program, '+', StackInc)) continue;
        if (ConsumeE(&program, '-', StackDec)) continue;
        // About Ctrl
        if (Consume(&program, '#')) {
            if (ConsumeE(&program, '<', CtrlRet)) continue;  // ctrl ret
            if (Consume(&program, '>')) {
                if (ReadNum(&program, OutputCtrlCall)) continue; // ctrl call
                exit(1); // if not found, err and exit
            }
            exit(1); // if not found, err and exit
        }
        if (ConsumeE(&program, '<', CtrlSpl)) continue;  // ctrl spl
        if (ConsumeE(&program, '>', CtrlSpr)) continue;  // ctrl spl
        if (ConsumeE(&program, '[', CtrlRepb)) continue; // ctrl repb
        if (ConsumeE(&program, ']', CtrlRepe)) continue; // ctrl repe
        // About Tag
        if (Consume(&program, ':')) {
            if (Consume(&program, ':')) {
                if (ReadNum(&program, OutputTagDef)) continue;
                exit(1); // if not found, err and exit
            }
            if (Consume(&program, '>')) {
                if (ReadNum(&program, OutputTagJmp)) continue;
                exit(1); // if not found, err and exit
            }
            if (ConsumeE(&program, '#', TagAsfn)) continue;
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