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

int main() {
    Triangle T;
    cout << "Inserire le coordinate (intere) del vertice A: ";
    cin >> T.A.x >> T.A.y;
    cout << "Inserire le coordinate (intere) del vertice B: ";
    cin >> T.B.x >> T.B.y;
    cout << "Inserire le coordinate (intere) del vertice C: ";
    cin >> T.C.x >> T.C.y;

    if (samePoint(T.A, T.B) || samePoint(T.B, T.C) || samePoint(T.A, T.C)) {
        cout << "I tre vertici non sono distinti" << endl;
        return 1;
    }

    double a = dist(T.B, T.C), b = dist(T.A, T.C), c = dist(T.A, T.B);
    T.perimeter = a + b + c;
    double p = T.perimeter / 2; // semiperimetro
    double h = p * (p - a) * (p - b) * (p - c);
    T.area = h > 0 ? sqrt(h) : 0; // formula di Erone

    cout << "Perimetro: " << T.perimeter << endl;
    cout << "Area: " << T.area << endl;
    return 0;
}
