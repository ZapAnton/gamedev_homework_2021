cmake_minimum_required(VERSION 3.16)
project(
    sdl_loop_with_engine
    VERSION 0.0.1
    DESCRIPTION "Basic SDL game loop example"
    LANGUAGES CXX
)
add_executable(
    sdl_loop_with_engine
    ${CMAKE_CURRENT_LIST_DIR}/game.cpp
    ${CMAKE_CURRENT_LIST_DIR}/engine.cpp
    ${CMAKE_CURRENT_LIST_DIR}/engine.hpp
)
find_package(
    SDL2
    REQUIRED
)
target_link_libraries(
    sdl_loop_with_engine
    PRIVATE
    SDL2::SDL2
    SDL2::SDL2main
)
target_compile_features(
    sdl_loop_with_engine
    PUBLIC
    cxx_std_17
)
target_compile_options(sdl_loop_with_engine PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:  -Wall
                                                                                            -Werror
                                                                                            -pedantic
                                                                                            -Wextra
                                                                                            -pedantic-errors
                                                                                            -Wconversion
                                                                                            -Wsign-conversion
                                                                                            -Wfatal-errors>
    $<$<CXX_COMPILER_ID:MSVC>: /W4>)
