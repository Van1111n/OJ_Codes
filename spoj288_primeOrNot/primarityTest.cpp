#include <iostream>
#define LLU unsigned long long
#define LLD long long int
#define LLF long double

using namespace std;

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
    if (n < 3 || n % 2 == 0)
        return n == 2;
    if (n % 3 == 0)
        return n == 3;
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
        if (a % n == 0 || a % n == 1 || a % n == n - 1) continue;
        LLU v = fast_pow(a, u, n);
        if (v == 1) continue;
        int s;
        for (s = 0; s < t; ++s) {
            if (v == n - 1) break;
            v = fast_mul(v, v, n);
        }
        if (s == t)
            return false;
    }
    return true;
}

bool division_primarity_test(LLU n){
    for (LLU i=2; i*i<=n; i++){
        if (n%i==0) return false;
    }
    return true;
}

int main() {
    for (LLU i=2; i<__LONG_LONG_MAX__; i++){
        if (division_primarity_test(i)!=miller_rabin_primarity_test(i)) {
            printf("for %d: div:%d, mr:%d\n", i, division_primarity_test(i), miller_rabin_primarity_test(i));
            getchar();
        }
    }
    return 0;
}