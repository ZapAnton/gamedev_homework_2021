#include <iostream>
#include <string>
#include <SDL.h>
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

int main() {
    const int SDL_INIT_RESULT = SDL_Init(SDL_INIT_EVERYTHING);
    if (SDL_INIT_RESULT != 0) {
        const std::string error_message{SDL_GetError()};
        std::cerr << "Failed to call SDL_Init: " << error_message << std::endl;
        return EXIT_FAILURE;
    }
    SDL_Window* const window = SDL_CreateWindow(
        "Stay Grey",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1024,
        768,
        SDL_WINDOW_SHOWN
    );
    if (window == nullptr) {
        const std::string error_message{SDL_GetError()};
        std::cerr << "Failed to call SDL_CreateWindow: " << error_message << std::endl;
        SDL_Quit();
        return EXIT_FAILURE;
    }
    bool game_is_running = true;
    while (game_is_running) {
        SDL_Event event;
        if (SDL_PollEvent(&event) != 1) {
            continue;
        }
        switch (event.type) {
            case SDL_QUIT:
                game_is_running = false;
                break;
            case SDL_KEYUP:
            case SDL_KEYDOWN:
                print_key(event);
                break;
            default:
                break;
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
