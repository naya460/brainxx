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
    OutputStackPush       = x86_64_StackPush;
    // c-ctrl
    OutputCtrlCall        = x86_64_CtrlCall;
    // c-tag
    OutputTagDef          = x86_64_TagDef;
    OutputTagJmp          = x86_64_TagJmp;
}

void (*Output)(Operation operation) = NULL;

// c-stack
void (*OutputStackPush)(long num) = NULL;

// c-ctrl
void (*OutputCtrlCall)(long num) = NULL;

// c-tag
void (*OutputTagDef)(long num) = NULL;

void (*OutputTagJmp)(long num) = NULL;