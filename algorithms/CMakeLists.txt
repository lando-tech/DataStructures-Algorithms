cmake_minimum_required(VERSION 3.10)

project(algorithms VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

add_executable(${PROJECT_NAME} "src/main.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin
)

if (WIN32)
  set(CMAKE_CXX_COMPILER "C:/mingw64/bin/g++.exe")
  message(STATUS "Configuring for Windows")
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)

elseif (UNIX)
  set(CMAKE_CXX_COMPILER "/usr/bin/g++")
  message(STATUS "Configuring for Linux")
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall - Wextra -pedantic)
  
endif()

enable_testing()
