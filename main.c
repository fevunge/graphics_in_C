#include <SDL3/SDL.h>
#include <stdint.h>
#include <stdio.h>

#define WIDTH 640
#define HEIGHT 400

uint64_t framebuffer[WIDTH * HEIGHT];

int main(int argc, char const *argv[]) {
  SDL_Window *win;
  SDL_Renderer *renderer;
  SDL_Texture *texture;
  SDL_Event event;
  uint8_t is_running = 1;

  SDL_Init(SDL_INIT_VIDEO);

  win = SDL_CreateWindow("Framebuffer", WIDTH, HEIGHT, 0);
  renderer = SDL_CreateRenderer(win, NULL);
  SDL_CreateTexture(renderer, SDL_PIXELFORMAT_XRGB8888, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);

  while (is_running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        is_running = 0;
      }
      if (event.type == SDL_EVENT_KEY_UP) {
        is_running = !(event.key.key == SDLK_ESCAPE);
      }     
    }
    
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }
  
  printf("Hello, World with SDL!");
  return 0;
}
