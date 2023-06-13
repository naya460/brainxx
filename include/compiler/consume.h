#pragma once

#include <stdbool.h>

#include "compiler/output.h"

// Consume char and call needed function
// 1. Compare current program and expected char
// 2. If current program doesn't match expected char, return false
// 3. Move program pointer to next char
// 4. Return true
bool Consume(char **program_ptr, char expect);

// Consume char and call needed function
// 1. Compare current program and expected char
// 2. If current program doesn't match expected char, return false
// 3. Move program pointer to next char
// 4. Call output function with operation
// 5. Return true
bool ConsumeE(char **program_ptr, char expect, Operation operation);

// Try to read number
// If it was successful, run the function
// and move the program pointer to next of number
bool ConsumeNum(char **program_ptr, void function(int num));

// Try to read number
// If it was successful, return the number with the pointer
// and move the program pointer to next of number
bool ReadNum(char **program_ptr, int *num);