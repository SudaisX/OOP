#include <iostream>
using namespace std;

class Payment {
    double amount;

   public:
    Payment(double amt = 0) : amount(amt) {}

    void paymentDetails() {
        cout << amount << endl;
    }
};

class CashPayment : public Payment {
   public:
    CashPayment(double amt = 0) : Payment(amt) {}

    void paymentDetails() {
        cout << "Amount of cash payment: $";
        Payment::paymentDetails();
    }
};

class CreditCardPayment : public Payment {
    string name, expirationDate, creditCardNo;

   public:
    CreditCardPayment(double amt = 0, string n = "", string expDate = "", string cCardNo = "") : Payment(amt) {
        name = n;
        expirationDate = expDate;
        creditCardNo = cCardNo;
    }

    void paymentDetails() {
        cout << "Amount of credit card payment: $";
        Payment::paymentDetails();
        cout << "Name on the credit card: " << name << endl;
        cout << "Expiration date: " << expirationDate << endl;
        cout << "Credit card number: " << creditCardNo << endl;
    }
};
int main()