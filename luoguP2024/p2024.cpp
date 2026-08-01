#include <iostream>
#include <numeric>
#include <vector>

const int mod = 3;
using llong = long long;

struct FoodChain {
    std::vector<int> parent, data;
    int fakeNews;

    explicit FoodChain(int n) : parent(n + 1), data(n + 1, 0) {
        std::iota(parent.begin(), parent.end(), 0);
        fakeNews = 0;
    }

    int find(int u, int& x) {
        if (parent[u] == u) {
            return u;
        } else {
            parent[u] = find(parent[u], x);
            x = (x + data[u] + mod) % mod;
            data[u] = x;
            return parent[u];
        }
    }

    int zip(int u) {
        int x = 0;
        return find(u, x);
    }

    void merge(int u, int v, int x) {
        if (u >= parent.size() || v >= parent.size()) {
            ++fakeNews;
            return;
        }
        zip(u), zip(v);
        if (parent[u] == parent[v]) {
            if ((data[u] - data[v] - x) % mod == 0) {
                return;
            } else {
                ++fakeNews;
                return;
            }
        } else {
            data[parent[u]] = (x - data[u] + data[v] + mod) % mod;
            parent[parent[u]] = parent[v];
            return;
        }
    }
};

int main() {
    int n, k;
    std::cin >> n >> k;

    int type;
    llong x, y;
    FoodChain dsu(n);
    while (k--) {
        std::cin >> type >> x >> y;
        switch (type) {
            case 1:
                dsu.merge(x, y, 0);
                break;
            case 2:
                dsu.merge(x, y, 1);
                break;
            default:
                break;
        }
    }
    std::cout << dsu.fakeNews << std::endl;
}