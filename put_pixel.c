#include "main.h"

void put_pixel(uint32_t *buffer, int x, int y, uint32_t hex_color) {
    if (x >= 0 && x <= WIDTH) {
        if (y >= 0 && y <= HEIGHT) {
            buffer[WIDTH * y + x] = hex_color;
        }
    }
}