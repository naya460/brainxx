#include "compiler/c-tag.h"

#include <stdlib.h>

#include "compiler/consume.h"
#include "compiler/output.h"
#include "compiler/read_num.h"

// prototype declaration
void CompileAboutTagDef(char **program_ptr);

void CompileAboutTagJmp(char **program_ptr);

// ========================================

void CompileAboutTag(char **program_ptr){
    if (Consume(program_ptr, ':', CompileAboutTagDef)) return;
    if (Consume(program_ptr, '>', CompileAboutTagJmp)) return;
    if (ConsumeE(program_ptr, '#', TagAsfn)) return;
    exit(1);
}

void CompileAboutTagDef(char **program_ptr){
    if (ReadNum(program_ptr, OutputTagDef)) return;
    exit(1);
}

void CompileAboutTagJmp(char **program_ptr){
    if (ReadNum(program_ptr, OutputTagJmp)) return;
    exit(1);
}