#include <iostream>
#include <string>
using namespace std;

int main() {
    int num;
    cout << "Inserisci un numero positivo: ";
    if (!(cin >> num) || num <= 0) return 1;
    string str = "";
    for (int i = 0; i < num; ++i) str = str + "AH";
    cout << str << endl;
    return 0;
}
