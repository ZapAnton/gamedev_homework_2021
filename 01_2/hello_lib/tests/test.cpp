#include <cassert>
#include <hello_world_lib.h>
#include <string>

int main(int argc, char **argv) {
    const std::string input = argc < 2 ? "test user" : argv[1];
    const auto output = hello(input);
    assert(output);
    return 0;
}
