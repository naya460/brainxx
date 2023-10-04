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

#include "compiler/consume.h"

#include <stdlib.h>
#include <string.h>

bool Consume(char **program_ptr, char expect){
    if (**program_ptr != expect) return false;
    ++(*program_ptr);
    return true;
}

bool ConsumeE(char **program_ptr, char expect, Operation operation){
    if (**program_ptr != expect) return false;
    ++(*program_ptr);
    Output(operation);
    return true;
}

bool ConsumeNum(char **program_ptr, void function(int num)){
    char *program = *program_ptr;
    if ('0' <= *program && *program <= '9') {
        int num = strtol(*program_ptr, program_ptr, 10);
        function(num);
        return true;
    }
    return false;
}

bool ReadNum(char **program_ptr, int *num){
    char *program = *program_ptr;
    if ('0' <= *program && *program <= '9') {
        *num = strtol(*program_ptr, program_ptr, 10);
        return true;
    }
    return false;
}

bool ReadNumStr(char **program_ptr, char **num_str){
    char *program = *program_ptr;
    int count = 0;
    while ('0' <= *(program + count) && *(program + count) <= '9') ++count;
    if (count == 0) return false;
    *num_str = (char*)calloc(sizeof(char), count + 1);
    strncpy(*num_str, program, count);
    program_ptr += count;
    return true;
}

bool ConsumeNumStr(char **program_ptr, void function(char *num_str)){
    char **tmp = (char**)calloc(sizeof(char**), 1);
    bool ret = ReadNumStr(program_ptr, tmp);
    if (ret) function(*tmp);
    return ret;
}
