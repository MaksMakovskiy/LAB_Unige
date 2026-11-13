#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Inserisci una stringa: ";
    if (!getline(cin, str)) return 1;
    int count = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == ' ') ++count;
    }
    cout << str << " ha " << count << " spazi!" << endl;
    return 0;
}
