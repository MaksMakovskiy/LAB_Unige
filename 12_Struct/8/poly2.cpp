#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

struct Point {
    double x;
    double y;
};

double dist(const Point &p, const Point &q) {
    return sqrt(pow(q.x - p.x, 2) + pow(q.y - p.y, 2));
}

string polygonName(int sides) {
    switch (sides) {
        case 3: return "triangolo";
        case 4: return "rettangolo";
        case 5: return "pentagono";
        case 6: return "esagono";
        case 7: return "ettagono";
        case 8: return "ottagono";
        case 9: return "ennagono";
        case 10: return "decagono";
        default: return "poligono";
    }
}

int main() {
    const int N = 5; // numero di punti (modificabile)
    const double TOL = 1e-6;
    vector<Point> line(N);
    for (int i = 0; i < N; ++i) {
        cout << "Inserire le coordinate del punto " << i + 1 << ": ";
        cin >> line[i].x >> line[i].y;
    }

    double total = 0;
    bool sameLength = true;
    double first = N > 1 ? dist(line[0], line[1]) : 0;
    for (int i = 0; i < N - 1; ++i) {
        double d = dist(line[i], line[i + 1]);
        total += d;
        if (fabs(d - first) > TOL) sameLength = false;
    }
    cout << "Lunghezza totale della spezzata: " << total << endl;
    if (sameLength)
        cout << "I lati hanno tutti la stessa lunghezza" << endl;
    else
        cout << "I lati non hanno tutti la stessa lunghezza" << endl;

    bool closed = N > 1 && dist(line[0], line[N - 1]) < TOL;
    if (closed) {
        cout << "La linea è chiusa e quindi definisce un " << polygonName(N - 1);
        if (sameLength) cout << " regolare";
        cout << endl;
    } else {
        cout << "La linea è aperta" << endl;
    }
    return 0;
}
