#include "engine.hpp"
#include <array>
#include <unordered_map>

namespace psi_engine {
Engine::Engine() : window{nullptr} {}

Engine::~Engine() {}

void Engine::initialize(const std::string &game_name) {
    const int SDL_INIT_RESULT = SDL_Init(SDL_INIT_EVERYTHING);
    if (SDL_INIT_RESULT != 0) {
        const std::string error_message{SDL_GetError()};
        std::cerr << "Failed to call SDL_Init: " << error_message << std::endl;
        // return EXIT_FAILURE;
        // TODO: throw exception
    }
    this->window =
        SDL_CreateWindow(game_name.c_str(), SDL_WINDOWPOS_CENTERED,
                         SDL_WINDOWPOS_CENTERED, 1024, 768, SDL_WINDOW_SHOWN);
    if (this->window == nullptr) {
        const std::string error_message{SDL_GetError()};
        std::cerr << "Failed to call SDL_CreateWindow: " << error_message
                  << std::endl;
        SDL_Quit();
        // return EXIT_FAILURE;
        // TODO: throw exception
    }
}

void Engine::uninitialize() {
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

struct event_pair {
    event press_event;
    event release_event;
};

static event map_sdl_to_engine_event(const SDL_Event &sdl_event) {
    const std::unordered_map<SDL_Keycode, const event_pair> GAME_KEYS = {
        {SDLK_SPACE, {event::select_pressed, event::select_released}},
        {SDLK_e, {event::button_1_pressed, event::button_1_released}},
        {SDLK_UP, {event::up_pressed, event::up_released}},
        {SDLK_DOWN, {event::down_pressed, event::down_released}},
        {SDLK_RIGHT, {event::right_pressed, event::right_released}},
        {SDLK_LEFT, {event::left_pressed, event::left_released}},
    };
    const auto key_code = sdl_event.key.keysym.sym;
    if (GAME_KEYS.find(key_code) == GAME_KEYS.end()) {
        return event::unknown_event;
    }
    const auto input_pair = GAME_KEYS.at(key_code);
    const auto engine_event = (sdl_event.type == SDL_KEYDOWN)
                                  ? input_pair.press_event
                                  : input_pair.release_event;
    return engine_event;
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
    case SDL_KEYDOWN:
    case SDL_KEYUP:
        engine_event = map_sdl_to_engine_event(sdl_event);
        break;
    default:
        engine_event = event::unknown_event;
        break;
    }
}

static std::array<std::string, 15> event_names{
    "exit",
    "unknown_event",
    "read_error",
    "select_pressed",
    "select_released",
    "button_1_pressed",
    "button_1_released",
    "up_pressed",
    "up_released",
    "down_pressed",
    "down_released",
    "right_pressed",
    "right_released",
    "left_pressed",
    "left_released",
};

std::ostream &operator<<(std::ostream &stream, const event e) {
    std::uint32_t value = static_cast<std::uint32_t>(e);
    std::uint32_t minimal = static_cast<std::uint32_t>(event::exit);
    std::uint32_t maximal = static_cast<std::uint32_t>(event::left_released);
    if (value < minimal || value > maximal) {
        throw std::runtime_error("too big event value");
    }
    stream << event_names[value];
    return stream;
}
} // end namespace psi_engine
