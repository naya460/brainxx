#include "compiler/output.h"

#include "compiler/output_x86_64.h"

// prototype declaration
void CompileTo_x86_64();

void CompileTo(ARCH architecture){
    switch (architecture) {
        case arch_x86_64:
            CompileTo_x86_64();
            break;
    }
}

void CompileTo_x86_64(){
    // general
    OutputStartAssembly = x86_64_StartAssembly;
    OutputEndAssembly   = x86_64_EndAssembly;
    // c-stack
    OutputStackPush     = x86_64_StackPush;
    OutputStackAdd      = x86_64_StackAdd;
    OutputStackSub      = x86_64_StackSub;
    OutputStackMul      = x86_64_StackMul;
    OutputStackDiv      = x86_64_StackDiv;
    OutputStackMod      = x86_64_StackMod;
}

// general
 void (*OutputStartAssembly)() = NULL;

 void (*OutputEndAssembly)() = NULL;

// c-stack
 void (*OutputStackPush)(long num) = NULL;

 void (*OutputStackAdd)() = NULL;

 void (*OutputStackSub)() = NULL;

 void (*OutputStackMul)() = NULL;

 void (*OutputStackDiv)() = NULL;

 void (*OutputStackMod)() = NULL;