#include <iostream>
#include <string>
#include <SDL.h>

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
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
