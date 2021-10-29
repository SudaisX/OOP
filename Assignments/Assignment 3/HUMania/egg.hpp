#include <SDL.h>

class Egg {
    SDL_Rect srcRect, moverRect;

    public:

    bool isCracked = false; // to enable drawing of cracked egg

    Egg(); // default constructor 
    Egg(int, int); // constructor for when user clicks at (x,y)

    void draw(SDL_Renderer*, SDL_Texture* assets);
    void fall(int); // fall updates egg position repeatedly, unitl it breaks

};
