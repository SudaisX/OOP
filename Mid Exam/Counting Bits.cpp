#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'getOneBits' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER n as parameter.
 */

vector<int> getOneBits(int n) {
    vector<int> binary;
    for (int i = 1; n > 0; i++) {
        binary.push_back(n % 2);
        n = n / 2;
    }
    reverse(binary.begin(), binary.end());

    vector<int> positions;
    int count = 0;
    for (int i = 0; i < binary.size(); i++) {
        if (binary[i] == 1) {
            count += 1;
        }
    }
    positions.push_back(count);
    for (int i = 0; i < binary.size(); i++) {
        if (binary[i] == 1) {
            positions.push_back(i + 1);
        }
    }

    return positions;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<int> result = getOneBits(n);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
