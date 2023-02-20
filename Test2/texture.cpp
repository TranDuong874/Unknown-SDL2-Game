#include "texture.h"



texture::texture(SDL_Renderer*& renderer, int posx, int posy, string path)
    {
        texture_load(renderer, path);

        srcRect.x = 0;
        srcRect.y = 0;
        SDL_QueryTexture(textureSheet, NULL, NULL, &srcRect.w, &srcRect.h);

        dstRect.x = 0;
        dstRect.y = 0;
        dstRect.w = srcRect.w;
        dstRect.h = srcRect.h;

    }

texture::~texture()
    {
        close();
    }

void texture::texture_load(SDL_Renderer* &renderer, string path)
    {
        SDL_Surface *loadedSurface = IMG_Load(path.c_str());
        SDL_SetColorKey(loadedSurface, SDL_TRUE,SDL_MapRGB(loadedSurface -> format, 0,255,255));
        if(loadedSurface == nullptr)
        {
            cout << "Unable to load surface " << path << " " << SDL_GetError() << endl;
        }
        else{
            textureSheet = SDL_CreateTextureFromSurface(renderer, loadedSurface);
            if(textureSheet == nullptr)
            {
                cout << "Unable to load textureSheet " << path << " " << SDL_GetError() << endl;
            }
            SDL_FreeSurface(loadedSurface);
        }
    }

void texture::render(SDL_Renderer* renderer, bool null_rect)
    {
        if(null_rect)
            SDL_RenderCopy(renderer,textureSheet, NULL,NULL);
        else
            SDL_RenderCopy(renderer,textureSheet, &srcRect,&dstRect);
    }

void texture::close()
    {
        SDL_DestroyTexture(textureSheet);
    }

void texture::set_dstRect(int x, int y, int w, int h)
    {
        dstRect.x = x;
        dstRect.y = y;
        dstRect.w = w;
        dstRect.h = h;
    }
void texture::set_srcRect(int x, int y, int w, int h)
    {
        srcRect.x = x;
        srcRect.y = y;
        srcRect.w = w;
        srcRect.h = h;
    }

int texture::get_x(){return posx;}
int texture::get_y(){return posy;}



