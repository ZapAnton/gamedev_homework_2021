#ifndef ENGINE_H
#define ENGINE_H
#include <SDL.h>
#include <string>
namespace psi_engine
{

enum class event {
    exit,
    unknown_event,
    read_error,
};

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
