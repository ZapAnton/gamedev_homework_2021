#ifndef CANVAS_H
#define CANVAS_H
#include "color.hpp"
#include <array>
#include <cstddef>
#include <string>

constexpr size_t BUFFER_HEIGHT = 240;
constexpr size_t BUFFER_WIDTH = 320;
constexpr size_t BUFFER_SIZE = BUFFER_WIDTH * BUFFER_HEIGHT;

class Canvas {
  private:
    std::array<Color, BUFFER_SIZE> pixels;

  public:
    Canvas();
    void set_color(const Color &color);
    void write_to_file(const std::string &filename);
    void read_from_file(const std::string &filename);
    friend bool operator!=(const Canvas &l_canvas, const Canvas &r_canvas);
};
#endif
