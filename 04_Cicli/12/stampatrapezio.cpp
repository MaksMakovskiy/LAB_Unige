#include <iostream>
using namespace std;

int main() {
    // Input
    int b, B;
    cin >> b >> B;
    if (b <= 0 || B <= 0 || b > B) {
        cout << "Basi non valide" << endl;
        return 1;
    }
    // Trapezio
    for (int i = b; i <= B; ++i) {
        for (int j = 0; j < i; ++j)
            cout << 'x';
        cout << endl;
    }
    return 0;
}
