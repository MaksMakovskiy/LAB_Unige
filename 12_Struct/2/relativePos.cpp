#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x;
    double y;
};

int main() {
    const double TOL = 1e-6;
    cout << "Inserire le coordinate del punto P1: ";
    Point P1;
    cin >> P1.x >> P1.y;
    cout << "Inserire le coordinate del punto P2: ";
    Point P2;
    cin >> P2.x >> P2.y;

    if (fabs(P1.x - P2.x) < TOL && fabs(P1.y - P2.y) < TOL) {
        cout << "I punti sono uguali" << endl;
    } else {
        cout << "Il secondo punto è ";
        if (P2.y > P1.y)
            cout << "in alto ";
        else
            cout << "in basso ";
        if (P2.x > P1.x)
            cout << "a destra ";
        else
            cout << "a sinistra ";
        cout << " rispetto al primo" << endl;
    }
    return 0;
}
