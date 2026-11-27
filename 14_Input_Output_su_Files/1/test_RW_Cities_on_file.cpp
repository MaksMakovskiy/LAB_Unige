#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct city {
    string name;
    int inhabitants;
};

typedef vector<city> cities;

void write_cities_to_file(const cities &C, string fileName) {
    ofstream outfile;
    outfile.open(fileName);
    if (!outfile) {
        cout << "Impossibile aprire il file " << fileName << endl;
        return;
    }
    outfile << C.size() << endl;
    for (size_t i = 0; i < C.size(); ++i)
        outfile << C[i].name << " " << C[i].inhabitants << endl;
    outfile.close();
}

void read_cities_from_file(cities &C, string fileName) {
    ifstream infile;
    infile.open(fileName);
    if (!infile) {
        cout << "Impossibile aprire il file " << fileName << endl;
        return;
    }
    string data;
    infile >> data;
    int N = stoi(data);
    for (int i = 0; i < N; ++i) {
        city c;
        infile >> c.name >> data;
        c.inhabitants = stoi(data);
        C.push_back(c);
    }
    infile.close();
}

int main() {
    cities C;
    read_cities_from_file(C, "citiesToRead.txt");
    write_cities_to_file(C, "citiesToWrite.txt");
    cout << "Copiate " << C.size() << " città in citiesToWrite.txt" << endl;
    return 0;
}
