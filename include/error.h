#pragma once

#include <stdarg.h>

// display error_text and exit program
void Error(int return_num, const char *error_text, ...);

void CompileError(int line, char *program, char *line_begin);