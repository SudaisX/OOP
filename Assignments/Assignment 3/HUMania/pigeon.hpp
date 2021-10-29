#include <SDL.h>
#include <string>   

class Pigeon {
    SDL_Rect srcRect, moverRect;
    char flightState = 0; // flightState = 0 => wingUp
                         // flightState = 1 => swoop
                         // flightState = 2 => windDown
    // bool reverse = false; // added feature where the pigeon would flip (visually) if when it hits the wall (instead of warping) - check [pigeon copy].cpp in [Archive]  

    public:
    Pigeon(); // default constructor 
    Pigeon(int, int); // constructor for when user clicks at (x,y)

    void draw(SDL_Renderer*, SDL_Texture* assets);
    void fly(int); // fly takes the pigeon to the top left and warps from right to left; 
                   // optional int param specifies rate of flying. 


};
