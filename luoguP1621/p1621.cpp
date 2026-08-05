#include <iostream>
#include <numeric>
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
    while (i <= n) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
        i++;
    }

    return primes;
}

struct Unionfind {
    std::vector<int> pa;
    int merged;

    explicit Unionfind(int n) : pa(n + 1) {
        std::iota(pa.begin(), pa.end(), 0);
        merged = 0;
    }

    int find(int u) {
        return pa[u] == u ? u : pa[u] = find(pa[u]);
    }

    void merge (int u, int v) {
        u = find(u), v = find(v);
        if (u == v)
            return;
        pa[u] = v;
        merged++;
    }
};

int main() {
    int a, b, pMin;
    std::cin >> a >> b >> pMin;
    std::vector<int> primes = eratosthenes_sieve(b);
    Unionfind unionfind(b);
    for (auto p : primes) {
        if (p < pMin) {
            continue;
        }
        int u = a / p * p + (a % p ? p : 0); // u是最小的大于等于a的p的倍数
        for (int v = u + p; v <= b; v += p) {
            unionfind.merge(u, v);
        }
    }
    int ans = b - a + 1 - unionfind.merged;
    std::cout << ans;
    return 0;
}