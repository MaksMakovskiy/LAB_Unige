#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Date {
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

struct Student {
    int matricola;
    string name;
    string surname;
    Date birth;
    double average;
};

// true se a e' nato prima di b (quindi e' piu' vecchio)
bool olderThan(const Date &a, const Date &b) {
    if (a.year != b.year) return a.year < b.year;
    if (a.month != b.month) return a.month < b.month;
    return a.day < b.day;
}

int main() {
    int N;
    cout << "Quanti studenti (almeno 3)? ";
    cin >> N;
    while (N <= 2) {
        cout << "Servono almeno 3 studenti - riprova: ";
        cin >> N;
    }

    vector<Student> s(N);
    for (int i = 0; i < N; ++i) {
        cout << "Studente " << i + 1 << endl;
        cout << "  Matricola: ";
        cin >> s[i].matricola;
        cout << "  Nome: ";
        cin >> s[i].name;
        cout << "  Cognome: ";
        cin >> s[i].surname;
        cout << "  Data di nascita (giorno mese anno): ";
        cin >> s[i].birth.day >> s[i].birth.month >> s[i].birth.year;
        cout << "  Voto medio: ";
        cin >> s[i].average;
    }

    // selection sort: in ordine decrescente di eta' (dal piu' vecchio)
    for (int i = 0; i < N - 1; ++i) {
        int index = i;
        for (int j = i + 1; j < N; ++j)
            if (olderThan(s[j].birth, s[index].birth)) index = j;
        Student tmp = s[i];
        s[i] = s[index];
        s[index] = tmp;
    }

    cout << "Studenti in ordine decrescente di età:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << s[i].matricola << " " << s[i].name << " " << s[i].surname << " "
             << s[i].birth.day << "/" << s[i].birth.month << "/" << s[i].birth.year
             << " media " << s[i].average << endl;
    }
    return 0;
}
