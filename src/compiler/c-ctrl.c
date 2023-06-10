#include "compiler/c-ctrl.h"

#include <stdlib.h>

#include "compiler/consume.h"
#include "compiler/output.h"
#include "compiler/read_num.h"

void CompileAboutCtrlCall(char **program_ptr){
    if (ReadNum(program_ptr, OutputCtrlCall)) return; // ctrl call
    exit(1);
}

void CompileAboutCtrl(char **program_ptr){
    // Operation
    if (ConsumeE(program_ptr, '<', CtrlRet)) return;  // ctrl ret
    if (Consume(program_ptr, '>', CompileAboutCtrlCall)) return;
    exit(1);
}