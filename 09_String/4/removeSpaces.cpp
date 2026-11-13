#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Inserisci una stringa: ";
    if (!getline(cin, str)) return 1;
    string result = "";
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] != ' ') result = result + str[i];
    }
    cout << "La string senza spazi e' " << result << endl;
    return 0;
}
