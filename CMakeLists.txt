cmake_minimum_required(VERSION 3.0)
project(ci-playground)

set(CMAKE_CXX_STANDARD_REQUIRED 14)

if(MINGW)
  find_package(Boost COMPONENTS regex system filesystem REQUIRED)
endif()

add_executable(playground playground.c++)
message(STATUS "CMake Platform ID: ${CMAKE_CXX_PLATFORM_ID}")
target_compile_options(playground PUBLIC $<$<CXX_COMPILER_ID:Clang>:-std=c++14>)
target_link_libraries(playground $<$<AND:$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Intel>>,$<NOT:$<PLATFORM_ID:Windows>>>:-lstdc++fs>
                                 $<$<AND:$<CXX_COMPILER_ID:Clang>,$<NOT:$<OR:$<PLATFORM_ID:Windows>,$<PLATFORM_ID:MinGW>>>>:-lc++experimental>)
if(MINGW)
  target_link_libraries(playground Boost::system Boost::regex Boost::filesystem)
endif()

if((NOT MSVC) OR (${CMAKE_CXX_COMPILER_ID} MATCHES "Clang"))
  set_source_files_properties(playground.c++ PROPERTIES COMPILE_FLAGS -mssse3)
endif()
set(CMAKE_VERBOSE_MAKEFILE TRUE)
