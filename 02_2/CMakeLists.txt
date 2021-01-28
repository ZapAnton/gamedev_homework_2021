cmake_minimum_required(VERSION 3.16)
project(
    sdl_static_example
    VERSION 0.0.1
    DESCRIPTION "Example of the staticaly linked SDL2 project"
    LANGUAGES CXX
)
add_executable(
    sdl_static_example
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)
target_compile_features(
    sdl_static_example
    PUBLIC 
    cxx_std_17
)
find_library(
    SDL2_LIB
    REQUIRED
    NAMES libSDL2.a libSDL2main.a
    NO_DEFAULT_PATH
    PATHS ${CMAKE_CURRENT_LIST_DIR}/sdl/build
)
target_link_libraries(
    sdl_static_example
    PRIVATE
    ${SDL2_LIB}
    -lm
    -ldl
    -lpthread
)
target_compile_options(sdl_static_example PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:  -Wall
                                                                                            -Werror
                                                                                            -pedantic
                                                                                            -Wextra
                                                                                            -pedantic-errors
                                                                                            -Wconversion
                                                                                            -Wsign-conversion
                                                                                            -Wfatal-errors>
    $<$<CXX_COMPILER_ID:MSVC>: /W4>)
