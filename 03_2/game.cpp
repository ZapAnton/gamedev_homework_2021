/*
#include <unordered_map>

const std::unordered_map<SDL_Keycode, const char*> GAME_KEYS = {
    {SDLK_SPACE, "select"},
    {SDLK_e, "button_1"},
    {SDLK_UP, "up"},
    {SDLK_DOWN, "down"},
    {SDLK_RIGHT, "right"},
    {SDLK_LEFT, "left"},
};

void print_key(const SDL_Event &event) {
    const auto key_code = event.key.keysym.sym;
    if (GAME_KEYS.find(key_code) == GAME_KEYS.end()) {
        return;
    }
    const std::string prefix_message { (event.type == SDL_KEYDOWN) ? "Key pressed: " : "Key released: " };
    std::cout << prefix_message << GAME_KEYS.at(key_code) << std::endl;
}
*/

#include "engine.hpp"

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
                break;
        }
    }
    game_engine.uninitialize();
    return EXIT_SUCCESS;
}
