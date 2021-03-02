#include "engine.hpp"
#include <iostream>

int main() {
    psi_engine::Engine game_engine;
    game_engine.initialize("Stay Grey"); // TODO: Add exception handling
    bool game_is_running = true;
    while (game_is_running) {
        psi_engine::event event;
        game_engine.read_input(event);
        if (event == psi_engine::event::read_error) {
            continue;
        }
        switch (event) {
        case psi_engine::event::exit:
            game_is_running = false;
            break;
        default:
            std::cout << "Current event: " << event << std::endl;
            break;
        }
    }
    game_engine.uninitialize();
    return EXIT_SUCCESS;
}
