#include "compiler/c-ctrl.h"

#include <stdlib.h>

#include "compiler/consume.h"
#include "compiler/output.h"

void CompileAboutCtrl(char **program_ptr){
    // Operation
    if (ConsumeE(program_ptr, '<', Output[CtrlRet])) return; // ctrl ret
    exit(1);
}