#include <iostream>
#include <vector>

const int N = 10000000;

std::vector<int> primes;
bool is_prime[N];

void Eratosthenes(int n) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        is_prime[i] = true;
    }
    // i * i <= n 说明 i <= sqrt(n)
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Eratosthenes(N);

    int t;
    std::cin >> t;
    int x, y;
    while (t--) {
        int symDiff = 1;
        std::cin >> x >> y;
        for (int i = 0; primes[i] <= std::max(x, y); i++) {
            auto p = primes[i];
            if ((x % p == 0 && y % p != 0) || (x % p != 0 && y % p == 0)) {
                symDiff *= p;
            }
        }
        std::cout << symDiff << '\n';
    }
    return 0;
}