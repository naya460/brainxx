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
}

void (*Output)(Operation operation) = NULL;

// c-stack
void (*OutputStackPush)(int num) = NULL;

// c-tag
void (*OutputTagDef)(int num) = NULL;

void (*OutputTagJmp)(int num) = NULL;

// c-fn
void (*OutputFnDef)(int num) = NULL;

void (*OutputFnCall)(int fid, int argc) = NULL;