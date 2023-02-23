#ifndef texture_h
#define texture_h

#include "game.h"
#include <string>
using namespace std;

class texture
{
public:
    texture(){};
    texture(SDL_Renderer*& renderer, string path);
    ~texture();


    void texture_Load(SDL_Renderer renderer, string path);
    void texture_Render(SDL_Renderer*& renderer);

    SDL_Texture* texture_Get();

private:
    SDL_Texture* p_texture;

};
#endif
