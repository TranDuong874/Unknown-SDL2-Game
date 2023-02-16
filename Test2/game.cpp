#include "game.h"

void game::init(const char* title, int posx, int posy, int screen_width, int screen_height){
    SDL_Init(SDL_INIT_EVERYTHING);
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
        cout << "Oopsie! Initialization error" << SDL_GetError() << endl;
    else{
        window = SDL_CreateWindow(title, posx, posy, screen_width, screen_height, SDL_WINDOW_SHOWN);
        if(window == nullptr) cout << "Oopsie! Window initialization error" << SDL_GetError() << endl;

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        SDL_SetRenderDrawColor(renderer, 255,255,255,255);
        if(renderer == nullptr) cout << "Oopsie! Renderer initialization error" << SDL_GetError() << endl;
    }
}

void game::userInput(){
    while(SDL_PollEvent(&event) != 0){
        if(event.type == SDL_QUIT){
            running = false;
        }
        else if(event.type == SDL_KEYDOWN){
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                running = false;
                break;
            }
        }
    }
}

void game::update(){

}

void game::render(){
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void game::exitSDL(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
