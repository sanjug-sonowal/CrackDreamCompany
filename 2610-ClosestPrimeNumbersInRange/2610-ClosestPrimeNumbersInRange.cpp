// Last updated: 18/10/2025, 08:59:51
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        // Step 1: Find all prime numbers up to right using the Sieve of Eratosthenes
        int N = right + 1;
        vector<bool> isPrime(N, true);
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

        for (int i = 2; i * i < N; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < N; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Step 2: Collect primes in the given range
        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        // Step 3: Find the closest pair of primes
        if (primes.size() < 2) return {-1, -1};

        int minDiff = INT_MAX;
        vector<int> result(2, -1);

        for (int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                result = {primes[i - 1], primes[i]};
            }
        }

        return result;
    }
};
