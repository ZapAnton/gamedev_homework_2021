cmake_minimum_required(VERSION 3.16)
project(
    sdl_dynamic_example
    VERSION 0.0.1
    DESCRIPTION "Example of the dynamically linked SDL2 project"
    LANGUAGES CXX
)
add_executable(
    sdl_dynamic_example
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)
target_compile_features(
    sdl_dynamic_example
    PUBLIC
    cxx_std_17
)
set(
    SDL2_DIR
    ${CMAKE_CURRENT_LIST_DIR}/sdl/build
)
find_package(
    SDL2
    REQUIRED
)
target_link_libraries(
    sdl_dynamic_example
    PRIVATE
    SDL2::SDL2 SDL2::SDL2main
)
target_compile_options(sdl_dynamic_example PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:  -Wall
                                                                                            -Werror
                                                                                            -pedantic
                                                                                            -Wextra
                                                                                            -pedantic-errors
                                                                                            -Wconversion
                                                                                            -Wsign-conversion
                                                                                            -Wfatal-errors>
    $<$<CXX_COMPILER_ID:MSVC>: /W4>)
