#ifndef animation_h
#define animation_h

#include "game.h"

#include <bits/stdc++.h>
using namespace std;

class animation
{
public:
    animation(){};
    ~animation(){}
    animation(SDL_Renderer*& renderer,int posx, int posy, int frames, int lines, string path);

    void load_spriteSheet(SDL_Renderer* renderer, string path);

    void spritesVector_create();

    void render(SDL_Renderer* &renderer);

    void update();

    void close();
    void set_x(int x);
    void set_y(int y);
    int get_x(){return dstRect.x;}
    int get_y(){return dstRect.y;}

    void scale_dstRect(double w, double h);


    //player state will later be added to entity
    bool up, down, left, right;
    void set_spriteLine(int x){
        spriteLine = x;
    }
protected:
    int count_frame = 0;
    SDL_Rect srcRect, dstRect;
    SDL_Texture* spriteSheet;
    int frames, lines;
    vector<vector<SDL_Rect>> clips;

    //Player/Entity class's feature;
    int spriteLine = 0;

};
#endif
