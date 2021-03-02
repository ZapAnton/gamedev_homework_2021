cmake_minimum_required(VERSION 3.16)
project(
    sdl_loop_with_engine_dll
    VERSION 0.0.1
    DESCRIPTION "Basic SDL game loop with separate engine library"
    LANGUAGES CXX
)
add_library(
    engine
    SHARED
    ${CMAKE_CURRENT_LIST_DIR}/engine.cpp
    ${CMAKE_CURRENT_LIST_DIR}/engine.hpp
)
target_compile_features(
    engine
    PUBLIC
    cxx_std_17
)
find_package(
    SDL2
    REQUIRED
)
target_link_libraries(
    engine
    PRIVATE
    SDL2::SDL2
    SDL2::SDL2main
)
add_executable(
    game
    ${CMAKE_CURRENT_LIST_DIR}/game.cpp
)
target_compile_features(
    game
    PUBLIC
    cxx_std_17
)
target_link_libraries(
    game
    PRIVATE
    engine
)
target_compile_options(game PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:  -Wall
                                                                                            -Werror
                                                                                            -pedantic
                                                                                            -Wextra
                                                                                            -pedantic-errors
                                                                                            -Wconversion
                                                                                            -Wsign-conversion
                                                                                            -Wfatal-errors>
    $<$<CXX_COMPILER_ID:MSVC>: /W4>)
target_compile_options(engine PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:  -Wall
                                                                                            -Werror
                                                                                            -pedantic
                                                                                            -Wextra
                                                                                            -pedantic-errors
                                                                                            -Wconversion
                                                                                            -Wsign-conversion
                                                                                            -Wfatal-errors>
    $<$<CXX_COMPILER_ID:MSVC>: /W4>)
