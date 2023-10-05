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

#include "compiler/output.h"

#include "compiler/output_x86_64.h"

// prototype declaration
void CompileTo_x86_64();

// ========================================

void CompileTo(ARCH architecture){
    switch (architecture) {
        case arch_x86_64:
            CompileTo_x86_64();
            break;
    }
}

void CompileTo_x86_64(){
    // general
    Output = x86_64_Output;
    // c-stack
    OutputStackPush  = x86_64_StackPush;
    // c-tag
    OutputTagDef     = x86_64_TagDef;
    OutputTagJmp     = x86_64_TagJmp;
    // c-fn
    OutputFnCall     = x86_64_FnCall;
    OutputFnDef      = x86_64_FnDef;
    OutputFnPub      = x86_64_FnPub;
}

void (*Output)(Operation operation) = NULL;

// c-stack
void (*OutputStackPush)(int num) = NULL;

// c-tag
void (*OutputTagDef)(char *num_str) = NULL;

void (*OutputTagJmp)(char *num_str) = NULL;

// c-fn
void (*OutputFnDef)(char *num_str) = NULL;

void (*OutputFnCall)(int fid, int argc) = NULL;

void (*OutputFnPub)(int num) = NULL;