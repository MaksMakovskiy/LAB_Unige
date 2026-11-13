#include <iostream>
#include <vector>
using namespace std;

void stampaVector(const vector<int>& array) {
    for (size_t i = 0; i < array.size(); ++i) cout << array[i] << ' ';
    cout << endl;
}

void selectionSort(vector<int>& array) {
    for (size_t i = 0; i < array.size(); ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < array.size(); ++j)
            if (array[j] < array[minIndex]) minIndex = j;
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}

int ricercaSequenziale(const vector<int>& array, int item) {
    int count = 0;
    for (size_t i = 0; i < array.size(); ++i) {
        ++count;
        if (array[i] == item) {
            cout << "Accessi sequentialSearch: " << count << endl;
            return int(i);
        }
    }
    cout << "Accessi sequentialSearch: " << count << endl;
    return -1;
}

int main() {
    vector<int> array = {29, 5, 17, 1, 13, 25, 9, 3, 21, 7,
                         11, 19, 15, 23, 27, 0, 2, 4, 6, 8,
                         10, 12, 14, 16, 18, 20, 22, 24, 26, 28};
    selectionSort(array);
    stampaVector(array);
    int item;
    cout << "Elemento da cercare: ";
    if (!(cin >> item)) return 1;
    int pos = ricercaSequenziale(array, item);
    if (pos >= 0) cout << "Posizione: " << pos << endl;
    else cout << "Elemento assente" << endl;
    return 0;
}
