#include <iostream>
using namespace std;

void fixSequence(string badSequence, string correctedSequence) {
    int i = 0;
    while (badSequence[i] != '\0') {
        if (badSequence[i] == 'A' || badSequence[i] == tolower('A') ||
            badSequence[i] == 'C' || badSequence[i] == tolower('C') ||
            badSequence[i] == 'G' || badSequence[i] == tolower('G') ||
            badSequence[i] == 'T' || badSequence[i] == tolower('T')) {
            correctedSequence.push_back(toupper(badSequence[i]));
        }
        i++;
    };
    cout << correctedSequence;
}

int main() {
    string badSequence;
    string correctedSequence = "";

    getline(cin, badSequence);
    fixSequence(badSequence, correctedSequence);
}