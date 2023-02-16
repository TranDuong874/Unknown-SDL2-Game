#ifndef entity_h
#define entity_h
#include "game.h"

class entity
{
public:
    entity(){
        entityBox.x = 0;
        entityBox.y = 0;
        entityBox.w = 0;
        entityBox.h = 0;
    }

    ~entity(){}


    entity(float posx, float posy, SDL_Texture* entityTexture);

    void render(SDL_Renderer*& renderer);

protected:
    float posx, posy;
    SDL_Rect entityBox;
    SDL_Texture* entityTexture;
};
#endif // entity_h
