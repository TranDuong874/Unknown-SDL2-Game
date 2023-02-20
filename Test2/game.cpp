#include "game.h"

SDL_Renderer* game::renderer = nullptr;

//Declare entity here
//texture *background;
animation *player;
animation *one;
texture *background;

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

    //Define entity here
    //background = new texture(renderer,100,100, "assets/character/foo2.png");
    player = new animation(renderer,100,100,4,1,"assets/character/foo2.png");
    one = new animation(renderer, 300,500,22,8, "assets/character/running.png");

    //background = new texture(renderer,0,0,"assets/bgr.png");
    one->scale_dstRect(3,3);

}

void game::userInput(){
    while(SDL_PollEvent(&event) != 0){
        if(event.type == SDL_QUIT){
            running = false;
        }
        else if(event.type == SDL_KEYDOWN){

            switch(event.key.keysym.sym){
            case SDLK_w:
                one->up = true;
                one->set_spriteLine(1);
                break;
            case SDLK_a:
                one->left = true;
                one->set_spriteLine(7);
                break;
            case SDLK_s:
                one->down = true;
                one->set_spriteLine(5);
                break;
            case SDLK_d:
                one->right = true;
                one->set_spriteLine(3);
                break;
            }
        }
        if(event.type == SDL_KEYUP){
            switch(event.key.keysym.sym){
            case SDLK_w:
                one->up = false;

                break;
            case SDLK_a:
                one->left = false;

                break;
            case SDLK_s:
                one->down = false;

                break;
            case SDLK_d:
                one->right = false;


                break;
            }
        }
    }
}

void game::update(){
    player->update();
    one->update();
}

void game::render(){
    SDL_RenderClear(renderer);
    //Render entity here
    //background->render(renderer,1);
    one->render(renderer);
    SDL_RenderPresent(renderer);
}


void game::exitSDL(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
