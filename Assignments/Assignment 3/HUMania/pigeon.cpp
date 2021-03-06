#include "pigeon.hpp"
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

void Pigeon::draw(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    SDL_RenderCopyEx(gRenderer, assets, &srcRect, &moverRect, NULL, NULL, SDL_FLIP_NONE);
    fly(20); // fly included in draw because if the pigeon has been drawn it must fly.

    Rect wingUp(7, 15, 155, 102), // set various asset names / sources
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
    srcRect = { 7, 15, 155, 102 }; // pigeon asset source initialized 
    moverRect = { x, y, 76, 50 }; // to be drawn on the x and y coords that user clicked
}

void Pigeon::fly(int speed = 10) { // default speed = 10
    int y_speed = speed;
    if (moverRect.y + speed <= 20) { // Ideally these constants would've been expressed in terms of Screen width and height
        y_speed = 0; // disable y_speed once at the top
    }
    if (moverRect.x + speed >= 990) { // once reached right end of the screen
        moverRect.x = -50;            // send to the left of the screen
    }
    moverRect.x += speed;
    moverRect.y -= y_speed;
}