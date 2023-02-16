#ifndef game_h
#define game_h

#include <bits/stdc++.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "entity.h"
#include "texture.h"

using namespace std;

class game
{

public:

    void init(const char* title, int posx, int posy, int screen_width, int screen_height);

    void userInput();

    void update();

    void render();

    void exitSDL();

    bool running = true;

private:
    SDL_Renderer *renderer;
    SDL_Window *window = nullptr;
    SDL_Event event;
};


#endif
