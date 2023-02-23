#ifndef map_h
#define map_h

class Map
{
public:
    Map();
    ~Map();

    void Map_Load();
    void Map_Render();

private:
    SDL_Rect src,dst;


};
#endif // map_h
