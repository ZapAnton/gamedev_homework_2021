cmake_minimum_required(VERSION 3.16)
project(hello_world VERSION 0.0.1
                    DESCRIPTION "Basic Hello World application"
                    LANGUAGES CXX)
add_executable(hello_world ${CMAKE_CURRENT_SOURCE_DIR}/hello_world.cpp)
target_compile_features(hello_world PUBLIC cxx_std_17)
target_compile_options(hello_world PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:  -Wall
                                                                                            -Werror
                                                                                            -pedantic
                                                                                            -Wextra
                                                                                            -pedantic-errors
                                                                                            -Wconversion
                                                                                            -Wsign-conversion
                                                                                            -Wfatal-errors>
    $<$<CXX_COMPILER_ID:MSVC>: /W4>)
