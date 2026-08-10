#include "main.h"

void put_pixel(uint32_t* buffer, int x, int y, uint32_t hex_color) {
    buffer[WIDTH * y  + x] = hex_color;
}