#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int N = 15;
    int item;
    if (!(cin >> item)) return 1;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        if (!(cin >> v[i])) return 1;
    }
    int loc = -1;
    bool found = false;
    for (int i = 0; i < N && !found; ++i) {
        if (v[i] == item) {
            loc = i;
            found = true;
        }
    }
    if (found) cout << item << " e' stato trovato in posizione " << loc << endl;
    else cout << item << " non e' stato trovato" << endl;
    return 0;
}
