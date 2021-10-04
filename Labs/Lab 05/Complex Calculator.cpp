#include<iostream>
using namespace std;

struct Complex {
    double real;
    double imag;
};

Complex add(Complex num1, Complex num2) {
    Complex num;
    num.real = num1.real + num2.real;
    num.imag = num1.imag + num2.imag;
    return num;
}

Complex add(Complex num1, double num2) {
    Complex num;
    num.real = num1.real + num2;
    num.imag = num1.imag;
    return num;
}

Complex subtract(Complex num1, Complex num2) {
    Complex num;
    num.real = num1.real - num2.real;
    num.imag = num1.imag - num2.imag;
    return num;
}

Complex subtract(Complex num1, double num2) {
    Complex num;
    num.real = num1.real - num2;
    num.imag = num1.imag;
    return num;
}

Complex multiply(Complex num1, Complex num2) {
    Complex num;
    num.real = num1.real * num2.real - num1.imag * num2.imag;
    num.imag = num1.imag * num2.real + num1.real * num2.imag;
    return num;
}

Complex multiply(Complex num1, double num2) {
    Complex num;
    num.real = num1.real * num2;
    num.imag = num1.imag * num2;
    return num;
}

void show(Complex num) {
    cout << num.real;
    if (num.imag > 0) {
        cout << "+";
    }
    cout << num.imag << "i" << endl;
}

int main()
{
    Complex c1, c2;
    cin>>c1.real>>c1.imag;
    cin>>c2.real>>c2.imag;

    double d1;
    cin>>d1;

    cout<<"c1+c2: "; show(add(c1,c2));
    cout<<"c1-c2: "; show(subtract(c1,c2));
    cout<<"c1*c2: "; show(multiply(c1,c2));

    
    cout<<"c1+d1: "; show(add(c1,d1));
    cout<<"c1-d1: "; show(subtract(c1,d1));
    cout<<"c1*d1: "; show(multiply(c1,d1));
}