#include<iostream>
#include "HUMania.hpp"

void HUMania::drawObjects() {

    // call draw functions of all the objects here
    n1.draw(gRenderer, assets);
    p1.draw(gRenderer, assets);
    e1.draw(gRenderer, assets); // draws an egg

    for (int i = 0; i < eggs.size(); i++) { // draws each egg in the eggs vector 
        eggs[i].draw(gRenderer, assets);
    }
    for (int i = 0; i < nests.size(); i++) { // note how these loops are dynamic owing to the .size() method; arrays wouldn't have had this.
        nests[i].draw(gRenderer, assets);
    }
    for (int i = 0; i < pigeons.size(); i++) {
        pigeons[i].draw(gRenderer, assets);
    }

}

void HUMania::createObject(int x, int y) {
    int seed = rand() % 3; // randomizer to choose which object to create and draw when user clicks
    if (seed == 0) {
        nests.push_back(Nest(x, y)); // push a nest to nests, 
                                     // and draw the nest where the user clicked 
    }
    else if (seed == 1) {
        pigeons.push_back(Pigeon(x, y));
    }
    else if (seed == 2) {
        eggs.push_back(Egg(x, y));
    }
}

HUMania::HUMania(SDL_Renderer* renderer, SDL_Texture* asst) :gRenderer(renderer), assets(asst) { }
