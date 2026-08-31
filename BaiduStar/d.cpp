#include <iostream>
#include <vector>

using llong = long long;

inline llong matrixSum(std::vector<std::vector<llong>>& prefixSum, int x0, int x1, int y0, int y1) {
    return prefixSum[x1][y1] - prefixSum[x1][y0 - 1] - prefixSum[x0 - 1][y1] + prefixSum[x0 - 1][y0 - 1];
}

llong minPerfMatch(std::vector<std::vector<llong>> )

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<llong>> matrixA(n + 1, std::vector<llong>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            std::cin >> matrixA[i][j];
        }
    }
    std::vector<std::vector<llong>> prefixSum(n + 1, std::vector<llong>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + matrixA[i][j];
        }
    }

    std::vector<std::vector<llong>> adjMatrix(n + 1, std::vector<llong>(n + 1));
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            llong s1 = matrixSum(prefixSum, 1, i, i, j - 1), s2 = matrixSum(prefixSum, i + 1, j, j, n);
            adjMatrix[i][j] = s1 + s2;
        }
    }

    // TODO:

    return 0;
}