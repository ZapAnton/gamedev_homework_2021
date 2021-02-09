#ifndef COLOR_H
#define COLOR_H
#include <cstdint>

struct Color {
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
    bool operator==(const Color &other) const {
        return this->r == other.r && this->b == other.b && this->g == other.g;
    }
};
#endif
