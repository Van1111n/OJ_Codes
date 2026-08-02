#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

struct Conflict {
    int u, v, w;

    bool operator<(const Conflict& other) {
        return w > other.w;
    }
};

struct DSU {
    std::vector<int> parent, weight;

    explicit DSU(int n) : parent(n + 1), weight(n + 1, 0) {
        for (int i = 0; i < n + 1; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] == u) {
            return u;
        } else {
            int uPa = parent[u];
            parent[u] = find(uPa);
            weight[u] += weight[uPa];
            weight[u] %= 2;
            return parent[u];
        }
    }

    bool merge(int u, int v) {
        find(u), find(v);
        int uPa = parent[u], vPa = parent[v];
        int uWt = weight[u], vWt = weight[v];
        if (uPa == vPa) {
            if ((uWt + vWt) % 2 == 1) {
                return true;
            } else {
                return false;
            }
        }
        int w = (1 + uWt + vWt) % 2;
        parent[uPa] = vPa;
        weight[uPa] = w;
        return true;
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<Conflict> conflicts(m);
    for (auto& it : conflicts) {
        std::cin >> it.u >> it.v >> it.w;
    }
    std::sort(conflicts.begin(), conflicts.end());

    DSU dsu(n);
    for (auto c : conflicts) {
        if (!dsu.merge(c.u, c.v)) {
            std::cout << c.w;
            return 0;
        };
    }
    std::cout << 0;
    return 0;
}
