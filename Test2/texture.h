#ifndef texture_h
#define texture_h

#include <bits/stdc++.h>
#include "game.h"
using namespace std;

class texture
{
public:
    SDL_Texture* loadTexture(string path,SDL_Renderer*& renderer);
private:

};
#endif // texture_h
