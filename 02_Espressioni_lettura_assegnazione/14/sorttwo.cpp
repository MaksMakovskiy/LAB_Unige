#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Input
    double a, b;
    cin >> a >> b;
    // Calcolo
    double media = (a + b) / 2;
    double semidistanza = abs(a - b) / 2;
    // Output
    cout << media - semidistanza << " " << media + semidistanza << endl;
    return 0;
}
