#include <iostream>
using namespace std;

class Complex {
   private:
    double real, imag;

   public:
    Complex() {
        real = 0;
        imag = 0;
    }

    Complex(double realn, double imagn) {
        real = realn;
        imag = imagn;
    }

    Complex add(Complex num) {
        Complex newNum;
        newNum.real = real + num.real;
        newNum.imag = imag + num.imag;
        return newNum;
    }

    Complex add(double num) {
        Complex newNum;
        newNum.real = real + num;
        newNum.imag = imag;
        return newNum;
    }

    Complex subtract(Complex num) {
        Complex newNum;
        newNum.real = real - num.real;
        newNum.imag = imag - num.imag;
        return newNum;
    }

    Complex subtract(double num) {
        Complex newNum;
        newNum.real = real - num;
        newNum.imag = imag;
        return newNum;
    }

    Complex multiply(Complex num) {
        Complex newNum;
        newNum.real = real * num.real - imag * num.imag;
        newNum.imag = imag * num.real + real * num.imag;
        return newNum;
    }

    Complex multiply(double num) {
        Complex newNum;
        newNum.real = real * num;
        newNum.imag = imag * num;
        return newNum;
    }

    void show() {
        cout << real;
        if (imag > 0) {
            cout << "+";
        }
        cout << imag << "i" << endl;
    }
};

int main() {
    double real, imag;
    cin >> real >> imag;
    Complex c1 = {real, imag};

    cin >> real >> imag;
    Complex c2 = {real, imag};

    double d1;
    cin >> d1;

    Complex result;
    //showing the numbers:
    cout << "c1: ";
    c1.show();
    cout << "c2: ";
    c2.show();
    cout << "d1: " << d1 << endl;

    // Check the opertions where both operands are complex
    result = c1.add(c2);
    cout << "c1+c2: ";
    result.show();

    result = c1.subtract(c2);
    cout << "c1-c2: ";
    result.show();

    result = c1.multiply(c2);
    cout << "c1*c2: ";
    result.show();

    // Check the opertions where one operator is complex, other is double

    result = c1.add(d1);
    cout << "c1+d1: ";
    result.show();

    result = c1.subtract(d1);
    cout << "c1-d1: ";
    result.show();

    result = c1.multiply(d1);
    cout << "c1*d1: ";
    result.show();
}