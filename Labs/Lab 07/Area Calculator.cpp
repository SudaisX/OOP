#include <iostream>

using namespace std;

struct Distance {
    int feet, inches;
};

class Area {
   private:
    Distance length, width;

   public:
    Area(Distance l, Distance w) : length(l), width(w){};

    operator double() {
        return (double(length.feet) + double(length.inches) / 12) * (double(width.feet) + double(width.inches) / 12);
    }
};

int main() {
    double ft1, ft2, in1, in2;
    cin >> ft1 >> in1 >> ft2 >> in2;
    Area area1 = {{ft1, in1}, {ft2, in2}};

    double decimalArea = area1;  // overload the double operator to convert area object into decimal value.
    cout << "Area is: " << decimalArea << "sq feet" << endl;
}