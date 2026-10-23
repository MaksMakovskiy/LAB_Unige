#include <iostream>
#include <cstdlib>
using namespace std;

float average(int hm) {
    if (hm <= 0) {
        cout << "Il numero deve essere positivo" << endl;
        exit(0);
    }
    float sum = 0;
    for (int i = 0; i < hm; ++i) {
        cout << "\nInserisci un numero ";
        float x;
        if (!(cin >> x)) exit(1);
        sum = sum + x;
    }
    return sum / hm;
}

int main() {
    cout << "Di quanti numeri vuoi fare la media?";
    int how_many;
    if (!(cin >> how_many)) return 1;
    float avg = average(how_many);
    cout << "\nLa media è " << avg << endl;
    return 0;
}
