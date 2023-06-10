#pragma once

#include <stdbool.h>

// Try to read number
// If it was successful, run the function
bool ReadNum(char **program_ptr, void function(int num));