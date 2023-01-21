#pragma once

// general
void x86_64_StartAssembly();

void x86_64_EndAssembly();

// c-stack
void x86_64_StackPush(long num);

void x86_64_StackAdd();

void x86_64_StackSub();

void x86_64_StackMul();

void x86_64_StackDiv();

void x86_64_StackMod();

void x86_64_StackEqual();