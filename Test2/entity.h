#ifndef entity_h
#define entity_h
#include "game.h"

#include <string>
using namespace std;


class entity
{
public:
    entity(double posx, double posy, string path);
    ~entity();


    void load_entityTexture(SDL_Renderer*& renderer);

    void clear_tmp();

    //dstRect parameter will later on be used as clip for animation
    void render(SDL_Renderer*& renderer/*SDL_Rect clip*/);

    //Set and get functions
    double get_entityPosx(){return posx;}
    double get_entityPosy(){return posy;}

    void set_dstRect(int w, int h){
        dstRect.w = w;
        dstRect.h = h;
    }
    void set_srcRect(int w, int h){
        srcRect.w = w;
        srcRect.h = h;
    }

    void scale_dstRect(double multiple){
        dstRect.w = dstRect.w *multiple;
        dstRect.h = dstRect.h *multiple;
    }


protected:
    string path;
    double posx, posy;
    SDL_Texture *entityTexture = nullptr;
    SDL_Rect srcRect, dstRect;
};


#endif // entity_h
