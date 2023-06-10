#include "compiler/consume.h"

bool Consume(char **program_ptr, char expect, void function(char **program)){
    if (**program_ptr != expect) return false;
    ++(*program_ptr);
    function(program_ptr);
    return true;
}

bool ConsumeE(char **program_ptr, char expect, Operation operation){
    if (**program_ptr != expect) return false;
    ++(*program_ptr);
    Output(operation);
    return true;
}