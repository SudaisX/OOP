#include "truck.hpp"
#include <vector>
using namespace std;

class TruckDelivery{
    vector<Truck> trucks;
public:
    void loadTrucks();
    void calculateCost();
    void makeJourney();
    void unloadTrucks();
};
	
