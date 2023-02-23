#include "entity.h"
#include <SDL_image.h>
#include <iostream>



using namespace std;

entity::entity(double pos_x, double pos_y, string path)
{
    this->pos_x = pos_x;
    this->pos_y = pos_y;
    this->path = path;
    entity_Load(game::renderer);

    SDL_QueryTexture(entity_Texture,NULL, NULL, &entity_Rect.w, &entity_Rect.h);
    entity_Rect.x = pos_x;
    entity_Rect.y = pos_y;
}

void entity::entity_Load(SDL_Renderer*& renderer)
{
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    SDL_SetColorKey(loadedSurface,SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0,255,255));
    if(loadedSurface == nullptr)
    {
        cout << "Unable to load Entity surface " << path << " " << SDL_GetError() << endl;
    }
    else
    {
        entity_Texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if(entity_Texture == nullptr)
        {
            cout << "Unable to load Entity Texture " << path << " " <<SDL_GetError << endl;
        }
        SDL_FreeSurface(loadedSurface);
    }
}
entity::~entity()
{
    if(entity_Texture != nullptr)
    {
        SDL_DestroyTexture(entity_Texture);
        entity_Texture = nullptr;
    }
}

void entity::entity_Render(SDL_Renderer*& renderer, SDL_Rect* clip, SDL_Rect* dstRect)
{
    SDL_RenderCopy(renderer,entity_Texture, clip, dstRect);
}

void entity::entity_Clear()
{
    SDL_DestroyTexture(entity_Texture);
    entity_Texture = nullptr;
}

SDL_Rect* entity::entity_GetRect()
{
    return &entity_Rect;
}

void entity::entity_SetX(double x)
{
    pos_x = x;
    entity_Rect.x = x;
}
void entity::entity_SetY(double y)
{
    pos_y = y;
    entity_Rect.y = y;
}
double entity::entity_GetX()
{
    return pos_x;
}

double entity::entity_GetY()
{
    return pos_y;
}

bool entity::collision(SDL_Rect other)
    {
        double left_a, left_b;
        double right_a, right_b;
        double top_a, top_b;
        double bot_a, bot_b;

        left_a = entity_Rect.x;
        right_a = entity_Rect.x + entity_Rect.w;
        top_a = entity_Rect.y;
        bot_a = entity_Rect.y + entity_Rect.h;

        left_b = other.x;
        right_b = other.x + other.w;
        top_b = other.y;
        bot_b = other.y + other.h;

        if(bot_a <= top_b)
            return false;
        if(top_a >= bot_b)
            return false;
        if(right_a <= left_b)
            return false;
        if(left_a >= right_b)
            return false;

        return true;
    }
