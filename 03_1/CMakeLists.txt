cmake_minimum_required(VERSION 3.16)
project(
    sdl_loop
    VERSION 0.0.1
    DESCRIPTION "Basic SDL game loop example"
    LANGUAGES CXX
)
add_executable(
    sdl_loop
    ${CMAKE_CURRENT_LIST_DIR}/game.cpp
)
find_package(
    SDL2
    REQUIRED
)
target_link_libraries(
    sdl_loop
    PRIVATE
    SDL2::SDL2
    SDL2::SDL2main
)
target_compile_features(
    sdl_loop
    PUBLIC
    cxx_std_17
)
target_compile_options(sdl_loop PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:  -Wall
                                                                                            -Werror
                                                                                            -pedantic
                                                                                            -Wextra
                                                                                            -pedantic-errors
                                                                                            -Wconversion
                                                                                            -Wsign-conversion
                                                                                            -Wfatal-errors>
    $<$<CXX_COMPILER_ID:MSVC>: /W4>)
