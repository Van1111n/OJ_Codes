#include <iostream>

using LLU = unsigned long long;
using LLD = signed long long;

const int mod = 1000000007;

std::pair<LLD, LLD> exgcd(LLD a, LLD b){
    if (b == 0) {
        return {1, 0};
    } else {
        auto solve = exgcd(b, a % b);
        LLD x2 = solve.first, y2 = solve.second;

        LLD x1 = y2;
        LLD y1 = x2 - a / b * y2;
        return {x1, y1};
    }
}

LLD modInv(LLD a, LLD m) {
    LLD x = exgcd(a, m).first;
    return (x % m + m) % m;
}

LLD catalan(LLD n) {
    if (n == 0)
        return 1;
    else
        return (4 * n - 2) * catalan(n - 1) % mod * modInv(n + 1, mod) % mod;
}

int main(){
    LLD n;
    std::cin >> n;
    std::cout << catalan(n) << std::endl;
}