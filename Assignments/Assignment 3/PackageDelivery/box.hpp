#pragma once
#include <iostream>
using namespace std;

class Box {
    int length;
    int width;
    int height;

   public:
    Box() {  // Generate random l, w, h between 5 and 30
        length = (rand() % 25) + 5;
        width = (rand() % 25) + 5;
        height = (rand() % 25) + 5;
    }

    int volume() {  // generate volume
        return length * width * height;
    }

    void load() {  // print and load the boxes with
        cout << " ( " << length << ", " << width << ", " << height << " ) "
             << "Volume: "
             << volume() << endl;
    }
};