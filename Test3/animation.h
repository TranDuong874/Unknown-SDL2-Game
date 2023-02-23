#ifndef animation_h
#define animation_h
#include <SDL_image.h>
#include <SDL.h>
#include <vector>
#include <iostream>
using namespace std;
class animation
{
public:
    //entity rect = entity rect;
    //How does this work?
    //pass in texture and entity_Rect
    //The constructor will reshape entity rect, and create a clip(srcREct)
    //When render, it will render on entity_Rect's pos

    animation(SDL_Texture *texture, int frame, int line, SDL_Rect& dstRect)
    {
        this->frame = frame;
        this->line = line;

        clip.x = 0;
        clip.y = 0;

        spriteSheet = texture;
        SDL_QueryTexture(spriteSheet, NULL, NULL, &clip.w, &clip.h);
        clip.w /= frame;
        clip.h /= line;

        animation_createClipVector();
        dstRect.w = clip.w*3;
        dstRect.h = clip.h*3;
    }
    ~animation(){};

    void animation_Render(SDL_Renderer*& renderer, SDL_Rect& dstRect)
    {
        SDL_RenderCopy(renderer, spriteSheet, &clips[frame_count][line-1], &dstRect);
        animation_Play();
    }

    void animation_Play()
    {
        frame_count++;
        if(frame_count > frame-1){
            frame_count = 0;

        }
        cout << frame_count << endl;
    }


    void animation_createClipVector()
    {
        vector<SDL_Rect> tmp_v;
        SDL_Rect tmp = clip;


        for(int i = 0; i < frame; i++){
            for(int j = 0; j < line; j++){
                tmp.y = j*tmp.h;
                tmp_v.push_back(tmp);
            }
            clips.push_back(tmp_v);
            tmp_v.clear();
            tmp.x = i*tmp.w;
        }
    }

    void animation_SetSpriteLine(int x)
    {
        line = x;
    }
private:
    SDL_Texture* spriteSheet;
    SDL_Rect clip;
    SDL_Rect animation_dstRect;
    int frame, line;
    int frame_count = 0;
    vector<vector<SDL_Rect>> clips;

};
#endif // animation_h
