// Copyright 2023 naya460
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <stdbool.h>

// Compile program
void Compile(char *program, bool is_single_file);

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
// | $#        (push arg)
// | $<        (stack cl)
// | $>        (stack cg)
// | About Stack Equal
// | | $==     (stack eq)
// | | $=<     (stack el)
// | | $=>     (stack eg)
// | | $=!     (stack ne)
// | About Bit
// | | $|      (stack or)
// | | $&      (stack and)
// | | $^      (stack xor)
// | | $~      (stacck not)
// | | $[      (stack shl)
// | | $]      (stack shr)
// | About Stack Ptr
// | | $:^     (push cptr)
// | | $:~     (push bptr)
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
// | #~__num__ (fn pub)
// About Ctrl
// | <         (ctrl spl)
// | >         (ctrl spr)
// | [         (ctrl repb)
// | ]         (ctrl repe)
// | @         (mov cptr)
// About IO
// | .         (io cout)
// | ,         (io cin)