#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Inserisci una stringa: ";
    if (!getline(cin, str)) return 1;
    bool isNumber = str.length() > 0 && str[0] != '0';
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] < '0' || str[i] > '9') isNumber = false;
    }
    if (isNumber) cout << str << " e' un numero positivo." << endl;
    else cout << str << " non e' un numero positivo." << endl;
    return 0;
}
