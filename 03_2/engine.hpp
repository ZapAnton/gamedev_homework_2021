#ifndef ENGINE_H
#define ENGINE_H
#include <SDL.h>
#include <string>
#include <iostream>
namespace psi_engine
{

enum class event {
    exit,
    unknown_event,
    read_error,
    select_pressed,
    select_released,
    button_1_pressed,
    button_1_released,
    up_pressed,
    up_released,
    down_pressed,
    down_released,
    right_pressed,
    right_released,
    left_pressed,
    left_released,
};

std::ostream& operator<<(std::ostream& stream, const event e);

class Engine {
    public:
        Engine();
        ~Engine();
        void initialize(const std::string &game_name);
        void uninitialize();
        void read_input(event &engine_event);
    private:
        SDL_Window* window;
};


} // end namespace psi_engine
#endif
