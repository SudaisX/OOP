#include "egg.hpp"
#include "game.hpp"

class Rect { // Rect class to reduce code clutter
    int x, y, w, h;

    public:
    Rect(int x_, int y_, int w_, int h_) : x(x_), y(y_), w(w_), h(h_) { } // constructor

    // function assign values of the Rect to the passed SDL_Rect address
    void assign_Rect(SDL_Rect& srcRect) { // IMPROVEMENT can use '=' overloading
        srcRect.x = x;
        srcRect.y = y;
        srcRect.w = w;
        srcRect.h = h;
    }
};

void Egg::draw(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
    fall(20); // fall at a speed of 20 pixels per frame
              // fall included in draw because if the egg has been drawn it must fall.
    Rect uncracked(228, 24, 132, 174),
        cracked(207, 244, 231, 186);

    if (isCracked) {
        cracked.assign_Rect(srcRect);
    }
}

Egg::Egg() {
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = { 228, 24, 132, 174 };
    moverRect = { 30, 40, 22, 29 };
}

Egg::Egg(int x, int y) {
    srcRect = { 228, 24, 132, 174 };
    moverRect = { x, y, 22, 29 };
}

void Egg::fall(int fallingRate = 50) {
    if (!isCracked) {
        if (moverRect.y + fallingRate < 580) {
            moverRect.y += fallingRate;
        }
        // else if (moverRect.y + 50 > Game::SCREEN_HEIGHT) { // IMPROVEMENT:  implement with SCREN_HEIGHT CONSTANTS rather than absolute values
        else if (moverRect.y + fallingRate >= 580) {
            isCracked = true;
        }
    }
}