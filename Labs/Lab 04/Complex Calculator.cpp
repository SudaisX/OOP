#include <iostream>
using namespace std;

struct Complex {
    double real;
    double imag;

    void inputNumbers() {
        cin >> real;
        cin >> imag;
    }
};

void complexAddition(Complex num1, Complex num2) {
    double real = num1.real + num2.real;
    double imag = num1.imag + num2.imag;

    cout << "Addition: " << real << "+" << imag << "i" << endl;
}

void complexSubtraction(Complex num1, Complex num2) {
    double real = num1.real - num2.real;
    double imag = num1.imag - num2.imag;

    cout << "Subtraction: " << real;
    if (imag > 0) {
        cout << "+";
    }
    cout << imag << "i" << endl;
}

void complexMultiplication(Complex num1, Complex num2) {
    double real = num1.real * num2.real - num1.imag * num2.imag;
    double imag = num1.imag * num2.real + num1.real * num2.imag;

    cout << "Multiplication: " << real << "+" << imag << "i" << endl;
}

int main() {
    Complex num1, num2;
    num1.inputNumbers();
    num2.inputNumbers();

    complexAddition(num1, num2);
    complexSubtraction(num1, num2);
    complexMultiplication(num1, num2);
}