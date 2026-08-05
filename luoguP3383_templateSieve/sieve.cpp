#include <iostream>
#include <vector>

std::vector<int> eratosthenes_sieve(int n) {
    std::vector<int> primes;
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    int i = 2;
    while (i * i <= n) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
        i++;
    }
    while (i < n) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
        i++;
    }

    return primes;
}

std::vector<int> euler_sieve(int n) {
    std::vector<int> primes;
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    int i = 2;
    while (i <= n) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p > n)
                break;
            isPrime[i * p] = false;
        }
        i++;
    }

    return primes;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::vector<int> primes = euler_sieve(n);
    int k;
    while (q--) {
        std::cin >> k;
        std::cout << primes[k - 1] << '\n';
    }
    return 0;
}