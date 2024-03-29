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

#include "compiler/output.h"

// general
void x86_64_Output(Operation operation);

// c-stack
void x86_64_StackPush(int num);

// c-tag
void x86_64_TagDef(char *num_str);

void x86_64_TagJmp(char *num_str);

// c-fn
void x86_64_FnDef(char *num_str);

void x86_64_FnCall(char *fid, int argc);

void x86_64_FnPub(char *num_str);