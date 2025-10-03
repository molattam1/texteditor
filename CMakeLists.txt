cmake_minimum_required(VERSION 3.10)
project(TextEditor VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -pedantic)

include_directories(${PROJECT_SOURCE_DIR}/inc)

set(SOURCES
    src/main.c
    src/custominput.c
    src/dynamicstack.c
)

add_executable(myapp ${SOURCES})
