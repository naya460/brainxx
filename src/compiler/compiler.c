#include "compiler/compiler.h"

#include "compiler/c-stack.h"
#include "compiler/output.h"

// declare variables
static char *program;

// ========================================

bool Consume(char **program_ptr, char expect, void function(char **program)){
    if (**program_ptr != expect) return false;
    ++(*program_ptr);
    function(program_ptr);
    return true;
}

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