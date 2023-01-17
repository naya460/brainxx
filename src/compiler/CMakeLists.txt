# lib : output
add_library(output STATIC output.c)

# lib : compiler
add_library(compiler STATIC compiler.c c-stack.c)
target_link_libraries(compiler output)
