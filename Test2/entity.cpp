#include "entity.h"

entity::entity(float posx, float posy, SDL_Texture* entityTexture){
    this -> posx = posx;
    this -> posy = posy;
    this -> entityTexture = entityTexture;
}

void entity::render(SDL_Renderer*& renderer){
    SDL_RenderCopy(renderer,entityTexture, NULL, NULL);

}
