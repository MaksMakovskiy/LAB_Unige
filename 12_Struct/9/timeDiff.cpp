#include <iostream>
using namespace std;

struct Time {
    unsigned int h;
    unsigned int m;
    unsigned int s;
};

bool isValid(const Time &t) {
    return t.h < 24 && t.m < 60 && t.s < 60;
}

unsigned int toSeconds(const Time &t) {
    return t.h * 3600 + t.m * 60 + t.s;
}

int main() {
    Time T1, T2;
    cout << "Inserire il primo orario (ore minuti secondi): ";
    cin >> T1.h >> T1.m >> T1.s;
    cout << "Inserire il secondo orario (ore minuti secondi): ";
    cin >> T2.h >> T2.m >> T2.s;

    if (!isValid(T1) || !isValid(T2)) {
        cout << "Dati non validi" << endl;
        return 1;
    }
    if (toSeconds(T1) > toSeconds(T2)) {
        cout << "Il primo orario è successivo al secondo" << endl;
        return 1;
    }

    unsigned int diff = toSeconds(T2) - toSeconds(T1);
    Time D;
    D.h = diff / 3600;
    D.m = (diff % 3600) / 60;
    D.s = diff % 60;
    cout << "Sono trascorse " << D.h << " ore, " << D.m << " minuti e "
         << D.s << " secondi" << endl;
    return 0;
}
