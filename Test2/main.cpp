#include "game.h"

int main(int argc, char* argv[]){
    game *g = new game();
    g->init("Testing screen", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800,600);


    while(g->running){
        g->userInput();

        g->render();

        g->update();
    }
    return 0;
}
