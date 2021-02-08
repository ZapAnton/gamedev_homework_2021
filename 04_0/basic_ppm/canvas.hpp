#ifndef CANVAS_H
#define CANVAS_H
#include "color.hpp"
#include <array>
#include <cstddef>

constexpr size_t BUFFER_HEIGHT = 240;
constexpr size_t BUFFER_WIDTH = 320;
constexpr size_t BUFFER_SIZE = BUFFER_WIDTH * BUFFER_HEIGHT;

class Canvas {
  private:
    std::array<Color, BUFFER_SIZE> pixels;

  public:
    Canvas();
    void set_color(const Color &color);
};
#endif
