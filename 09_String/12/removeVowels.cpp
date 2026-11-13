#include <iostream>
#include <string>
using namespace std;

string removeVowels(const string& str) {
    string result = "";
    for (size_t i = 0; i < str.length(); ++i) {
        char c = str[i];
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            result = result + c;
        }
    }
    return result;
}

int main() {
    string str;
    cout << "Inserisci una stringa: ";
    if (!getline(cin, str)) return 1;
    cout << removeVowels(str) << endl;
    return 0;
}
