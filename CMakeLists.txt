cmake_minimum_required(VERSION 3.10)
project(TextEditor VERSION 1.0.0 LANGUAGES C)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Add compiler warnings
add_compile_options(-Wall -Wextra -pedantic)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/inc)

# Source files
set(SOURCES
    src/main.c
    src/custominput.c
    src/dynamicstack.c
)

# Create executable
add_executable(myapp ${SOURCES})
