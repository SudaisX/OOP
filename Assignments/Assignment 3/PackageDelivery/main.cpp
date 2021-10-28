#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include "box.hpp"
#include "truck.hpp"
#include "truckDelivery.hpp"

using namespace std;

int main() {
    TruckDelivery delivery;
    delivery.loadTrucks();
    delivery.calculateCost();
    delivery.makeJourney();
    delivery.unloadTrucks();
    return 0;
}
