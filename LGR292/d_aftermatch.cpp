#include <iostream>
#include <vector>

using llong = long long;

const llong inf = 1000000000000;

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<Edge> edges(m);
    for (auto& it : edges) {
        std::cin >> it.u >> it.v >> it.w;
        --it.u, --it.v; // to 0-base
    }

    int maxE = n / 2 - 1;
    std::vector<std::vector<llong>> dp(maxE+1, std::vector<llong>(n, inf));
    dp[0][0] = 0;
    for (int i=1; i<=maxE; i++) {
        for (auto e : edges) {
            dp[i][e.v] = std::min(dp[i][e.v], dp[i - 1][e.u] + e.w);
        }
    }
    llong ans = inf;
    for (int i=0; i<=maxE; i++) {
        ans = std::min(dp[i][n-1], ans);
    }
    std::cout << (ans == inf ? -1 : ans);
}