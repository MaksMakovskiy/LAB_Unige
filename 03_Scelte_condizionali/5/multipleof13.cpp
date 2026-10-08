#include <iostream>
using namespace std;

int main() {
    // Input
    int n;
    cin >> n;
    // Verifica
    if (n % 13 == 0)
        cout << "Divisibile per 13" << endl;
    else
        cout << "Non divisibile per 13" << endl;
    return 0;
}
