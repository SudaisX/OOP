#include "pigeon.hpp"

struct Rect {
    int x, y, w, h;
};

void assign_Rect(Rect X, SDL_Rect srcRect) {
    srcRect.x = X.x;
    srcRect.y = X.y;
    srcRect.w = X.w;
    srcRect.h = X.h;
}

bool compare_Rect(Rect X, SDL_Rect srcRect) {
    srcRect.x = X.x;
    srcRect.y = X.y;
    srcRect.w = X.w;
    srcRect.h = X.h;
}

void Pigeon::draw(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
    moverRect.x += 10; // moves the pigeon one pixel towards right, should it be in fly function??

    Rect wingUp, swoop, wingDown;
    wingUp = { 7, 15, 155, 102 }; // dimensions for rect in while wingUp asset is stored
    swoop = { 0, 164, 153, 83 };
    wingDown = { 2, 288, 159, 123 };

    if
}

Pigeon::Pigeon() {
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = { 7, 15, 155, 102 };
    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = { 30, 40, 76, 50 };
}

Pigeon::Pigeon(int x, int y) {
    moverRect = { x, y, 76, 50 };
}

void Pigeon::fly(int speedConstant = 2) {
    moverRect.x += 10 * speedConstant;
    moverRect.y -= 10 * speedConstant;
}