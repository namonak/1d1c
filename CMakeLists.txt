cmake_minimum_required(VERSION 3.0)

project(1d1c C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_COMPILER "/usr/bin/clang")

include_directories("unity/src")

include_directories("inc")

add_subdirectory("unity")

add_executable(1d1c
        src/boj/no10998.c
        src/boj/no10807.c
        test/boj/main.test.c
        test/boj/no10998.test.c
        test/boj/no10807.test.c)

target_link_libraries(1d1c unity)

target_compile_definitions(1d1c PRIVATE TEST)
#target_compile_definitions(1d1c PRIVATE NO10807)
