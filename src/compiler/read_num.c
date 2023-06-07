#include "compiler/read_num.h"

#include <stdlib.h>

bool ReadNum(char **program_ptr, void function(long num)){
    char *program = *program_ptr;
    if ('0' <= *program && *program <= '9') {
        long num = strtol(program, &program, 10);
        function(num);
        return true;
    } else {
        return false;
    }
}