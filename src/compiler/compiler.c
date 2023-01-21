#include "compiler/compiler.h"

#include "compiler/c-stack.h"
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
        ++program;
    }

    Output[EndAssembly]();
}