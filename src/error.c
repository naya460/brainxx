#include "error.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Error(int return_num, const char *error_text, ...){
    fprintf(stderr, "error %d : ", return_num);
    va_list ap;
    va_start(ap, error_text);
    vfprintf(stderr, error_text, ap);
    va_end(ap);
    fprintf(stderr, "\n");
    exit(return_num);
}

void CompileError(int line, char *program, char *line_begin){
    fprintf(stderr, "error 1 : undefined operation\n");
    fprintf(stderr, "%d | %s\n", line, strtok(line_begin, "\n"));
    for (int i = 0; i < program - line_begin; ++i) {
        putc(' ', stderr);
    }
    fprintf(stderr, "    ^\n");
    exit(1);
}