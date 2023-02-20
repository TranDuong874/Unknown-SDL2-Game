#include "animation.h"

animation::animation(SDL_Renderer*& renderer,int posx, int posy, int frames, int lines, string path){
        load_spriteSheet(renderer, path);

        this -> frames = frames;
        SDL_QueryTexture(spriteSheet, NULL, NULL, &srcRect.w, &srcRect.h);

        srcRect.x = 0;
        srcRect.y = 0;
        srcRect.w /= frames;
        srcRect.h /= lines;

        dstRect.x = posx;
        dstRect.y = posy;
        dstRect.w = srcRect.w;
        dstRect.h = srcRect.h;
        spritesVector_create();

    }

void animation::load_spriteSheet(SDL_Renderer* renderer, string path)
    {
        SDL_Surface *loadedSurface = IMG_Load(path.c_str());
        SDL_SetColorKey(loadedSurface, SDL_TRUE,SDL_MapRGB(loadedSurface -> format, 0,255,255));
        if(loadedSurface == nullptr)
        {
            cout << "Unable to load surface " << path << " " << SDL_GetError() << endl;
        }
        else{
            spriteSheet = SDL_CreateTextureFromSurface(renderer, loadedSurface);
            if(spriteSheet == nullptr)
            {
                cout << "Unable to load spriteSheet " << path << " " << SDL_GetError() << endl;
            }
            SDL_FreeSurface(loadedSurface);
        }
    }

void animation::spritesVector_create()
    {
        vector<SDL_Rect> tmp_v;
        SDL_Rect tmp = srcRect;

        for(int i = 0; i < lines; i++){
            for(int j = 0; j < frames; j++){
                tmp.x = j*tmp.w;
                tmp_v.push_back(tmp);
            }
            clips.push_back(tmp_v);
            tmp_v.clear();
            tmp.y = i*tmp.h;
        }
    }

void animation::render(SDL_Renderer* &renderer)
    {
        SDL_RenderCopy(renderer, spriteSheet, &clips[spriteLine][count_frame],&dstRect);
    }

void animation::update()
    {
        //remove later
        if(up == true){
            dstRect.y -= 10;
        }
        else if(down == true){
            dstRect.y += 10;
        }
        else if(left == true){
            dstRect.x -= 10;
        }
        else if(right == true){
            dstRect.x += 10;
        }
        //////////////
        count_frame++;
        if(count_frame > frames-1)
        {
            count_frame = 0;
        }
    }

void animation::close()
    {
        SDL_DestroyTexture(spriteSheet);
    }

void animation::set_x(int x)
{
    dstRect.x = x;
}
void animation::set_y(int y)
{
    dstRect.y = y;
}

void animation::scale_dstRect(double w, double h)
{
    dstRect.w *= w;
    dstRect.h *= h;
}

