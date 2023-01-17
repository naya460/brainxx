#include "compiler/compiler.h"

#include "compiler/c-stack.h"
#include "compiler/output.h"

// declare variables
static char *program;

// ========================================

void Compile(char *program_text){
    program = program_text;

    OutputStartAssembly();

    // operation each text in program
    while(*program != '\0') {
        switch (*program) {
            // about stack process
            case '$':
                CompileAboutStack(&program);
                break;
            // move next char
            default:
                ++program;
                break;
        }
    }

    OutputEndAssembly();
}