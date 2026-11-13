#include <iostream>
#include <string>
using namespace std;

string numberToString(int number) {
    string result = "";
    do {
        char digit = '0' + number % 10;
        result = digit + result;
        number /= 10;
    } while (number > 0);
    return result;
}

int main() {
    int number;
    cout << "Inserisci un numero positivo: ";
    if (!(cin >> number) || number <= 0) return 1;
    cout << numberToString(number) << endl;
    return 0;
}
