#pragma once

// Compile program
void Compile(char *program);

// --- Operation List ---
// About Stack
// | $__num__  (push __num__)
// | $$        (stack dup)
// | $+        (stack add)
// | $-        (stack sub)
// | $*        (stack mul)
// | $/        (stack div)
// | $%        (stack mod)
// | $<        (stack cl)
// | $>        (stack cg)
// | +         (stack inc)
// | -         (stack dec)
// | About Stack Equal
// | | $==     (stack eq)
// | | $=<     (stack el)
// | | $=>     (stack eg)
// | | $=!     (stack ne)
// | About Stack Ptr
// | | $:^     (push cptr)
// | | $:~     (push bptr)
// | | $:<     (mov cptr)
// About Ctrl
// | #<        (ctrl ret)
// | #>__num__ (ctrl call)
// | <         (ctrl spl)
// | >         (ctrl spr)
// | [         (ctrl repb)
// | ]         (ctrl repe)
// About Tag
// | ::__num__ (tag def)
// | :>__num__ (tag jmp)
// | :#        (tag asfn)
// About IO
// | .         (io cout)
// | ,         (io cin)