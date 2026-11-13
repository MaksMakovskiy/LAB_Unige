#include <iostream>
#include <string>
using namespace std;

void reverseString(string& str) {
    for (size_t i = 0; i < str.length() / 2; ++i) {
        char temp = str[i];
        str[i] = str[str.length() - 1 - i];
        str[str.length() - 1 - i] = temp;
    }
}

int main() {
    string str;
    cout << "Inserisci una stringa: ";
    if (!getline(cin, str)) return 1;
    reverseString(str);
    cout << str << endl;
    return 0;
}
