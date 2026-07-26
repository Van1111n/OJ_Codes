#include <iostream>

const int MAXN = 100000;
const int mod = 1000000007;

int main() {
    int t, n, q, l, r;
    int a[MAXN+5], prefixXor[MAXN+5]={0};
    std::cin >> t;
    while (t--) {
        std::cin >> n >> q;
        for (int i=1; i<=n; i++) {
            std::cin >> a[i];
            prefixXor[i]=prefixXor[i-1]^a[i];
        }
        while (q--) {
            std::cin >> l >> r;
            int xorSum = 0;
            for (int i=l; i<=r; i++) {
                for (int j=i; j<=r; j++) {
                    xorSum = (xorSum + (prefixXor[j]^prefixXor[i-1])) % mod;
                }
            }
            std::cout << xorSum << std::endl;
        }
    }

    return 0;
}