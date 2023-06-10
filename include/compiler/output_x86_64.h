#pragma once

#include "compiler/output.h"

// general
void x86_64_Output(Operation operation);

// c-stack
void x86_64_StackPush(int num);

// c-ctrl
void x86_64_CtrlCall(int num);

// c-tag
void x86_64_TagDef(int num);

void x86_64_TagJmp(int num);
