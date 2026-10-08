#include <iostream>
using namespace std;

int main() {
    // Input
    int n;
    cin >> n;
    // Calcolo
    long long valore = n;
    if (valore < 0)
        valore = -valore;
    // Output
    cout << valore << endl;
    return 0;
}
