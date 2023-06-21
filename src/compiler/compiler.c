#include "compiler/compiler.h"

#include <stdlib.h>
#include <stdio.h>

#include "compiler/consume.h"
#include "compiler/output.h"
#include "file.h"
#include "error.h"

// declare variables
static char *program;

// ========================================

void Compile(char *program_text, bool is_single_file){
    program = program_text;
    char *line_begin = program;
    int line = 1;

    CompileTo(arch_x86_64);

    Output(Header);
    if (is_single_file) Output(StartAssembly);

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
                CompileError(line, program, line_begin);
            }
            // About Stack Bit
            if (ConsumeE(&program, '|', StackOr)) continue;  // stack or
            if (ConsumeE(&program, '&', StackAnd)) continue; // stack and
            // About Stack Ptr
            if (Consume(&program, ':')) {
                if (ConsumeE(&program, '^', PushCptr)) continue; // push cptr
                if (ConsumeE(&program, '~', PushBptr)) continue; // push bptr
                if (ConsumeE(&program, '+', PtrAdd)) continue;   // ptr add
                if (ConsumeE(&program, '-', PtrSub)) continue;   // ptr sub
                if (ConsumeE(&program, '>', PtrGet)) continue;   // ptr get
                CompileError(line, program, line_begin);
            }
            CompileError(line, program, line_begin);
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
                CompileError(line, program, line_begin);
            }
            if (Consume(&program, '>')) {
                if (ConsumeNum(&program, OutputTagJmp)) continue; // tag jmp
                CompileError(line, program, line_begin);
            }

            CompileError(line, program, line_begin);
        }
        // About Fn
        if (Consume(&program, '#')) {
            if (Consume(&program, ':')) {
                if (ConsumeNum(&program, OutputFnDef)) continue;  // fn def
                CompileError(line, program, line_begin);
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
            // fn pub
            if (Consume(&program, '~')) {
                if (ConsumeNum(&program, OutputFnPub)) continue;
                CompileError(line, program, line_begin);
            }
            CompileError(line, program, line_begin);
        }
        // About IO
        if (ConsumeE(&program, '.', IoCout)) continue;   // io cout
        if (ConsumeE(&program, ',', IoCin)) continue;    // io cin
        // if other character
        if (*program == '\n') {
            line_begin = program + 1;
            if (*line_begin == '\r') ++line_begin;
            ++line;
        }
        ++program;
    }

    if (is_single_file) Output(EndAssembly);
}