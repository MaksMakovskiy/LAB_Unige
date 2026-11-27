#include <iostream>
#include <cmath>
using namespace std;

struct IntPoint {
    int x;
    int y;
};

struct Triangle {
    IntPoint A, B, C;
    double area;
    double perimeter;
};

double dist(const IntPoint &p, const IntPoint &q) {
    return sqrt(pow(q.x - p.x, 2) + pow(q.y - p.y, 2));
}

bool samePoint(const IntPoint &p, const IntPoint &q) {
    return p.x == q.x && p.y == q.y;
}

Triangle readTriangle(int n) {
    Triangle T;
    bool ok = false;
    while (!ok) {
        cout << "Triangolo " << n << " - coordinate (intere) dei vertici A B C: ";
        cin >> T.A.x >> T.A.y >> T.B.x >> T.B.y >> T.C.x >> T.C.y;
        ok = !(samePoint(T.A, T.B) || samePoint(T.B, T.C) || samePoint(T.A, T.C));
        if (!ok) cout << "I tre vertici non sono distinti - riprova." << endl;
    }
    double a = dist(T.B, T.C), b = dist(T.A, T.C), c = dist(T.A, T.B);
    T.perimeter = a + b + c;
    double p = T.perimeter / 2;
    double h = p * (p - a) * (p - b) * (p - c);
    T.area = h > 0 ? sqrt(h) : 0;
    return T;
}

int main() {
    Triangle T1 = readTriangle(1);
    Triangle T2 = readTriangle(2);
    Triangle T3 = readTriangle(3);

    cout << "Area triangolo 1: " << T1.area << endl;
    cout << "Area triangolo 2: " << T2.area << endl;
    cout << "Area triangolo 3: " << T3.area << endl;

    int best = 1;
    double maxArea = T1.area;
    if (T2.area > maxArea) {
        best = 2;
        maxArea = T2.area;
    }
    if (T3.area > maxArea) {
        best = 3;
        maxArea = T3.area;
    }
    cout << "Il triangolo con area maggiore è il triangolo " << best
         << " (area " << maxArea << ")" << endl;
    return 0;
}
