#include "compiler/c-stack.h"

#include <stdio.h>
#include <stdlib.h>

#include "compiler/output.h"

void CompileAboutStack(char **program_ptr){
    char *program = *program_ptr;
    // move next char of '$'
    ++program;
    // push number when current char is number
    if ('0' <= *program && *program <= '9') {
        long num = strtol(program, &program, 10);
        OutputStackPush(num);
    }
    // single operation
    switch (*program) {
        case '+':
            OutputStackAdd();
            ++program;
            break;
        case '-':
            OutputStackSub();
            ++program;
            break;
    }
    *program_ptr = program;
}