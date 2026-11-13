#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Numero di elementi: ";
    if (!(cin >> n) || n < 0) return 1;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        if (!(cin >> a[i])) return 1;
    }
    if (n < 2) {
        cout << "Servono almeno due valori distinti" << endl;
        return 0;
    }
    int maximum = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] > maximum) maximum = a[i];
    }
    int second = 0;
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (a[i] < maximum && (!found || a[i] > second)) {
            second = a[i];
            found = true;
        }
    }
    // Il secondo massimo e' il secondo valore distinto piu' elevato.
    if (found) cout << second << endl;
    else cout << "Non esiste un secondo valore distinto" << endl;
    return 0;
}
