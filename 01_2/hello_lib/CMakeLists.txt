cmake_minimum_required(VERSION 3.18)
project(
    hello_world_lib
    VERSION 0.0.1
    DESCRIPTION "Hello World Library"
    LANGUAGES CXX
)
add_library(
    hello_world_lib_static
    STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/hello_world_lib.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/hello_world_lib.cpp
)
add_library(
    hello_world_lib_shared
    SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/include/hello_world_lib.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/hello_world_lib.cpp
)

target_include_directories(hello_world_lib_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(hello_world_lib_shared PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_features(hello_world_lib_static PUBLIC cxx_std_17)
target_compile_features(hello_world_lib_shared PUBLIC cxx_std_17)

target_compile_options(hello_world_lib_static PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:  -Wall
                                                                                            -Werror
                                                                                            -pedantic
                                                                                            -Wextra
                                                                                            -pedantic-errors
                                                                                            -Wconversion
                                                                                            -Wsign-conversion
                                                                                            -Wfatal-errors>
    $<$<CXX_COMPILER_ID:MSVC>: /W4>)
target_compile_options(hello_world_lib_shared PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:  -Wall
                                                                                            -Werror
                                                                                            -pedantic
                                                                                            -Wextra
                                                                                            -pedantic-errors
                                                                                            -Wconversion
                                                                                            -Wsign-conversion
                                                                                            -Wfatal-errors>
    $<$<CXX_COMPILER_ID:MSVC>: /W4>)
