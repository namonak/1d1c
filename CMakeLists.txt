cmake_minimum_required(VERSION 3.0)

project(1d1c C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_COMPILER "/usr/bin/cc")

include_directories("unity/src")

include_directories("inc")

add_subdirectory("unity")

add_executable(1d1c
        src/boj/no10998.c
        src/boj/no10807.c
        src/boj/no27866.c
        src/boj/no15439.c
        src/boj/no2512.c
        src/boj/no9507.c
        test/boj/main.test.c
        test/boj/no10998.test.c
        test/boj/no10807.test.c
        test/boj/no27866.test.c
        test/boj/no15439.test.c
        test/boj/no2512.test.c
        test/boj/no9507.test.c)

target_link_libraries(1d1c unity)

#target_compile_definitions(1d1c PRIVATE TEST)
target_compile_definitions(1d1c PRIVATE NO9507)

find_program(
        CLANG_FORMAT_EXE
        NAMES clang-format clang-format-14
        DOC "Path to clang-format executable"
)

file(GLOB_RECURSE TARGET_SOURCE_FILES "src/*.c" "src/*.h" "test/*.c" "test/*.h" "inc/*.h")

add_custom_target(
        clang-format
        COMMAND ${CLANG_FORMAT_EXE} -i -style=file:${CMAKE_SOURCE_DIR}/.clang-format ${TARGET_SOURCE_FILES}
)

add_dependencies(1d1c clang-format)
