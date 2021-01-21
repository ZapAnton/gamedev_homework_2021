#include <iostream>

int main(int, char**) {
    std::cout << "Hello, World!" << std:: endl;
    const auto cout_result = std::cout.good() ? EXIT_SUCCESS : EXIT_FAILURE;
    return cout_result;
}
