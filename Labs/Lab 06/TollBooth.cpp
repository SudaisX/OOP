#include <iostream>
using namespace std;

class TollBooth {
   private:
    unsigned int cars, cash;

   public:
    TollBooth() {
        cars = 0;
        cash = 0;
    }

    void payingCar() {
        cars += 1;
        cash += 50;
    }
    void nopayCar() {
        cars += 1;
    }
    void display() {
        cout << "Total cars passed: " << cars << endl;
        cout << "Total toll collected: Rs. " << cash << endl;
    }
};

int main() {
    TollBooth tollBooth;
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