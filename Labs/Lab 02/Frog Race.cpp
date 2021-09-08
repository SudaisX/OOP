#include <iostream>
using namespace std;

void race(int primeUp, int primeDown, int tronUp, int tronDown) {
    int distPrime = 0, distTron = 0;
    int jumps = 0;

    while (true) {
        jumps++;

        if ((distPrime + primeUp) >= 1000 && (distTron + tronUp) >= 1000) {
            distPrime += primeUp;
            distTron += tronUp;
        } else if ((distPrime + primeUp) >= 1000 && distTron < 1000) {
            distPrime += primeUp;
            distTron += (tronUp - tronDown);
        } else if (distPrime < 1000 && (distTron + tronUp) >= 1000) {
            distPrime += (primeUp - primeDown);
            distTron += tronUp;
        } else {
            distPrime += (primeUp - primeDown);
            distTron += (tronUp - tronDown);
        }

        cout << "Jump " << jumps << endl;

        if (distPrime >= 1000 && distTron >= 1000) {
            cout << "Frog Prime has cleared the well!" << endl;
            cout << "Frogatron has cleared the well!" << endl;
            break;
        } else if (distPrime >= 1000 && distTron < 1000) {
            cout << "Frog Prime has cleared the well!" << endl;
            cout << "Frogatron is at " << distTron << " meters." << endl;
            break;
        } else if (distPrime < 1000 && distTron >= 1000) {
            cout << "Frog Prime is at " << distPrime << " meters." << endl;
            cout << "Frogatron has cleared the well!" << endl;
            break;
        } else {
            cout << "Frog Prime is at " << distPrime << " meters." << endl;
            cout << "Frogatron is at " << distTron << " meters." << endl;
        }
    }

    cout << "***** END OF RACE *****" << endl;

    if (distPrime >= 1000 && distTron >= 1000) {
        cout << "TIE in " << jumps << " jumps!" << endl;
    } else if (distPrime > distTron) {
        cout << "Frog Prime wins in " << jumps << " jumps!" << endl;
    } else {
        cout << "Frogatron wins in " << jumps << " jumps!" << endl;
    }
}

int main(int argc, char** argv) {
    int prime_up, prime_down, tron_up, tron_down;
    cin >> prime_up >> prime_down >> tron_up >> tron_down;
    race(prime_up, prime_down, tron_up, tron_down);
    return 0;
}