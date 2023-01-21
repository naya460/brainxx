#pragma once

#include <stdbool.h>

// Consume char and call needed function
// 1. Compare current program and expected char
// 2. If current program doesn't match expected char, return false
// 3. Move program pointer to next char
// 4. Call the function with program_ptr
// 5. Return true
bool Consume(char **program_ptr, char expect, void function(char **program_ptr));

// Compile program
void Compile(char *program);