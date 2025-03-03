cmake_minimum_required(VERSION 3.10)

project(algorithms VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")

include_directories(include)

add_executable(${PROJECT_NAME} src/main.cpp src/node.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin
)

if (CMAKE_CXX_COMPILER_ID MATCHES 'GNU|Clang')
    message(STATUS "Configuring for Linux")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall - Wextra -pedantic)
endif()

