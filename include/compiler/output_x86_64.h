#pragma once

#include "compiler/output.h"

// general
void x86_64_Output(Operation operation);

// c-stack
void x86_64_StackPush(int num);

// c-tag
void x86_64_TagDef(int num);

void x86_64_TagJmp(int num);

// c-fn
void x86_64_FnDef(int num);

void x86_64_FnCall(int fid, int argc);

void x86_64_FnPub(int num);