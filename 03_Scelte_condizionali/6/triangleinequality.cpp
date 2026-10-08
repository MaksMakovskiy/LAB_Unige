#include <iostream>
using namespace std;

int main() {
    // Input
    double a, b, c;
    cin >> a >> b >> c;
    // Verifica
    if (a > 0 && b > 0 && c > 0 && a <= b + c && b <= a + c && c <= a + b)
        cout << "Disuguaglianza triangolare verificata" << endl;
    else
        cout << "Non possono essere lati di un triangolo" << endl;
    return 0;
}
