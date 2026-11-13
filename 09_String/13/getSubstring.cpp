#include <iostream>
#include <string>
using namespace std;

string getSubstr(const string& str, int i, int j) {
    if (i < 0 || j < i || size_t(j) >= str.length()) return "";
    return str.substr(i, j - i + 1);
}

int main() {
    string str;
    cout << "Inserisci una stringa: ";
    if (!getline(cin, str)) return 1;
    int i, j;
    cout << "Indici iniziale e finale (inclusi): ";
    if (!(cin >> i >> j)) return 1;
    if (i < 0 || j < i || size_t(j) >= str.length()) {
        cout << "Indici non validi" << endl;
        return 1;
    }
    cout << getSubstr(str, i, j) << endl;
    return 0;
}
