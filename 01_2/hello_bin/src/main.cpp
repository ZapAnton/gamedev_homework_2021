#include <hello_world_lib.h>
#include <string>

int main(int, char **) {
    const std::string user_name{"my cool user"};
    const auto is_hello_successfull = hello(user_name);
    const auto return_code = is_hello_successfull ? EXIT_SUCCESS : EXIT_FAILURE;
    return return_code;
}
