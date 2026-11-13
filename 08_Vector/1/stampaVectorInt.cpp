#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {2, 4, 34, 78, 4, 3, 876};
    for (size_t i = 0; i < a.size(); ++i) {
        cout << "Valore di a[" << i << "] = " << a[i] << endl;
    }
    return 0;
}
