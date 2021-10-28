#include <fstream>
#include <vector>

#include "truck.hpp"
using namespace std;

class TruckDelivery {
    vector<Truck> trucks;

   public:
    void loadTrucks() {  // Reads the Drivers file and populates the vector trucks with the information from the file
        int count = 0;
        string truck[5];                    // an array of size 5 to store contents of each line in the entry
        ifstream TruckFile("Drivers.txt");  // Load Drivers File
        string line;                        // Initialize a line variable
        cout << "Before Journey: " << endl;
        while (getline(TruckFile, line)) {  // While not EOF
            truck[count] = line;            // save the contents of the line in the truck variable
            count++;
            if (count == 5) {  // Check if all 5 lines have been saved into the array
                count = 0;     // Make the counter 0 so we can save another entry

                Truck tempTruck(truck[0], stoi(truck[1]), stoi(truck[2]), stoi(truck[3]), stoi(truck[4]));  // make a temporary truck with the contents of the truck array
                tempTruck.load();                                                                           // load boxes into the truck

                trucks.push_back(tempTruck);  // push truck into the vector of trucks

                cout << "Name: " << truck[0] << ", Tank: " << truck[1] << "litres, Funds: $" << truck[2] << ", Empty Mileage: " << truck[3] << ", Loaded Mileage: " << truck[4] << endl;
            }
        }
    }

    void unloadTrucks() {  //shows all the trucks information, once the journey is complete
        for (int i = 0; i < trucks.size(); i++) {
            cout << "Total Volume of all the boxes carried by Truck " << i << ": ";
            trucks[i].unload();
            cout << " unit^3" << endl;
        }
    }

    void calculateCost() {  // calculates the total cost it will take the loaded truck to travel 60 km drop the cargo and return empty based on the fuel consumption when the tank was full

        cout << "Cost spent by each driver for the fuel" << endl;
        for (int i = 0; i < trucks.size(); i++) {  // For every truck
            float journeyCost = trucks.at(i).cost();
            if (journeyCost != -1) {                                                          // Check if any truck does not have insufficient petrol for the journey
                cout << "Travel cost for Truck " << i + 1 << " is: " << journeyCost << endl;  // Call cost method of truck to calculate the petrol cost
            } else {                                                                          // if yes then
                cout << "Truck " << i << " can not do the journey." << endl;
                trucks.erase(trucks.begin() + i);  // delete the truck from the vector of trucks
            }
        }
    }

    void makeJourney() {  // updates all the trucks (which made journey) after making all the journey
        for (int i = 0; i < trucks.size(); i++)
            trucks[i].update();  // update petrol and money
    }
};