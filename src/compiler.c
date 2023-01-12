#include <stdio.h>

// prototype declaration
static void CompileAboutStack();

// declare variables
static char *program;

// ========================================

void Compile(char *program_text){
    program = program_text;

    while(*program != '\0') {
        switch (*program) {
            // About Stack Process
            case '$':
                ++program;
                CompileAboutStack();
                break;
        }

        // next char
        ++program;
    }
}

void CompileAboutStack(){
    printf("OK\n");
}