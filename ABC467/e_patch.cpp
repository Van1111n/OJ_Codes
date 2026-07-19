#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        std::cin >> b[i];
    }

    std::vector<int> adjSum(n-1);
    for (int i=0; i<n-1; i++) {
        adjSum[i] = a[i] + a[i + 1];
    }

    std::vector<int> opr(n);
    opr[0]=0;
    for (int i=1; i<=n-1; i++) {
        opr[i] = ((b[i - 1] - adjSum[i - 1] - opr[i - 1]) % m + m) % m;
    }

    // TODO: find possible s, sort'em, then use diffenrence update to calc min oprCount.

    return 0;
}