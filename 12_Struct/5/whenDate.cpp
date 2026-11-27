#include <iostream>
using namespace std;

struct Date {
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

bool isLeap(unsigned int y) {
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

unsigned int daysInMonth(unsigned int m, unsigned int y) {
    switch (m) {
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeap(y) ? 29 : 28;
        default:
            return 31;
    }
}

bool isValid(const Date &d) {
    if (d.month < 1 || d.month > 12) return false;
    return d.day >= 1 && d.day <= daysInMonth(d.month, d.year);
}

int main() {
    Date D, D1;
    cout << "Inserire la data corrente (anno mese giorno): ";
    cin >> D.year >> D.month >> D.day;

    cout << "Inserire una data qualsiasi (anno mese giorno): ";
    cin >> D1.year >> D1.month >> D1.day;
    while (!isValid(D1)) {
        cout << "Data non valida - riprova (anno mese giorno): ";
        cin >> D1.year >> D1.month >> D1.day;
    }

    int cmp; // -1 passata, 0 oggi, 1 futura
    if (D1.year != D.year)
        cmp = D1.year < D.year ? -1 : 1;
    else if (D1.month != D.month)
        cmp = D1.month < D.month ? -1 : 1;
    else if (D1.day != D.day)
        cmp = D1.day < D.day ? -1 : 1;
    else
        cmp = 0;

    cout << "La data " << D1.day << "/" << D1.month << "/" << D1.year;
    if (cmp < 0)
        cout << " è passata" << endl;
    else if (cmp > 0)
        cout << " è futura" << endl;
    else
        cout << " è oggi" << endl;
    return 0;
}
