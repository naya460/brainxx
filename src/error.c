// Copyright 2023 naya460
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

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