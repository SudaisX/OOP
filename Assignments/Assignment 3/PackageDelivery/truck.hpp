#pragma once
#include <fstream>

#include "box.hpp"

class Truck {
    string driver;
    float petrol, money;            // money and petrol as float
    int fullMileage, emptyMileage;  // mileage as int
    float petrolPrice = 2.73;
    float reqPetrolCost = 0;
    float totalPetrolCost;
    float petrolRequired;
    Box box[10];

   public:
    Truck(string _name, float _petrol, float _money, float _emptyMileage, float _fullMileage) : driver(_name), petrol(_petrol), money(_money), fullMileage(_fullMileage), emptyMileage(_emptyMileage) {
        petrolRequired = (30.0 / fullMileage) + (30.0 / emptyMileage);  // the total petrol required for the journey, 30km to go with load, 30km to return without load (60km total journey)
    }

    void load() {  // load the boxes into the truck
        cout << "Loading Boxes for Truck.." << endl;
        for (int i = 0; i < 10; i++) {
            cout << "Box no. " << i + 1;
            box[i].load();
        }
    }
    void unload() {
        int totalVolume = 0;
        for (int i = 0; i < 10; i++) {  // calculate total volume for 10 boxes
            totalVolume += box[i].volume();
        }

        cout << totalVolume;  // output total volume carrier by a truck in a journey

        ofstream driverFile;
        driverFile.open("Trip.txt", ios_base::app);  // Create a new Trip text file to store truck data after journey

        // insert updated data into the Trip.txt file
        driverFile << driver << endl;
        driverFile << petrol << endl;
        driverFile << money << endl;
        driverFile << emptyMileage << endl;
        driverFile << fullMileage << endl;

        driverFile.close();  // Close text file
    }

    float cost() {  // Calculate petrol cost
        if (petrolRequired > petrol || petrol < 50) {
            totalPetrolCost = (50 - petrol) * petrolPrice;
            reqPetrolCost = petrolPrice * (petrolRequired - petrol);
            if (money >= totalPetrolCost && money >= reqPetrolCost) {  // check if money is greater or equal than the full tank price
                // money -= totalPetrolCost;
                petrol = 50;                      // set tank to full at 50 and
                return totalPetrolCost;           // return the full tank price
            } else {                              // else if not enough money for full tank then
                petrol += (money / petrolPrice);  // buy petrol with whatever money the driver has
                totalPetrolCost = money;          // update petrol cost
                // money = 0;
                if (petrol < petrolRequired) {
                    return -1;  // if the petrol is not enough then return -1
                }
                return totalPetrolCost;  // return the petrol cost
            }
        }
        return 0;
    }

    void update() {  // update money and petrol after making the journey
        money -= totalPetrolCost;
        petrol -= petrolRequired;
        cout << "Name: " << driver << ", Tank: " << petrol << "litres, Funds: $" << money << ", Empty Mileage: " << fullMileage << ", Loaded Mileage: " << emptyMileage << endl;
    }
};