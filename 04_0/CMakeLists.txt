cmake_minimum_required(VERSION 3.16)
project(
    render_basic
    VERSION 0.0.1
    DESCRIPTION "Basic software render exercises"
    LANGUAGES CXX
)
add_executable(
    basic_ppm
    ${CMAKE_CURRENT_SOURCE_DIR}/basic_ppm/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basic_ppm/canvas.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basic_ppm/canvas.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basic_ppm/color.hpp
)
target_compile_features(
    basic_ppm
    PUBLIC
    cxx_std_17
)
target_compile_options(basic_ppm PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:  -Wall
                                                                                            -Werror
                                                                                            -pedantic
                                                                                            -Wextra
                                                                                            -pedantic-errors
                                                                                            -Wconversion
                                                                                            -Wsign-conversion
                                                                                            -Wfatal-errors>
    $<$<CXX_COMPILER_ID:MSVC>: /W4>)
