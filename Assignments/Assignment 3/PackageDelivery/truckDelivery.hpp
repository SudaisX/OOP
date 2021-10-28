#include <vector>

#include "truck.hpp"
using namespace std;

class TruckDelivery {
    vector<Truck> trucks;

   public:
    void loadTrucks();
    void calculateCost();
    void makeJourney();
    void unloadTrucks();
};
