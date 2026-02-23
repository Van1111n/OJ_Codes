#include <iostream>

int main() {
    long long n, m, squareNum = 0, rectangleNum = 0;
    scanf("%lld %lld", &n, &m);
    for (size_t i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            rectangleNum += i * j;
        }
    }
    for (size_t i = 1; i <= ((m < n) ? m : n); i++) {
        squareNum += (m + 1 - i) * (n + 1 - i);
    }
    printf("%lld %lld\n", squareNum, rectangleNum - squareNum);
}