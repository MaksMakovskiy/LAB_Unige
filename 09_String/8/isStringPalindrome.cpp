#include <iostream>
#include <string>
using namespace std;

bool isStringPalindrome(const string& str) {
    for (size_t i = 0; i < str.length() / 2; ++i) {
        if (str[i] != str[str.length() - 1 - i]) return false;
    }
    return true;
}

int main() {
    string str;
    cout << "Inserisci una stringa: ";
    if (!getline(cin, str)) return 1;
    if (isStringPalindrome(str)) cout << "La stringa e' palindroma" << endl;
    else cout << "La stringa non e' palindroma" << endl;
    return 0;
}
