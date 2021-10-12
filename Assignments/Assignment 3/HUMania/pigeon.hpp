#include<SDL.h>

class Pigeon{
SDL_Rect srcRect, moverRect;

public:
    // add the fly function here as well.
    void draw(SDL_Renderer*, SDL_Texture* assets);
    Pigeon(); // may add other overloaded constructors here... 
};
