#include <stdio.h>

#include "file.h"
#include "error.h"

void Compile(char *program){
    while(*program != '\0') {
        putchar(*program);
        ++program;
    }
}

int main(int argc, char **argv){
    if (argc < 2) Error(1, "arguments are less than 2\n");
    Compile(ReadFile(argv[1]));
    putchar('\n');
    return 0;
}