#include <iostream>
#include <string>

bool hello(const std::string &user_name) {
    const auto greet_target = user_name.empty() ? "World" : user_name;
    std::cout << "Hello, " << greet_target << std::endl;
    const auto cout_result = std::cout.good();
    return cout_result;
}
