#include <iostream>
#include <string>
#include <stdexcept>
#include "iovector.h"
using namespace std;

void readVector(vector<int> &v) {
    cout << "Inserisci la dimensione della sequenza: ";
    int N;
    cin >> N;
    while (N <= 0) {
        cout << "La dimensione deve essere positiva - riprova: ";
        cin >> N;
    }
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }
}

void readVectorAlt(vector<int> &v) {
    cout << "Inserisci i valori (y per terminare): " << endl;
    string s;
    while (cin >> s && s != "y") {
        try {
            v.push_back(stoi(s));
        } catch (const invalid_argument &) {
            cout << "\"" << s << "\" non è un intero - ignorato" << endl;
        } catch (const out_of_range &) {
            cout << "\"" << s << "\" è fuori dai limiti di int - ignorato" << endl;
        }
    }
}

void printVector(const vector<int> &v) {
    for (size_t i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
}
