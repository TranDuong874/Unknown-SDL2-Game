#include "entity.h"

entity::entity(double posx, double posy, string path){
    this->posx = posx;
    this->posy = posy;
    this->path = path;
    load_entityTexture(game::renderer);

    //Set source as the whole texture's area
    srcRect.x = 0;
    srcRect.y = 0;
    SDL_QueryTexture(entityTexture, NULL, NULL, &srcRect.w, &srcRect.h);

    //Default rectangle is set to equal to source rect
    dstRect.x = posx;
    dstRect.y = posy;
    dstRect.h = srcRect.h;
    dstRect.w = srcRect.w;
}
entity::~entity(){
    if(entityTexture != nullptr){
        SDL_DestroyTexture(entityTexture);
        entityTexture = nullptr;
    }
}
void entity::load_entityTexture(SDL_Renderer*& renderer){
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    SDL_SetColorKey(loadedSurface,SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0,255,255));
    if(loadedSurface == nullptr){
        cout << "Unable to load Entity surface " << path << " " << SDL_GetError() << endl;
    }
    else{
        entityTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if(entityTexture == nullptr){
            cout << "Unable to load Entity Texture " << path << " " <<SDL_GetError << endl;
        }
        SDL_FreeSurface(loadedSurface);
    }
}
void entity::render(SDL_Renderer*& renderer){
    SDL_RenderCopy(renderer,entityTexture, &srcRect, &dstRect);
}

void entity::clear_tmp(){
    SDL_DestroyTexture(entityTexture);
    entityTexture = nullptr;
}
