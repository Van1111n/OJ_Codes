#include <iostream>

const int mod = 10000;

int main() {
    int n;
    std::cin >> n;
    if (n == 1) {
        std::cout << 1; //特判n==1
    } else {
        // 说明：以 i、j 分别为上下两行的格数，递推发现方案数 a[i][j] 满足：
        // 若 i==j, a[i][j] = a[i-i][j-1]+a[i-2][j-2]+a[i-2][j-1]+a[i-1][j-2]
        // 若 i-j == 1, a[i][j] = a[i-2][j] + a[i-2][j-1]
        int a = 1, b = 1, c = 2;
        int a0, b0;
        for (int i = 0; i < n - 2; i++) {
            // (a, b, c) = (c, a+b, a+2b+c)
            a0 = a;
            a = c;
            b0 = b;
            b = (a0 + b) % mod;
            c = (a0 + 2 * b0 + c) % mod;
        }
        std::cout << c;
    }
}