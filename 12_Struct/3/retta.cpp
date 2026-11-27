#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x;
    double y;
};

struct StraightLine {
    double m; // coefficiente angolare
    double q; // quota
};

int main() {
    const double TOL = 1e-6;
    cout << "Inserire i parametri della retta R: ";
    StraightLine R;
    cin >> R.m >> R.q;
    cout << "Inserire le coordinate del punto P: ";
    Point P;
    cin >> P.x >> P.y;

    cout << "La retta R di equazione y=" << R.m << "x+" << R.q;
    if (fabs(P.y - R.m * P.x - R.q) < TOL)
        cout << " passa ";
    else
        cout << " non passa ";
    cout << "per il punto di coordinate (" << P.x << ", " << P.y << ")" << endl;
    return 0;
}
