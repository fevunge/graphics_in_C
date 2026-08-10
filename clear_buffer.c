#include "main.h"

void clear_buffer(uint32_t *buffer, uint32_t hex_color) {
    for (size_t i = 0; i < (WIDTH * HEIGHT); i++) {
        buffer[i] = hex_color;
    }
}