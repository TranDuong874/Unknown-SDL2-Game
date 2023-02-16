#ifndef animation_h
#define animation_h

#include "game.h"
#include <string>
using namespace std;

class animation
{
public:
    animation(){};

    animation(SDL_Renderer* &renderer, string path);

    ~animation();

    void box(int x, int y, int w, int h);

    void PlayFrame(int x, int y, int w, int h, int NUMBER_OF_FRAMES);

    void update();

    void render(SDL_Renderer* &renderer);
private:
    SDL_Rect srcRect;
    SDL_Rect dstRect;
    SDL_Texture *aTexture;
};
#endif
