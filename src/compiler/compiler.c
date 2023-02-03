#include "compiler/compiler.h"

#include "compiler/consume.h"
#include "compiler/c-stack.h"
#include "compiler/c-ctrl.h"
#include "compiler/output.h"

// declare variables
static char *program;

// ========================================

void Compile(char *program_text){
    program = program_text;

    CompileTo(arch_x86_64);

    Output[StartAssembly]();

    // Interpret every char in the program
    while(*program != '\0') {
        // About Stack
        if (Consume(&program, '$', CompileAboutStack)) continue;
        // About Ctrl
        if (Consume(&program, '#', CompileAboutCtrl)) continue;
        if (ConsumeE(&program, '<', Output[CtrlSpl])) continue;  // ctrl spl
        if (ConsumeE(&program, '>', Output[CtrlSpr])) continue;  // ctrl spl
        if (ConsumeE(&program, '[', Output[CtrlRepb])) continue; // ctrl repb
        if (ConsumeE(&program, ']', Output[CtrlRepe])) continue; // ctrl repe
        ++program;
    }

    Output[EndAssembly]();
}