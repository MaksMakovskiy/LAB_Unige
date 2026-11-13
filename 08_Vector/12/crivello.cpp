#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int N = 1000;
    vector<bool> isprime(N, true);
    isprime[0] = false;
    isprime[1] = false;
    for (int p = 2; p < N; ++p) {
        if (isprime[p]) {
            for (int multiple = 2 * p; multiple < N; multiple += p) {
                isprime[multiple] = false;
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        if (isprime[i]) cout << i << endl;
    }
    return 0;
}
