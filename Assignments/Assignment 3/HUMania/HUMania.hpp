#include<SDL.h>
#include "pigeon.hpp"
#include "egg.hpp"
#include "nest.hpp"
// #include <vector>
#include "vector.cpp" // apparently this files fixes some <vector> issues that I was facing

class HUMania {
    SDL_Renderer* gRenderer;
    SDL_Texture* assets;

     // Initialize demo pigeon, egg and nest
    Pigeon p1;
    Egg e1;
    Nest n1;

    MyVector<Egg> eggs; // initializing a vector for eggs to store eggs that might be produced for each click
    MyVector<Pigeon> pigeons;
    MyVector<Nest> nests;

public:
    HUMania(SDL_Renderer*, SDL_Texture*);
    void drawObjects();
    void createObject(int, int);

};