#pragma once

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
// | | $=!    (stack ne)
// | About Stack Ptr
// | | $:^    (push cptr)
// | | $:~    (push bptr)
// | | $:<    (mov cptr)
// About Ctrl
// | #<       (ctrl ret)
// | <        (ctrl spl)
// | >        (ctrl spr)
// | [        (ctrl repb)
// | ]        (ctrl repe)