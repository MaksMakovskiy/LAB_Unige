#include <iostream>
#include <string>
using namespace std;

int main() {
    // Input
    string msg;
    cout << "Inserisci una singola parola (senza spazi): ";
    cin >> msg;
    // Output
    cout << msg << "-" << msg << "-" << msg << endl;
    return 0;
}
