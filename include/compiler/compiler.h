#pragma once

#include "compiler/consume.h"

// Compile program
void Compile(char *program);

// --- Operation List ---
// About Stack
// | $__num__ (push __num__)
// | $+       (stack add)
// | $-       (stack sub)
// | $*       (stack mul)
// | $/       (stack div)
// | $%       (stack mod)
// | $<       (stack cl)
// | $>       (stack cg)
// | About Stack Equal
// | | $==    (stack eq)
// | | $=<    (stack el)
// | | $=>    (stack eg)
