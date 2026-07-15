#include <iostream>

using LLU = unsigned long long;
using LLD = signed long long;

const int mod = 1000000007;


LLD fast_pow(LLD a, LLD b, LLD p){
    LLD res = 1;
    while (b) {
        if (b % 2) {
            res = res * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

LLD modInv_p(LLD a, LLD p) {
    return fast_pow(a, p-2, p);
}

LLD catalan(LLD n) {
    if (n == 0)
        return 1;
    else
        return (4 * n - 2) * catalan(n - 1) % mod * modInv_p(n + 1, mod) % mod;
}

int main(){
    LLD n;
    std::cin >> n;
    std::cout << catalan(n) << std::endl;
}