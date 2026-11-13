#include <iostream>
#include <string>
using namespace std;

bool isValidPositiveNumber(const string& str) {
    if (str.length() == 0 || str[0] == '0') return false;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] < '0' || str[i] > '9') return false;
    }
    return true;
}

int stringToNumber(const string& str) {
    int number = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        number = number * 10 + str[i] - '0';
    }
    return number;
}

int main() {
    string str;
    bool valid = false;
    do {
        cout << "Inserisci un intero positivo rappresentabile con int: ";
        if (!getline(cin, str)) return 1;
        valid = isValidPositiveNumber(str);
        // Su questa piattaforma int ha un massimo di 2147483647.
        // Confrontare le cifre prima della conversione evita overflow.
        const string maximum = "2147483647";
        if (str.length() > maximum.length()) valid = false;
        if (str.length() == maximum.length()) {
            size_t i = 0;
            while (i < str.length() && str[i] == maximum[i]) ++i;
            if (i < str.length() && str[i] > maximum[i]) valid = false;
        }
        if (!valid) cout << "Numero non valido. Riprova." << endl;
    } while (!valid);
    cout << stringToNumber(str) << endl;
    return 0;
}
