#include "texture.h"
#include <iostream>
#include <SDL_image.h>
#include <string>
using namespace std;

texture::texture(SDL_Renderer*& renderer, string path)
{
    texture_Load(renderer, path);
}

void texture::texture_Load(SDL_Renderer*& renderer, string path)
{
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == nullptr)
    {
        cout << "Unable to load entity surface " << path << endl;
    }
    else{
        p_texture = SDL_CreateTextureFromSurface(renderer,loadedSurface);
        if(p_texture == nullptr)
        {
            cout << "Unable to load texture " << path << endl;
        }
        SDL_FreeSurface(loadedSurface);
    }
}

void texture::texture_Render(SDL_Renderer renderer)
{
    SDL_RenderCopy(renderer, p_texture, NULL, NULL);
}
SDL_Texture* texture::texture_Get()
{
    return p_texture;
}

texture::~texture()
{
    SDL_DestroyTexture(p_texture);
}
