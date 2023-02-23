#ifndef entity_h
#define entity_h
#include "game.h"

#include <string>
using namespace std;


class entity
{
public:
    entity(double pos_x, double pos_y, string path);
    ~entity();


    void entity_Load(SDL_Renderer*& renderer);
    void entity_Clear();
    void entity_Render(SDL_Renderer*& renderer, SDL_Rect* clip, SDL_Rect* dstRect);
    void entity_Update();

    double entity_GetX();
    double entity_GetY();
    void entity_SetX(double x);
    void entity_SetY(double y);

    void entity_SetRect(int w, int h);
    SDL_Rect* entity_GetRect();

    bool collision(SDL_Rect other);

protected:
    string path;
    SDL_Rect entity_Rect;
    double pos_x, pos_y;
    SDL_Texture* entity_Texture;


    SDL_Rect* clip = nullptr;

};


#endif // entity_h
