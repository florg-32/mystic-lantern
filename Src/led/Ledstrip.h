#ifndef LANTERN_LEDSTRIP_H
#define LANTERN_LEDSTRIP_H

#include <cstdint>
#include <array>

#include "color.h"

template<uint16_t n_leds,
         uint8_t low_time,
         uint8_t high_time>
class Ledstrip {
public:
    Ledstrip() = default;

    constexpr Color& operator[](uint16_t n) {
        return colors[n];
    }

    void update() {
        uint16_t ind = 0;
        auto set_bits = [&](uint8_t col) {
            for (uint16_t i = 0; i < 8; i++) {
                array[ind] = low_time + ((col >> i) & 0x01) * (high_time - low_time);
                ind++;
            }
        };
        for (auto& c : colors) {
            set_bits(c.g);
            set_bits(c.r);
            set_bits(c.b);
        }
    }

    constexpr uint16_t* get_array_address() {
        return array.data();
    }

    static constexpr uint16_t array_length = n_leds * 24;
private:
    std::array<Color, n_leds> colors {};
    std::array<uint16_t, array_length> array {};
};


#endif //LANTERN_LEDSTRIP_H
