#include "game.h"

const int width = 800;
const int height = 600;
int main(int argc, char* argv[])
{
    game *g = new game();
    g->init("Testing screen", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width,height);

    const int FPS = 30;
    const int frameTime = 1000/FPS;

    Uint32 frameStart;
    int frameCnt;

    while(g->running)
    {
        frameStart = SDL_GetTicks();

        g->userInput();

        g->render();

        g->update();

        frameCnt = SDL_GetTicks()- frameStart;

        if(frameTime > frameCnt)
        {
            SDL_Delay(frameTime - frameCnt);
        }
    }
    return 0;
}

