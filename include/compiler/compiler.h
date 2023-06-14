#pragma once

// Compile program
void Compile(char *program);

// --- Operation List ---
// About Stack
// | +         (stack inc)
// | -         (stack dec)
// | $__num__  (push __num__)
// | $+        (stack add)
// | $-        (stack sub)
// | $*        (stack mul)
// | $/        (stack div)
// | $%        (stack mod)
// | $$        (stack dup)
// | $<        (stack cl)
// | $>        (stack cg)
// | About Stack Equal
// | | $==     (stack eq)
// | | $=<     (stack el)
// | | $=>     (stack eg)
// | | $=!     (stack ne)
// | About Stack Ptr
// | | $:^     (push cptr)
// | | $:~     (push bptr)
// | | $:<     (mov cptr)
// | | $:+     (ptr add)
// | | $:-     (ptr sub)
// | | $:>     (ptr get)
// About Tag
// | ::__num__ (tag def)
// | :>__num__ (tag jmp)
// About Fn
// | #:__num__ (fn def)
// | #>__num__:__num__ (fn call)
// | #<        (fn ret)
// About Ctrl
// | <         (ctrl spl)
// | >         (ctrl spr)
// | [         (ctrl repb)
// | ]         (ctrl repe)
// About IO
// | .         (io cout)
// | ,         (io cin)