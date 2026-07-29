#include <iostream>

const int MAXN = 1005;

inline int det(int a, int b, int c, int d) {
    return a * d - b * c;
}

void prtMatrix(int matrix[MAXN][MAXN], int n, int m) {
    std::cout << n << ' ' << m << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    int a[MAXN][MAXN] = {0}, b[MAXN][MAXN] = {0}, c[MAXN][MAXN] = {0}, d[MAXN][MAXN] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            b[i][j] = det(a[i][j], a[i][j + 1], a[i + 1][j], a[i + 1][j + 1]);
        }
    }
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            c[i][j] = det(b[i][j], b[i][j + 1], b[i + 1][j], b[i + 1][j + 1]);
        }
    }
    for (int i = 0; i < n - 3; i++) {
        for (int j = 0; j < m - 3; j++) {
            d[i][j] = det(c[i][j], c[i][j + 1], c[i + 1][j], c[i + 1][j + 1]);
        }
    }
    char matrixName;
    std::cin >> matrixName;
    if (matrixName == 'A') {
        prtMatrix(a, n, m);
    } else if (matrixName == 'B') {
        prtMatrix(b, n - 1, m - 1);
    } else if (matrixName == 'C') {
        prtMatrix(c, n - 2, m - 2);
    } else {
        prtMatrix(d, n - 3, m - 3);
    }
    return 0;
}