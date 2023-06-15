#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "file.h"
#include "error.h"
#include "compiler/compiler.h"

int main(int argc, char **argv){
    // local variables
    char *input_file = NULL;
    char *output_file = "output.s";

    // read args
    bool is_output = false;
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-o") == 0) {
            is_output = true;
            continue;
        }
        if (is_output) {
            output_file = argv[i];
            is_output = false;
            continue;
        }
        input_file = argv[i];
    }

    // check error
    if (input_file == NULL) {
        Error(1, "no input file");
    }
    if (is_output == true) {
        Error(1, "No file path after -o");
    }

    // compile and output
    Compile(ReadFile(input_file));
    QueueContent("\n");
    WriteFile(output_file);
    return 0;
}