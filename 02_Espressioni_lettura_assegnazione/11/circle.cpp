#include <iostream>
using namespace std;

int main() {
    // Input
    float raggio;
    cout << "Inserisci il raggio: ";
    cin >> raggio;
    // Calcolo
    float circonferenza = 2 * 3.14 * raggio;
    float area = 3.14 * raggio * raggio;
    // Output
    cout << "Circonferenza: " << circonferenza << "\nArea: " << area << endl;
    return 0;
}
