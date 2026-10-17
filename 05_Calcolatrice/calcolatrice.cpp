#include <iostream>
using namespace std;

int main()
{
    // 5.1: lettura dei tasti e display.
    char c;
    double disp = 0;

    // 5.2: numero costruito una cifra alla volta.
    double num = 0;

    // 5.3: costruzione della parte decimale.
    double fattore = 0.1;
    bool decimale = false;

    // 5.5: accumulatore e stato del conto.
    double acc = 0;
    bool prima = true;

    // 5.6: operazione pendente.
    char op = '+';

    cout << "Calcolatrice per numeri decimali\n";

    while (true) {
        if (!(cin >> c)) {
            break;
        }

        if (c >= '0' && c <= '9') {
            int cifra = c - '0';
            if (decimale) {
                num = num + cifra * fattore;
                fattore = fattore / 10;
            }
            else {
                num = 10 * num + cifra;
            }
            disp = num;
        }
        else if (c == '.' && !decimale) {
            decimale = true;
            disp = num;
        }
        else if (c == '+' || c == '-' || c == '/' ||
                 c == 'x' || c == 'X' || c == '*' || c == '=') {
            // 5.7: controlliamo il divisore prima di eseguire il calcolo.
            if (!prima && op == '/' && num == 0) {
                cout << "Errore: divisione per zero. Calcolo azzerato.\n";
                acc = 0;
                num = 0;
                disp = 0;
                fattore = 0.1;
                decimale = false;
                prima = true;
                cout << "Display:\t" << disp << endl;
                continue;
            }

            if (prima) {
                acc = num;
            }
            else {
                // 5.6: usiamo op, non il tasto appena letto.
                switch (op) {
                    case '+': acc = acc + num; break;
                    case '-': acc = acc - num; break;
                    case '/': acc = acc / num; break;
                    case 'x':
                    case 'X':
                    case '*': acc = acc * num; break;
                }
            }
            disp = acc;

            if (c == '=') {
                // 5.8: conserviamo il risultato per continuare il conto.
                prima = true;
                num = acc;
            }
            else {
                fattore = 0.1;
                decimale = false;
                num = 0;
                op = c;
                prima = false;
            }
        }
        else if (c == 'C' || c == 'c') {
            // 5.4 e 5.5: cancelliamo anche un conto incompleto.
            num = 0;
            disp = 0;
            fattore = 0.1;
            decimale = false;
            acc = 0;
            prima = true;
        }
        else if (c == 'Q' || c == 'q') {
            break;
        }

        // 5.9: una stampa per tasto, anche se non riconosciuto, tranne Q/q.
        cout << "Display:\t" << disp << endl;
    }

    cout << "Bye!\n";
    return 0;
}

// 5.10: prove finali (input -> ultimo display).
// 407Q -> 407; 12.34Q -> 12.34; 2+3x4=Q -> 20;
// 2X3*4=Q -> 24; 2-5=Q -> -3; 12.5/2=+1=Q -> 7.25;
// 8+2c3=q -> 3; 8/0=Q -> 0 (errore); 8/0+2=Q -> 2;
// 2+3= seguito da fine input -> 5; Q -> nessuna stampa del display.
