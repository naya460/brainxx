#include "compiler/compiler.h"

#include "compiler/consume.h"
#include "compiler/c-stack.h"
#include "compiler/c-ctrl.h"
#include "compiler/c-tag.h"
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
        if (Consume(&program, '$', CompileAboutStack)) continue;
        if (ConsumeE(&program, '+', StackInc)) continue;
        if (ConsumeE(&program, '-', StackDec)) continue;
        // About Ctrl
        if (Consume(&program, '#', CompileAboutCtrl)) continue;
        if (ConsumeE(&program, '<', CtrlSpl)) continue;  // ctrl spl
        if (ConsumeE(&program, '>', CtrlSpr)) continue;  // ctrl spl
        if (ConsumeE(&program, '[', CtrlRepb)) continue; // ctrl repb
        if (ConsumeE(&program, ']', CtrlRepe)) continue; // ctrl repe
        // About Tag
        if (Consume(&program, ':', CompileAboutTag)) continue;
        // About IO
        if (ConsumeE(&program, '.', IoCout)) continue;   // io cout
        if (ConsumeE(&program, ',', IoCin)) continue;    // io cin
        ++program;
    }

    Output(EndAssembly);
}