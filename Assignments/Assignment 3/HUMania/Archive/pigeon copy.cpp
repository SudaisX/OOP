#include "pigeon.hpp"
#include "game.hpp"

class Rect {
    int x, y, w, h;

    public:
    Rect(int x_, int y_, int w_, int h_) : x(x_), y(y_), w(w_), h(h_) { }

    void assign_Rect(SDL_Rect& srcRect) { // can use '=' overloading
        srcRect.x = x;
        srcRect.y = y;
        srcRect.w = w;
        srcRect.h = h;
    }
};

void Pigeon::draw(SDL_Renderer* gRenderer, SDL_Texture* assets) {

    if (reverse) {
        SDL_RenderCopyEx(gRenderer, assets, &srcRect, &moverRect, NULL, NULL, SDL_FLIP_HORIZONTAL);
    }
    else {
        SDL_RenderCopyEx(gRenderer, assets, &srcRect, &moverRect, NULL, NULL, SDL_FLIP_NONE);
    }

    fly(20); // fly included in draw because if the pigeon has been drawn it must fly.

    Rect wingUp(7, 15, 155, 102),
        swoop(0, 164, 153, 83),
        wingDown(2, 288, 159, 123);

    if (Pigeon::flightState == 0) {
        swoop.assign_Rect(srcRect); // ideally srcRect = swoop; 
                                    // if I had time to overload
        Pigeon::flightState = 1;
    }
    else if (Pigeon::flightState == 1) {
        wingDown.assign_Rect(srcRect);
        Pigeon::flightState = 2;
    }
    else if (Pigeon::flightState == 2) {
        wingUp.assign_Rect(srcRect);
        Pigeon::flightState = 0;
    }


}

Pigeon::Pigeon() {
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = { 7, 15, 155, 102 };
    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = { 30, 40, 76, 50 };
}

Pigeon::Pigeon(int x, int y) {
    srcRect = { 7, 15, 155, 102 };
    moverRect = { x, y, 76, 50 };
}

void Pigeon::fly(int speed = 10) {
    int y_speed = speed;
    if (moverRect.y + speed <= 20) {
        y_speed = 0;
    }
    if (!reverse) {
        if (moverRect.x + speed >= 900) {
            reverse = true;
        }
        moverRect.x += speed;
        moverRect.y -= y_speed;
    }
    else { // in reverse
        if (moverRect.x - speed <= 10) {
            reverse = false;
        }
        moverRect.x -= speed;
        // moverRect.y = speed;
    }
}