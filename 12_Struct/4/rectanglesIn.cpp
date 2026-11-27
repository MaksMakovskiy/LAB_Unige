#include <iostream>
using namespace std;

struct Point {
    double x;
    double y;
};

struct Rect {
    Point top_left;
    Point bottom_right;
};

Rect readRect(int n) {
    Rect r;
    cout << "Rettangolo " << n << " - coordinate del vertice in alto a sinistra: ";
    cin >> r.top_left.x >> r.top_left.y;
    cout << "Rettangolo " << n << " - coordinate del vertice in basso a destra: ";
    cin >> r.bottom_right.x >> r.bottom_right.y;
    while (r.bottom_right.x <= r.top_left.x || r.bottom_right.y >= r.top_left.y) {
        cout << "Vertici non validi (serve x_br > x_tl e y_br < y_tl) - riprova." << endl;
        cout << "Vertice in alto a sinistra: ";
        cin >> r.top_left.x >> r.top_left.y;
        cout << "Vertice in basso a destra: ";
        cin >> r.bottom_right.x >> r.bottom_right.y;
    }
    return r;
}

// true se inner e' contenuto (anche sul bordo) in outer
bool contains(const Rect &outer, const Rect &inner) {
    return inner.top_left.x >= outer.top_left.x &&
           inner.top_left.y <= outer.top_left.y &&
           inner.bottom_right.x <= outer.bottom_right.x &&
           inner.bottom_right.y >= outer.bottom_right.y;
}

int main() {
    Rect r1 = readRect(1);
    Rect r2 = readRect(2);

    bool in12 = contains(r2, r1);
    bool in21 = contains(r1, r2);
    if (in12 && in21)
        cout << "I due rettangoli coincidono" << endl;
    else if (in12)
        cout << "Il primo rettangolo è contenuto nel secondo" << endl;
    else if (in21)
        cout << "Il secondo rettangolo è contenuto nel primo" << endl;
    else
        cout << "Nessuno dei due rettangoli è contenuto nell'altro" << endl;
    return 0;
}
