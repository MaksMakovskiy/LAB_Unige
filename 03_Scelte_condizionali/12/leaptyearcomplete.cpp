#include <iostream>
using namespace std;

int main() {
    // Input
    int anno;
    cin >> anno;
    // Verifica
    if (anno % 400 == 0 || (anno % 4 == 0 && anno % 100 != 0))
        cout << "Anno bisestile" << endl;
    else
        cout << "Anno non bisestile" << endl;
    return 0;
}
