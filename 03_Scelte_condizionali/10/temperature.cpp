#include <iostream>
using namespace std;

int main() {
    // Input
    int Temp;
    cin >> Temp;
    // Classificazione
    if (Temp < -20 || Temp > 40)
        cout << "Non ci credo, il termometro deve essere rotto" << endl;
    else if (Temp <= 0)
        cout << "Freddo incredibile" << endl;
    else if (Temp <= 15)
        cout << "Freddo" << endl;
    else if (Temp <= 23)
        cout << "Normale" << endl;
    else if (Temp <= 30)
        cout << "Caldo" << endl;
    else
        cout << "Caldo da morire" << endl;
    return 0;
}
