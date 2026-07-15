#include <iostream>
#include <utility>

using LLU = unsigned long long;
using LLD = signed long long;

// solve ax + by = gcd(a, b)
std::pair<LLD, LLD> exgcd(LLD a, LLD b) {
    if (b == 0) {
        return {1, 0};
    } else {
        // solve bx + (a % b) y = gcd(b, a % b)
        std::pair<LLD, LLD> solve = exgcd(b, a % b);
        LLD x2 = solve.first, y2 = solve.second;
        LLD x1 = y2, y1 = x2 - a / b * y2;
        return {x1, y1};
    }
}

// returns a^(-1) mod m, assuming gcd(a, m) = 1
LLD modInv(LLD a, LLD m) {
    LLD x = exgcd(a, m).first;
    return (x % m + m) % m;
}

int main() {
    LLD a, b;
    scanf("%lld %lld", &a, &b);
    LLD x = modInv(a, b);
    printf("%lld\n", x);
    return 0;
}