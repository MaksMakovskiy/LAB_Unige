#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> a = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < a[i].size(); ++j) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
