#include <iostream>
using namespace std;

class Complex {
   private:
    double real, imag;

   public:
    Complex(double realn = 0, double imagn = 0) : real(realn), imag(imagn) {}

    friend ostream &operator<<(ostream &output, const Complex &C) {
        output << C.real;
        if (C.imag > 0) {
            output << "+";
        }
        output << C.imag << "i";
        return output;
    }

    friend istream &operator>>(istream &input, Complex &C) {
        input >> C.real >> C.imag;
        return input;
    }

    Complex operator+(Complex &num) {
        Complex newNum;
        newNum.real = real + num.real;
        newNum.imag = imag + num.imag;
        return newNum;
    }

    Complex operator+(double num) {
        Complex newNum;
        newNum.real = real + num;
        newNum.imag = imag;
        return newNum;
    }

    Complex operator-(Complex num) {
        Complex newNum;
        newNum.real = real - num.real;
        newNum.imag = imag - num.imag;
        return newNum;
    }

    Complex operator-(double num) {
        Complex newNum;
        newNum.real = real - num;
        newNum.imag = imag;
        return newNum;
    }

    Complex operator*(Complex num) {
        Complex newNum;
        newNum.real = real * num.real - imag * num.imag;
        newNum.imag = imag * num.real + real * num.imag;
        return newNum;
    }

    Complex operator*(double num) {
        Complex newNum;
        newNum.real = real * num;
        newNum.imag = imag * num;
        return newNum;
    }
};

int main() {
    Complex c1, c2;

    cin >> c1;  //extraction operator is overloaded
    cin >> c2;

    double d1;
    cin >> d1;

    Complex result;
    //showing the numbers:
    cout << "c1: " << c1 << endl;  // insertion operator is overloaded
    cout << "c2: " << c2 << endl;
    cout << "d1: " << d1 << endl;

    // Check the opertions where both operands are complex
    result = c1 + c2;
    cout << "c1+c2: " << result << endl;

    result = c1 - c2;
    cout << "c1-c2: " << result << endl;

    result = c1 * c2;
    cout << "c1*c2: " << result << endl;

    // Check the opertions where one operator is complex, other is double

    result = c1 + d1;
    cout << "c1+d1: " << result << endl;

    result = c1 - d1;
    cout << "c1-d1: " << result << endl;

    result = c1 * d1;
    cout << "c1*d1: " << result << endl;
}