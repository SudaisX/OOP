#include <iostream>
using namespace std;

class TollBooth {
    int totalCars;
    double toll;

   public:
    TollBooth() : totalCars(0), toll(0) {}
    void payingCar() {
        totalCars++;
        toll += 50;
    }

    void nopayCar() {
        totalCars++;
    }

    void display() const {
        cout << "Total cars passed: " << totalCars << endl;
        cout << "Total toll collected: Rs. " << toll << endl;
    }
};

// provide LyariTollBooth class implementation, and write main function.

class LyariTollBooth : public TollBooth {
    double fine = 0;

   public:
    void nopayCar() {
        TollBooth::nopayCar();
        fine += 50;
    }

    void display() const {
        TollBooth::display();
        cout << "Total fine collected: Rs. " << fine << endl;
    }
};

int main() {
    LyariTollBooth tollBooth;

    char input;
    cin >> input;

    while (input != 'q') {
        if (input == 'p') {
            tollBooth.payingCar();
        } else if (input == 'n') {
            tollBooth.nopayCar();
        }
        cin >> input;
    }

    tollBooth.display();
    return 0;
}