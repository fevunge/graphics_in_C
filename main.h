#ifndef MAIN_H
#define MAIN_H

#define WIDTH 320
#define HEIGHT 200

#include <SDL3/SDL.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

void put_pixel(uint32_t *, int , int , uint32_t);
void clear_buffer(uint32_t *, uint32_t);

#endif // !MAIN_H