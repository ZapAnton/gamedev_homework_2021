cmake_minimum_required(VERSION 3.16)
project(
    hello_world_bin
    VERSION 0.0.1
    DESCRIPTION "Hello World Binary with linked Hello World Library"
    LANGUAGES CXX
)
add_executable(hello_world_bin_shared ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
add_executable(hello_world_bin_static ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

target_compile_features(hello_world_bin_shared PUBLIC cxx_std_17)
target_compile_features(hello_world_bin_static PUBLIC cxx_std_17)

target_link_libraries(hello_world_bin_static PUBLIC hello_world_lib_static)
target_link_libraries(hello_world_bin_shared PUBLIC hello_world_lib_shared)

target_link_options(hello_world_bin_static PRIVATE -static)
