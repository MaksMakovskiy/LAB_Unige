#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x;
    double y;
};

int main() {
    cout << "Inserire le coordinate del punto P1: ";
    Point P1;
    cin >> P1.x >> P1.y;
    cout << "Inserire le coordinate del punto P2: ";
    Point P2;
    cin >> P2.x >> P2.y;

    double d = sqrt(pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2));
    cout << "La distanza tra i due punti è " << d << endl;
    return 0;
}
