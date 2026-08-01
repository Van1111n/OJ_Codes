#include <iostream>
#include <numeric>
#include <vector>

const int mod = 998244353;
using llong = long long;

struct unionfindWithPtt {
    std::vector<int> parent;
    std::vector<llong> data;

    explicit unionfindWithPtt(int n) : parent(n), data(n, 0) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int u, llong& x) {
        if (parent[u] == u) {
            return u;
        } else {
            parent[u] = find(parent[u], x);
            x = (x + data[u]) % mod;
            data[u] = x;
            return parent[u];
        }
    }

    int find(int u) {
        llong x = 0;
        return find(u, x);
    }

    void merge(int u, int v, llong x) {
        find(u), find(v);
        if (parent[u] == parent[v]) {
            if ((data[u] - data[v] - x) % mod == 0) {
                std::cout << "1\n";
                return;
            } else {
                std::cout << "0\n";
                return;
            }
        } else {
            data[parent[u]] = (x - data[u] + data[v] + mod) % mod;
            parent[parent[u]] = parent[v];
            std::cout << "1\n";
            return;
        }
    }

    void getPtt(int u, int v) {
        find(u), find(v);
        if (parent[u] == parent[v]) {
            llong ans = (data[u] - data[v] + mod) % mod;
            std::cout << ans << '\n';
        } else {
            std::cout << "-1\n";
        }
    }
};

int main() {
    int n, q;
    std::cin >> n >> q;

    int t, u, v;
    llong x;
    unionfindWithPtt dsu(n);
    while (q--) {
        std::cin >> t;
        switch (t) {
            case 0:
                std::cin >> u >> v >> x;
                dsu.merge(u, v, x);
                break;
            case 1:
                std::cin >> u >> v;
                dsu.getPtt(u, v);
            default:
                break;
        }
    }
}
