#include <stdio.h>
#include <stdlib.h>

// prototype declaration
static void CompileAboutStack();

// declare variables
static char *program;

// ========================================

void Compile(char *program_text){
    program = program_text;

    while(*program != '\0') {
        switch (*program) {
            // about stack process
            case '$':
                CompileAboutStack();
                break;
            // move next char
            default:
                ++program;
                break;
        }
    }
}

void CompileAboutStack(){
    // move next char of '$'
    ++program;
    // stack number when current char is number
    if ('0' <= *program && *program <= '9') {
        long n = strtol(program, &program, 10);
        printf("%ld\n", n);
    }
}