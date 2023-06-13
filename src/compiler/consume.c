#include "compiler/consume.h"

#include <stdlib.h>

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