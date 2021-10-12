#pragma once
#include "box.hpp"
class Truck
{
    string driver;
    int petrol;
    int money;
    int fullMileage;
    int emptyMileage;
    Box box[10];

    void load(int numBox);
    void unload();
    float cost();
};

