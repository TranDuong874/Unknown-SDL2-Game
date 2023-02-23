#include "game.h"
#include <SDL_image.h>
#include <SDL_mixer.h>

#include <iostream>
using namespace std;

#include "entity.h"
#include "map.h"
#include "player.h"

SDL_Renderer* game::renderer = nullptr;

const int level_w = 1280;
const int level_h = 768;

player *one;

void game::init(const char* title, int posx, int posy, int screen_width, int screen_height)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
        cout << "Oopsie! Initialization error" << SDL_GetError() << endl;
    else
    {
        window = SDL_CreateWindow(title, posx, posy, screen_width, screen_height, SDL_WINDOW_SHOWN);
        if(window == nullptr) cout << "Oopsie! Window initialization error" << SDL_GetError() << endl;

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        SDL_SetRenderDrawColor(renderer, 255,255,255,255);
        if(renderer == nullptr) cout << "Oopsie! Renderer initialization error" << SDL_GetError() << endl;
    }
    one = new player(100,100, "assets/running.png");

}

void game::userInput()
{
    int step = 10;
    while(SDL_PollEvent(&event) != 0)
    {
        if(event.type == SDL_QUIT)
        {
            running = false;
        }
        else{
            one->player_Input(event);
        }
    }
}

void game::update()
{
    one->player_Update();

}

void game::render()
{
    SDL_RenderClear(renderer);
    one->player_Render(renderer);
    SDL_RenderPresent(renderer);
}


void game::exitSDL()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
