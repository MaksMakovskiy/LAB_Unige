#include <iostream>
#include <string>
using namespace std;

bool containsSubstring(const string& str, const string& substring) {
    if (substring.length() > str.length()) return false;
    for (size_t i = 0; i <= str.length() - substring.length(); ++i) {
        size_t j = 0;
        while (j < substring.length() && str[i + j] == substring[j]) ++j;
        if (j == substring.length()) return true;
    }
    return false;
}

int main() {
    string str;
    cout << "Inserisci una stringa: ";
    if (!getline(cin, str)) return 1;
    string substring;
    cout << "Inserisci la sottostringa: ";
    if (!getline(cin, substring)) return 1;
    if (containsSubstring(str, substring)) cout << "Sottostringa presente" << endl;
    else cout << "Sottostringa assente" << endl;
    return 0;
}
