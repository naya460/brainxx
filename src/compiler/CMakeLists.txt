# lib : bxx_x86-64
add_library(bxx_x86_64 STATIC output_x86_64.c)

# lib : output
add_library(output STATIC output.c)
target_link_libraries(output bxx_x86_64)

# lib : compiler
add_library(compiler STATIC compiler.c consume.c c-stack.c c-ctrl.c)
target_link_libraries(compiler output)
