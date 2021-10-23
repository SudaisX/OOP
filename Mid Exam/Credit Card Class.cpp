#include <iostream>
#include <string>
using namespace std;

class CreditCard {
   public:
    string name, bank, cardNumber;
    int balance, spendinglimit;

    CreditCard() : name(""), bank(""), cardNumber(""), balance(0), spendinglimit(0) {}
    CreditCard(string n, string cardNum) : name(n), cardNumber(cardNum), balance(0), spendinglimit(0) {}
    CreditCard(string n, string bankName, string cardNum) : name(n), bank(bankName), cardNumber(cardNum), balance(0), spendinglimit(0) {}

    void increaseSpendingLimit(int amount) {
        if (amount > 2000) {
            cout << "Your " << bank << " Credit Card spending limit is 2000.Can not exceed the spending limit amount more than 2000 dollars." << endl;
        } else {
            spendinglimit += amount;
        }
    }

    void charge(int price) {
        balance += price;
    }

    void make_payment(int amount) {
        if (amount <= spendinglimit && amount <= balance) {
            balance -= amount;
        } else {
            if (amount > balance) {
                cout << "Insufficient balance in your " << bank << " card." << endl;
            } else if (amount > spendinglimit) {
                cout << "You can not spend more than " << spendinglimit << " using your " << bank << " credit card." << endl;
            }
        }

        // cout << amount << " " << spendinglimit << " " << balance << endl;
    }
};

class Wallet {
   public:
    CreditCard my_cards[3];

    Wallet() {
    }
    //view Wallet info
    void view_wallet_info() {
        for (int i = 0; i <= 2; i++) {
            cout << "Customer = " << my_cards[i].name;
            cout << "\nBank = " << my_cards[i].bank;
            cout << "\nCard Number = " << my_cards[i].cardNumber;
            cout << "\nBalance = " << my_cards[i].balance;
            cout << "\nSpending Limit = " << my_cards[i].spendinglimit;
            cout << "\n";
        }
    }
};
int main() {
    string customername;
    cin >> customername;

    Wallet mywallet;
    mywallet.my_cards[0] = CreditCard(customername, "Bank Al Habib", "56 5391 0375 9387 5309");
    mywallet.my_cards[1] = CreditCard(customername, "Meezan Bank", "58 3485 0399 3395 1954");
    mywallet.my_cards[2] = CreditCard(customername, "Islamic Bank", "60 5391 0375 9387 5309");

    cin.ignore();
    // increasing spending limit of each card

    int amount;
    for (int i = 0; i <= 2; i++) {
        cin >> amount;
        mywallet.my_cards[i].increaseSpendingLimit(amount);
    }

    //Charge different amount in to each card
    double charge_amount;
    for (int i = 0; i <= 2; i++) {
        cin >> charge_amount;
        mywallet.my_cards[i].charge(charge_amount);
    }

    // making some/different payments through each card.
    double bill;
    for (int i = 0; i <= 2; i++) {
        cin >> bill;
        mywallet.my_cards[i].make_payment(bill);
    }

    // view wallet info
    mywallet.view_wallet_info();

    return 0;
}