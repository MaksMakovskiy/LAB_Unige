#include <iostream>
using namespace std;

int main() {
    // Output
    cout << boolalpha;
    cout << "tre e' maggiore di uno = " << (3 > 1) << endl;
    cout << "quattro diviso due e' minore di zero = " << (4 / 2 < 0) << endl;
    cout << "il carattere zero e' uguale al valore zero = " << ('0' == 0) << endl;
    cout << "dieci mezzi e' compreso fra zero escluso e dieci incluso = "
         << (10.0 / 2 > 0 && 10.0 / 2 <= 10) << endl;
    cout << "non e' vero che tre e' maggiore di due e minore di uno = "
         << (!(3 > 2 && 3 < 1)) << endl;
    cout << "tre minore di meno cinque implica sette maggiore di zero = "
         << (!(3 < -5) || 7 > 0) << endl;
    return 0;
}
