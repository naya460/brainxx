#pragma once

#include <stddef.h>

// architecture
typedef enum ARCH ARCH;
enum ARCH {
    arch_x86_64,
};

// set up
void CompileTo(ARCH architecture);

// general
extern void (*OutputStartAssembly)();

extern void (*OutputEndAssembly)();

// c-stack
extern void (*OutputStackPush)(long num);

extern void (*OutputStackAdd)();

extern void (*OutputStackSub)();

extern void (*OutputStackMul)();

extern void (*OutputStackDiv)();

extern void (*OutputStackMod)();

extern void (*OutputStackEq)();

extern void (*OutputStackEl)();

extern void (*OutputStackEg)();