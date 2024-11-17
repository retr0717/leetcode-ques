#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countPrimes(int n) {
    if (n <= 2)
      return 0; // No primes less than 2

    vector<int> prime(n, 1); // Use vector for easier handling of sizes
    prime[0] = prime[1] = 0; // 0 and 1 are not primes

    // Sieve of Eratosthenes
    for (int i = 2; i * i < n; ++i) {
      if (prime[i]) {
        for (int j = i * i; j < n; j += i) {
          prime[j] = 0;
        }
      }
    }

    // Count primes
    int count = 0;
    for (int i = 2; i < n; ++i) {
      if (prime[i]) {
        count++;
      }
    }

    return count;
  }
};
