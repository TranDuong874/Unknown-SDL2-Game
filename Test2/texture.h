#ifndef texture_h
#define texture_h

#include <bits/stdc++.h>
#include "game.h"

using namespace std;

class texture
{
public:
    texture();
    texture(SDL_Renderer*& renderer, int posx, int posy, string path);

    ~texture();

    void texture_load(SDL_Renderer* &renderer, string path);

    void render(SDL_Renderer* renderer, bool null_rect);

    void close();

    void set_dstRect(int x, int y, int w, int h);
    void set_srcRect(int x, int y, int w, int h);

    int get_x();
    int get_y();

private:
    int posx, posy;
    SDL_Texture* textureSheet;
    SDL_Rect srcRect, dstRect;

};
#endif // texture_h
