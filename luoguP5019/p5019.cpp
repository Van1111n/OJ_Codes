#include <iostream>

void prt(int* a, int len) {
    for (int i=0; i<len; i++) {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    // 1-based
    int* d = new int[n + 1]{0};
    for (int i = 1; i <= n; i++) {
        std::cin >> d[i];
    }

    int* dp = new int[n + 1]{0};
    dp[1] = d[1];
    for (int i = 2; i<= n; i++) {
        dp[i] = dp[i - 1] + std::max(d[i] - d[i - 1], 0);
    }
    std::cout << dp[n];
}