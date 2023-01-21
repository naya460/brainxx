#include "compiler/compiler.h"

#include "compiler/c-stack.h"
#include "compiler/output.h"

// declare variables
static char *program;

// ========================================

void Compile(char *program_text){
    program = program_text;

    CompileTo(arch_x86_64);

    OutputStartAssembly();

    // Interpret every char in the program
    while(*program != '\0') {
        // About the Stack Process
        if (Consume(&program, '$', CompileAboutStack)) continue;
        ++program;
    }

    OutputEndAssembly();
}