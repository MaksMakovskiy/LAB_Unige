#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Numero di elementi: ";
    if (!(cin >> n) || n < 0) return 1;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        if (!(cin >> a[i])) return 1;
    }
    bool palindrome = true;
    for (int i = 0; i < n / 2; ++i) {
        if (a[i] != a[n - 1 - i]) palindrome = false;
    }
    if (palindrome) cout << "Il vector e' palindromo" << endl;
    else cout << "Il vector non e' palindromo" << endl;
    return 0;
}
