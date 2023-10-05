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

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "file.h"
#include "error.h"
#include "compiler/compiler.h"

void print_version(){
    printf("bxx 0.4.0\n");
    printf("The bxx is a compiler for brainxx (version 0.4).\n");
    printf("Copyright 2023 naya460\n");
    printf("License: Apache License Version 2.0\n");
}

int main(int argc, char **argv){
    // local variables
    char *input_file = NULL;
    char *output_file = "output.s";
    bool is_single_file = false;

    // read args
    bool is_output = false;
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "--version") == 0) {
            print_version();
            return 0;
        }
        if (strcmp(argv[i], "-s") == 0) {
            is_single_file = true;
            continue;
        }
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
        print_version();
        return 0;
    }
    if (is_output == true) {
        Error(1, "No file path after -o");
    }

    // compile and output
    Compile(ReadFile(input_file), is_single_file);
    QueueContent("\n");
    WriteFile(output_file);
    return 0;
}