#include <stdio.h>

#include "file.h"
#include "error.h"
#include "compiler/compiler.h"

int main(int argc, char **argv){
    if (argc < 3) Error(1, "arguments are less than 2\n");
    Compile(ReadFile(argv[1]));
    QueueContent("\n");
    WriteFile(argv[2]);
    return 0;
}