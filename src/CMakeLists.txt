# set include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# lib : error
add_library(error STATIC error.c)

# lib : file
add_library(file STATIC file.c)

# lib : compiler
add_library(compiler STATIC compiler.c)

# exe : bxx
add_executable(bxx brainxx.c)
target_link_libraries(bxx error file compiler)
