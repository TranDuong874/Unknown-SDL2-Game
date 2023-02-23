#ifndef player_h
#define player_h
#include "entity.h"
#include <SDL.h>
#include <cmath>
#include "animation.h"

class player : public entity
{
public:
    player(double pos_x, double pos_y, string path):entity(pos_x,pos_y,path){
        player_Animation = new animation(entity_Texture,22,8,entity_Rect);
    };

    ~player();
    void player_Input(SDL_Event event)
    {
        if(event.type == SDL_KEYDOWN)
        {
            switch(event.key.keysym.sym)
            {
                case SDLK_w:

                    UP = true;
                    break;

                case SDLK_s:
                    DOWN = true;
                    break;

                case SDLK_a:
                    LEFT = true;
                    break;

                case SDLK_d:
                    RIGHT = true;
                    break;
            }
        }
        if(event.type == SDL_KEYUP)
        {
            switch(event.key.keysym.sym)
            {
                case SDLK_w:
                    UP = false;
                    break;

                case SDLK_s:
                    DOWN = false;
                    break;

                case SDLK_a:
                    LEFT = false;
                    break;

                case SDLK_d:
                    RIGHT = false;
                    break;
            }
        }
    }

    void player_Update()
    {

        if(UP)
        {
            move_up();
            player_Animation->animation_SetSpriteLine(1);
            if(RIGHT){
                player_Animation->animation_SetSpriteLine(2);
                move_right();
            }
            else if(LEFT)
            {
                player_Animation->animation_SetSpriteLine(8);
                move_left();
            }
        }
        else if(DOWN)
        {
            player_Animation->animation_SetSpriteLine(5);
            move_down();
            if(RIGHT){
                move_right();
                player_Animation->animation_SetSpriteLine(4);
            }
            else if(LEFT)
            {
                move_left();
                player_Animation->animation_SetSpriteLine(6);
            }
        }
        else if(LEFT)
        {
            player_Animation->animation_SetSpriteLine(7);
            move_left();
            if(UP)
            {
                player_Animation->animation_SetSpriteLine(8);
                move_up();
            }
            if(DOWN)
            {
                player_Animation->animation_SetSpriteLine(6);
               move_down();
            }
        }
        else if(RIGHT)
        {
            player_Animation->animation_SetSpriteLine(3);
            move_right();
            if(UP)
            {
                player_Animation->animation_SetSpriteLine(1);
                move_up();
            }
            if(DOWN)
            {
                player_Animation->animation_SetSpriteLine(4);
                move_down();
            }
        }
    }

    void player_Render(SDL_Renderer* &renderer)
    {
        player_Animation->animation_Render(renderer, entity_Rect);
    }

    void move_up(){entity_Rect.y-= step;}
    void move_down(){entity_Rect.y+= step;}
    void move_left(){entity_Rect.x -= step;}
    void move_right(){entity_Rect.x += step;}
private:
    bool UP, DOWN, LEFT, RIGHT;
    double step = 10;
    animation* player_Animation;


};
#endif
