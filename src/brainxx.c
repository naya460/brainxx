#include <stdio.h>

#include "file.h"
#include "error.h"

static char *prog;

void CompileAboutStack(){
    printf("OK\n");
}

void Compile(char *program){
    prog = program;

    while(*prog != '\0') {
        switch (*prog) {
            case '$':
                ++prog;
                CompileAboutStack();
                break;
        }

        // next char
        ++prog;
    }
}

int main(int argc, char **argv){
    if (argc < 2) Error(1, "arguments are less than 2\n");
    Compile(ReadFile(argv[1]));
    putchar('\n');
    return 0;
}