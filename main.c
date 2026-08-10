#include "main.h"

uint32_t framebuffer[WIDTH * HEIGHT];

int main(int argc, char const *argv[]) {
  SDL_Window *win;
  SDL_Renderer *renderer;
  SDL_Texture *texture;
  SDL_Event event;
  uint8_t is_running = 1;
  uint64_t start_time, end_time = 0;

  const double fps = (1.0 / 60.0);

  if (!SDL_Init(SDL_INIT_VIDEO)){
    fprintf(stderr, "Error!: %s|\n", SDL_GetError());
    return (EXIT_FAILURE);
  }

  win = SDL_CreateWindow("Framebuffer", WIDTH * 3, HEIGHT * 3, 0);
  if (!win) {
    SDL_Quit();
    fprintf(stderr, "Error!: %s|\n", SDL_GetError());
    return (EXIT_FAILURE);
  };
   
  renderer = SDL_CreateRenderer(win, NULL);
  if (!renderer)
  {
    SDL_DestroyWindow(win);
    SDL_Quit();
    fprintf(stderr, "Error!: %s|\n", SDL_GetError());
    return (EXIT_FAILURE);
  }
  
  texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_XRGB8888, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
  if (!texture)
  {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();
    fprintf(stderr, "Error!: %s|\n", SDL_GetError());
    return (EXIT_FAILURE);
  }
  
  SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);

  int frame = 0;

  while (is_running) {

    start_time = SDL_GetPerformanceCounter();

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        is_running = 0;
      }
      if (event.type == SDL_EVENT_KEY_UP) {
        is_running = !(event.key.key == SDLK_ESCAPE);
      }     
    }

    clear_buffer(framebuffer, 0x131020);
    put_pixel(framebuffer, frame % WIDTH, (HEIGHT / 2), 0xffffff);
  
    SDL_UpdateTexture(
      texture,
      NULL,
      framebuffer, 
      sizeof(uint32_t) * WIDTH
    );

    frame++;
    
    SDL_RenderClear(renderer);
    SDL_RenderTexture(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    end_time = SDL_GetPerformanceCounter();

    double elapsed = (double)(end_time - start_time) / (double) SDL_GetPerformanceFrequency();
    if (elapsed < fps)
    {
      SDL_Delay((fps - elapsed) * (1000.0));
    }
  }
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(win);
  SDL_Quit();
  return 0;
}

