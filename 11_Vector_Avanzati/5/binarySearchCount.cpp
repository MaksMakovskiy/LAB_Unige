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

int ricercaBinaria(const vector<int>& array, int item) {
    int left = 0;
    int right = int(array.size()) - 1;
    int count = 0;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        ++count;
        int current = array[middle];
        if (current == item) {
            cout << "Accessi binarySearch: " << count << endl;
            return middle;
        }
        if (current < item) left = middle + 1;
        else right = middle - 1;
    }
    cout << "Accessi binarySearch: " << count << endl;
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
    int pos = ricercaBinaria(array, item);
    if (pos >= 0) cout << "Posizione: " << pos << endl;
    else cout << "Elemento assente" << endl;
    return 0;
}
