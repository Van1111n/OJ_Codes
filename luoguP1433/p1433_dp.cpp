#include <cmath>
#include <iomanip>
#include <iostream>

inline double distance(double px, double py, double qx, double qy) {
    return sqrt((px - qx) * (px - qx) + (py - qy) * (py - qy));
}

int main() {
    int n;
    std::cin >> n;

    double* x = new double[n];
    double* y = new double[n];
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }

    double** dist = new double*[n];
    for (int i = 0; i < n; i++) {
        dist[i] = new double[n];
        for (int j = 0; j < n; j++) {
            dist[i][j] = distance(x[i], y[i], x[j], y[j]);
        }
    }

    // 令dp[mask][j]是在已经访问状态为mask时（含j）且最后停留在第j个点的时候，所经过的的最短路径.
    double** dp = new double*[1 << n];
    // double dp[1<<4][4];
    for (int i = 0; i < 1 << n; i++) {
        dp[i] = new double[n];
        for (int j = 0; j < n; j++) {
            dp[i][j] = 1e6;
        }
    }

    for (int j = 0; j < n; j++) {
        dp[1 << j][j] = distance(0, 0, x[j], y[j]);
    }

    for (int i = 0; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) {
            if (!((i >> j) & 1))
                continue;
            for (int k = 0; k < n; k++) {
                if (k == j || !((i >> k) & 1))
                    continue;
                dp[i][j] = std::min(dp[i][j], dp[i & (~(1 << j))][k] + dist[j][k]);
            }
        }
    }

    // debug
    // for (int i=0; i< 1<<n; i++) {for (int j=0; j<n; j++) {printf("%.2lf\t", dp[i][j]);}printf("\n");}

    double shortestDistance = 1e6;
    for (int j = 0; j < n; j++) {
        shortestDistance = std::min(shortestDistance, dp[(1 << n) - 1][j]);
    }
    std::cout << std::fixed << std::setprecision(2) << shortestDistance;
}