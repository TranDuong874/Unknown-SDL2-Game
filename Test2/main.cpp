#include "game.h"



int main(int argc, char* argv[]){
    game *g = new game();
    g->init("Testing screen", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280,720);

    const int FPS = 30;
    const int frameTime = 1000/FPS;

    Uint32 frameStart;
    int frameCnt;

    while(g->running){
        frameStart = SDL_GetTicks();

        g->userInput();

        g->render();

        g->update();

        frameCnt = SDL_GetTicks()- frameStart;

        if(frameTime > frameCnt){
            SDL_Delay(frameTime - frameCnt);
        }
    }
    return 0;
}
