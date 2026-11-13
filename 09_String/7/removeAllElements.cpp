#include <iostream>
#include <string>
using namespace std;

int ricerca(string str, char c) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == c) return int(i);
    }
    return -1;
}

bool remove(string& str, int p) {
    if (p < 0 || size_t(p) >= str.length()) return false;
    str.erase(p, 1);
    return true;
}

void RemoveAll(string& str, char c) {
    int position = ricerca(str, c);
    while (position != -1) {
        remove(str, position);
        position = ricerca(str, c);
    }
}

int main() {
    string str;
    cout << "Inserisci una stringa: ";
    if (!getline(cin, str)) return 1;
    char c;
    cout << "Carattere da eliminare: ";
    if (!(cin >> c)) return 1;
    RemoveAll(str, c);
    cout << str << endl;
    return 0;
}
