#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> segmentedSieve(int L, int R) {
    int limit = sqrt(R) + 1;
    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;

    // Step 1: Find all primes up to sqrt(R)
    for (int i = 2; i <= limit; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Step 2: Mark multiples in range [L, R]
    vector<bool> rangeIsPrime(R - L + 1, true);
    for (int prime : primes) {
        int start = max(prime * prime, (L + prime - 1) / prime * prime);
        for (int j = start; j <= R; j += prime) {
            rangeIsPrime[j - L] = false;
        }
    }

    // Collect primes in the range
    vector<int> result;
    for (int i = 0; i <= R - L; ++i) {
        if (rangeIsPrime[i] && (i + L) > 1) {
            result.push_back(i + L);
        }
    }
    return result;
}

int main() {
    int L = 10, R = 50;
    vector<int> primes = segmentedSieve(L, R);
    for (int prime : primes) {
        cout << prime << " ";
    }
    return 0;
}
