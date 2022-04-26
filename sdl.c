//
// Created by mzxtx on 4/24/22.
//
#include <SDL2/SDL.h>
#include "sdl.h"

#define WIDTH 400
#define HEIGHT 300
//Setting up the Game interface
void sdl(){
    if (SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Can not init vadeo, %s", SDL_GetError());
    }
    SDL_Window *win = SDL_CreateWindow(
            "Conway Game of Life",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            WIDTH,
            HEIGHT,
            SDL_WINDOW_SHOWN);
    if (win == NULL) {
        SDL_Log("Can not creat window, %s", SDL_GetError());
    }
    SDL_Surface *screen=SDL_GetWindowSurface(win);
    SDL_Rect r={0,0,WIDTH,HEIGHT};
    SDL_FillRect(screen,&r,0xffffffff);
    SDL_UpdateWindowSurface(win);
    SDL_Delay(3000);
    SDL_DestroyWindow(win);
}
