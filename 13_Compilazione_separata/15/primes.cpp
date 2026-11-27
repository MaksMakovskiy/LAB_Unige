#include "primes.h"
using namespace std;

// Crivello di Eratostene
vector<int> primes(int n) {
    vector<int> result;
    if (n < 2) return result;
    vector<bool> isprime(n + 1, true);
    isprime[0] = false;
    isprime[1] = false;
    for (int p = 2; p * p <= n; ++p) {
        if (isprime[p]) {
            for (int multiple = p * p; multiple <= n; multiple += p)
                isprime[multiple] = false;
        }
    }
    for (int i = 2; i <= n; ++i)
        if (isprime[i]) result.push_back(i);
    return result;
}
