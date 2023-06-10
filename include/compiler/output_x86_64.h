#pragma once

#include "compiler/output.h"

// general
void x86_64_Output(Operation operation);

// c-stack
void x86_64_StackPush(long num);

// c-ctrl
void x86_64_CtrlCall(long num);

// c-tag
void x86_64_TagDef(long num);

void x86_64_TagJmp(long num);
