# lib : error
add_library(error STATIC error.c)
target_include_directories(error PUBLIC ${PROJECT_SOURCE_DIR}/include)

# exe : bxx
add_executable(bxx brainxx.c)
target_link_libraries(bxx error)
target_include_directories(error PUBLIC ${PROJECT_SOURCE_DIR}/include)