#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<float> a = {2.4f, 5.67f, 34.0f, 28.456f, 846.42f};
    for (int i = int(a.size()) - 1; i >= 0; --i) {
        cout << "Valore di a[" << i << "] = " << a[i] << endl;
    }
    return 0;
}
