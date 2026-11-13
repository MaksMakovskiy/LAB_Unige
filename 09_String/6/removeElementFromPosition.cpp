#include <iostream>
#include <string>
using namespace std;

bool remove(string& str, int p) {
    if (p < 0 || size_t(p) >= str.length()) return false;
    str.erase(p, 1);
    return true;
}

int main() {
    string str;
    cout << "Inserisci una stringa: ";
    if (!getline(cin, str)) return 1;
    int p;
    cout << "Posizione da eliminare: ";
    if (!(cin >> p)) return 1;
    if (!remove(str, p)) cout << "Posizione non valida" << endl;
    cout << str << endl;
    return 0;
}
