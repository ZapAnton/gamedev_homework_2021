#include <iostream>
#include "engine.hpp"

namespace psi_engine
{
Engine::Engine(): window{nullptr} {
}

Engine::~Engine(){}

void Engine::initialize(const std::string &game_name) {
    const int SDL_INIT_RESULT = SDL_Init(SDL_INIT_EVERYTHING);
    if (SDL_INIT_RESULT != 0) {
        const std::string error_message{SDL_GetError()};
        std::cerr << "Failed to call SDL_Init: " << error_message << std::endl;
        // return EXIT_FAILURE;
        // TODO: throw exception
    }
    this->window = SDL_CreateWindow(
        game_name.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1024,
        768,
        SDL_WINDOW_SHOWN
    );
    if (this->window == nullptr) {
        const std::string error_message{SDL_GetError()};
        std::cerr << "Failed to call SDL_CreateWindow: " << error_message << std::endl;
        SDL_Quit();
        // return EXIT_FAILURE;
        // TODO: throw exception
    }
}

void Engine::uninitialize() {
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

void Engine::read_input(event &engine_event) {
    SDL_Event sdl_event;
    if (SDL_PollEvent(&sdl_event) != 1) {
        engine_event = event::read_error;
        return;
    }
    switch (sdl_event.type) {
        case SDL_QUIT:
            engine_event = event::exit;
            break;
        default:
            engine_event = event::unknown_event;
            break;
    }
}
} // end namespace psi_engine
