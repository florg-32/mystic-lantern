#ifndef LANTERN_COLOR_H
#define LANTERN_COLOR_H

#include <cstdint>

struct Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;

    Color(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) {}
    Color() = default;


};

#endif //LANTERN_COLOR_H
