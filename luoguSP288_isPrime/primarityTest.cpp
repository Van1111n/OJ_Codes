#include <iostream>
#define LLU unsigned long long
#define LLD long long int
#define LLF long double

using namespace std;

//FIXME:

LLU fast_mul(LLU a, LLU b, LLU p) {
    LLU c = (LLU)a * b - (LLU)((LLF)a / p * b + 0.5L) * p;
    return c < p ? c : c + p;
}

LLU fast_pow(LLU a, LLU n, LLU p) {
    LLU b = 1;
    while (n != 0) {
        if (n % 2 == 1)
            b = fast_mul(b, a, p);
        n = n / 2;
        a = fast_mul(a, a, p);
    }
    return b;
}

const int base[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
// these bases ensures n<2^64 that pass the test is certainly a prime
bool miller_rabin_primarity_test(LLU n) {
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    // form n-1 to u*2^t
    LLU t = 0;
    LLU u = n - 1;
    while (u % 2 == 0) {
        u /= 2;
        t++;
    }
    // select a base a, need to mod n
    for (int i = 0; i < 12; i++) {
        LLU a = base[i] % n;
        if (a % n == 0 || a % n == 1 || a % n == n - 1)
            continue;
        // let v=a^u(mod n)，square n times，check the result mod n. +/-1 means prime.
        LLU v = fast_pow(a, u, n);
        for (int j = 0; j < t; j++) {
            v = fast_pow(v, 2, n);
            if (v != 1 && v != n - 1) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int t;
    LLU n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%llu", &n);
        miller_rabin_primarity_test(n) ? printf("YES\n") : printf("NO\n");
    }
    return 0;
}