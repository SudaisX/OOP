#include<SDL.h>


class Nest {
    SDL_Rect srcRect, moverRect;
    int state = 0; // ranges from 0-2, determines what asset to show
    int wiggle(); // used to modify state so that the right wiggle animation can be set in draw()

    public:

    void draw(SDL_Renderer*, SDL_Texture* assets);
    Nest(); // default constructor
    Nest(int, int); // constructed by mouseclick
};