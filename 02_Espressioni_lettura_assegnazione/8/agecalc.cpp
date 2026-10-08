#include <iostream>
using namespace std;

int main() {
    // Input
    int anno;
    cout << "In che anno sei nato? ";
    cin >> anno;
    // Calcolo
    int eta = 2026 - anno;
    // Output
    cout << "Hai " << eta << " anni" << endl;
    return 0;
}
