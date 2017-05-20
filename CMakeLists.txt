cmake_minimum_required(VERSION 3.0)
project(ci-playground)

set(CMAKE_CXX_STANDARD_REQUIRED 14)

add_executable(playground playground.c++)
target_compile_options(playground PUBLIC $<$<CXX_COMPILER_ID:Clang>:-std=c++14>)
