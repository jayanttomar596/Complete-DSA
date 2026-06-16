/*
1. Segmented Sieve
The segmented sieve is an efficient way to find all prime numbers in a given range [L, R] using the classic Sieve of Eratosthenes.

Key Idea:
Instead of finding primes up to 
R, we first find primes up to 
sqrt R using the normal sieve.
Then, we use these primes to mark multiples in the range [L, R].

Steps:Find base primes up to sqrt R
​using the Sieve of Eratosthenes.
Mark multiples of each base prime in the range [L, R]:

For each base prime p, find the smallest multiple in [L, R] (let's call it low_limit
low_limit) and mark all multiples 
low_limit,low_limit+𝑝,low_limit+2𝑝,

…
low_limit,low_limit+p,low_limit+2p,… as non-prime.
The numbers that remain unmarked in [L, R] are prime.
Why It’s Useful:
Works for large ranges
 memory-intensive.
*/


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
