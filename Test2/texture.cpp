#include "texture.h"

SDL_Texture *texture::loadTexture(string path, SDL_Renderer*& renderer)
{
    SDL_Texture *loadedTexture = nullptr;
    SDL_Surface *loadedSurface = nullptr;
    loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == nullptr) cout << "Oopsie! Unable to load Texture: " << path << SDL_GetError() << endl;

    loadedTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);

    return loadedTexture;
}



