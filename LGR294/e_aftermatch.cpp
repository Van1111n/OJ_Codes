#include <iostream>
#include <vector>

using llong = long long;

const int maxN = 10000000;

llong gcd(llong a, llong b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

std::vector<llong> sieve(int n) {
    std::vector<llong> vec(n + 1, 1);
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i; j <= n; j += i) {
                vec[j] *= i;
                isPrime[j] = false;
            }
        }
    }
    return vec;
} // 朴素筛法TLE

std::vector<llong> euler_sieve(int n) {
    std::vector<llong> radical(n + 1, 1);
    std::vector<int> primes;
    primes.reserve(maxN / 4);
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            radical[i] = i;
        }
        for (int p : primes) {
            if (i * p > n) {
                break;
            }
            isPrime[i * p] = false;
            if (i % p == 0) {
                radical[i * p] = radical[i];
                break;
            } else {
                radical[i * p] = radical[p] * radical[i];
            }
        }
    }
    return radical;
} // 整数x的所有互不相同的质因子的乘积R(x)满足积性，可用线性筛法求

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t, x, y;
    std::cin >> t;
    std::vector<llong> pfp = euler_sieve(maxN);
    while (t--) {
        std::cin >> x >> y;
        int g = gcd(x, y);
        llong ans = pfp[x] * pfp[y] / pfp[g] / pfp[g];
        std::cout << ans << '\n';
    }
    return 0;
}
