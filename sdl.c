//
// Created by mzxtx on 4/24/22.
//
#include <SDL2/SDL.h>
#include "sdl.h"
#include "game.h"

#define WIDTH 400
#define HEIGHT 300
//Setting up the Game interface
SDL_Window *win;
SDL_Surface *screen;
struct Game game;
struct Gameof game1;
void play(){
    for(game1.i=0;game1.i<game.lin;game1.i++){
        for(game1.j=0;game1.j<game.col;game1.j++)
        {
            //printf("%c",game.game[game1.i][game1.j]);
            if(game.game[game1.i][game1.j]=='1'){
                SDL_Rect re = {game1.j*WIDTH/game.col,game1.i*HEIGHT/game.lin,WIDTH/game.col,HEIGHT/game.lin};
                SDL_FillRect(screen,&re,0xff00000000);
            }
            if(game.game[game1.i][game1.j]=='0'){
                SDL_Rect re = {game1.j*WIDTH/game.col,game1.i*HEIGHT/game.lin,WIDTH/game.col,HEIGHT/game.lin};
                SDL_FillRect(screen,&re,0xffffffffff);
            }
        }
        //printf("\n");
    }
    SDL_UpdateWindowSurface(win);
    SDL_Delay(1000);
    //printf("%d",game.time);
    while (1){
        game_odd();
        if(exam()==0||game.time>game.step){
            break;
        }
        for(game1.i=0;game1.i<game.lin;game1.i++){
            for(game1.j=0;game1.j<game.col;game1.j++)
            {
                //printf("%c",game.game[game1.i][game1.j]);
                if(game.game1[game1.i][game1.j]=='1'){
                    SDL_Rect re = {game1.j*WIDTH/game.col,game1.i*HEIGHT/game.lin,WIDTH/game.col,HEIGHT/game.lin};
                    SDL_FillRect(screen,&re,0xff00000000);
                }
                if(game.game1[game1.i][game1.j]=='0'){
                    SDL_Rect re = {game1.j*WIDTH/game.col,game1.i*HEIGHT/game.lin,WIDTH/game.col,HEIGHT/game.lin};
                    SDL_FillRect(screen,&re,0xffffffffff);
                }
            }
            //printf("\n");
        }
        SDL_UpdateWindowSurface(win);
        SDL_Delay(1000);
        game_even();
        if(exam()==0||game.time>game.step){
            break;
        }
        for(game1.i=0;game1.i<game.lin;game1.i++){
            for(game1.j=0;game1.j<game.col;game1.j++)
            {
                //printf("%c",game.game[game1.i][game1.j]);
                if(game.game[game1.i][game1.j]=='1'){
                    SDL_Rect re = {game1.j*WIDTH/game.col,game1.i*HEIGHT/game.lin,WIDTH/game.col,HEIGHT/game.lin};
                    SDL_FillRect(screen,&re,0xff00000000);
                }
                if(game.game[game1.i][game1.j]=='0'){
                    SDL_Rect re = {game1.j*WIDTH/game.col,game1.i*HEIGHT/game.lin,WIDTH/game.col,HEIGHT/game.lin};
                    SDL_FillRect(screen,&re,0xffffffffff);
                }
            }
            //printf("\n");
        }
        SDL_UpdateWindowSurface(win);
        SDL_Delay(1000);
    }
}
void sdl(){
    if (SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Can not init video, %s", SDL_GetError());
    }
    win = SDL_CreateWindow(
            "Conway Game of Life",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            WIDTH,
            HEIGHT,
            SDL_WINDOW_SHOWN);
    if (win == NULL) {
        SDL_Log("Can not creat window, %s", SDL_GetError());
    }
    screen=SDL_GetWindowSurface(win);
    SDL_Rect r={0,0,WIDTH,HEIGHT};
    SDL_FillRect(screen,&r,0xffffffff);
    play();

    SDL_DestroyWindow(win);
}


