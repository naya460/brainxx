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

// Try to read number as string
// If it was successful, return the string pointer
// and move the program pointer to next of number string
bool ReadNumStr(char **program_ptr, char **num_str);