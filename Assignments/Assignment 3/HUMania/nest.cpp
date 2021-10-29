#include "nest.hpp"
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

void Nest::draw(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);

    Rect state0(484, 0, 156, 145),
        state1(489, 171, 141, 99),
        state2(494, 308, 144, 107);
    state = wiggle(); // wiggle included in draw because if the nest has been drawn it must wiggle.
    if (state == 0) {
        state0.assign_Rect(srcRect);
    }
    else if (state == 1) {
        state1.assign_Rect(srcRect);
    }
    else if (state == 2) {
        state2.assign_Rect(srcRect);
    }

}

Nest::Nest() {
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = { 484, 0, 156, 145 };
    moverRect = { 30, 40, 93, 87 };
}

Nest::Nest(int x, int y) {
    srcRect = { 484, 0, 156, 145 };
    moverRect = { x, y, 93, 87 };
}

int Nest::wiggle() {
    return rand() % 3;
}