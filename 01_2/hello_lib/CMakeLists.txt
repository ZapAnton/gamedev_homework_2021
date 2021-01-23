cmake_minimum_required(VERSION 3.16)
project(
    hello_world_lib
    VERSION 0.0.1
    DESCRIPTION "Hello World Library"
    LANGUAGES CXX
)

enable_testing()

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
add_executable(
    hello_world_lib_test
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp
)

target_include_directories(hello_world_lib_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(hello_world_lib_shared PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_features(hello_world_lib_static PUBLIC cxx_std_17)
target_compile_features(hello_world_lib_shared PUBLIC cxx_std_17)

target_link_libraries(hello_world_lib_test LINK_PUBLIC hello_world_lib_shared)

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

add_test(NAME hello_returns_true_if_no_argument_is_passed COMMAND hello_world_lib_test)
add_test(NAME hello_returns_true_if_valid_string_is_passed COMMAND hello_world_lib_test "cmake test user")
