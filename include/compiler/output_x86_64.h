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

void x86_64_StackCl();

void x86_64_StackCg();

void x86_64_StackInc();

void x86_64_StackDec();

void x86_64_StackEq();

void x86_64_StackEl();

void x86_64_StackEg();

void x86_64_StackNe();

void x86_64_PushCptr();

void x86_64_PushBptr();

void x86_64_MovCptr();

// c-ctrl
void x86_64_CtrlRet();

void x86_64_CtrlSpl();

void x86_64_CtrlSpr();

void x86_64_CtrlRepb();

void x86_64_CtrlRepe();

// c-io
void x86_64_IoCout();

void x86_64_IoCin();