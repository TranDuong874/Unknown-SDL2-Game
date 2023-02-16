#include "animation.h"

animation(){};

animation::animation(SDL_Renderer* &renderer, string path){
    SDL_Surface *tmpSurface = IMG_Load(path.c_str());
    aTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);

    SDL_FreeSurface(tmpSurface);
}

animation::~animation(){
    SDL_DestroyTexture(aTexture);
}

void animation::box(int x, int y, int w, int h){
    dstRect.x = x;
    dstRect.y = y;
    dstRect.w = w;
    dstRect.h = h;
}

void animation::PlayFrame(int x, int y, int w, int h, int NUMBER_OF_FRAMES){
    srcRect.x = x+w*NUMBER_OF_FRAMES;
    srcRect.y = y;
    srcRect.w = w;
    srcRect.h = h;
}

void animation::render(SDL_Renderer* &renderer){
    SDL_RenderCopy(renderer, aTexture, &srcRect, &dstRect);
}

void animation::update(){}


