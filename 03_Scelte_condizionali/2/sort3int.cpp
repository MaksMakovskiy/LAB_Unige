#include <iostream>
using namespace std;

int main() {
    // Input
    int a0, a1, a2;
    cout << "Inserisci tre numeri interi: ";
    cin >> a0 >> a1 >> a2;
    // Ordinamento
    int aux = a1;
    if (a0 > a1) {
        a1 = a0;
        a0 = aux;
        aux = a1;
    }
    if (a0 > a2) {
        a1 = a0;
        a0 = a2;
        a2 = aux;
    } else if (a1 > a2) {
        a1 = a2;
        a2 = aux;
    }
    // Output
    cout << "I numeri inseriti, in ordine crescente, sono: "
         << a0 << "<" << a1 << "<" << a2 << endl;
    return 0;
}
