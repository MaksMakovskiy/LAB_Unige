#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int leggiTemperatura() {
    int temperatura;
    cout << "Inserisci la temperatura in gradi Celsius: ";
    if (!(cin >> temperatura)) exit(1);
    return temperatura;
}

string descriviTemperatura(int temperatura) {
    if (temperatura < -20 || temperatura > 40)
        return "Non ci credo, il termometro deve essere rotto";
    if (temperatura <= 0) return "Freddo incredibile";
    if (temperatura <= 15) return "Freddo";
    if (temperatura <= 23) return "Normale";
    if (temperatura <= 30) return "Caldo";
    return "Caldo da morire";
}

void stampaRisultato(string messaggio) {
    cout << messaggio << endl;
}

int main() {
    int temperatura = leggiTemperatura();
    string messaggio = descriviTemperatura(temperatura);
    stampaRisultato(messaggio);
    return 0;
}
