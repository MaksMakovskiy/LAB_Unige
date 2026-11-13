#include <iostream>
#include <string>
using namespace std;

int ricerca(string str, char c) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == c) return int(i);
    }
    return -1;
}

int main() {
    string str;
    cout << "Inserisci una stringa: ";
    if (!getline(cin, str)) return 1;
    char c;
    cout << "Carattere da cercare: ";
    if (!(cin >> c)) return 1;
    int position = ricerca(str, c);
    if (position >= 0) cout << "Posizione: " << position << endl;
    else cout << "Carattere assente" << endl;
    return 0;
}
