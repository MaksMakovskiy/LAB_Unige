#include <iostream>
#include <vector>
#include "insert.h"
using namespace std;

void print(const vector<int> &v) {
    for (size_t i = 0; i < v.size(); ++i) cout << v[i] << " ";
    cout << endl;
}

int main() {
    vector<int> v;

    cout << "(a) inserimento in v vuoto: ";
    insert(v, 0, 10);
    print(v);                       // 10

    cout << "(b) inserimento in testa: ";
    insert(v, 0, 5);
    print(v);                       // 5 10

    cout << "(c) inserimento in coda: ";
    insert(v, v.size(), 20);
    print(v);                       // 5 10 20

    cout << "(d) inserimento in posizione generica (1): ";
    insert(v, 1, 7);
    print(v);                       // 5 7 10 20

    cout << "(e) inserimento in posizione non valida (10): ";
    try {
        insert(v, 10, 99);
        print(v);
    } catch (int pos) {
        cout << "eccezione: posizione " << pos << " non valida" << endl;
    }
    print(v);                       // invariato
    return 0;
}
