#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

struct DSU
{
    std::vector<int> parent, size;
    bool connected;

    explicit DSU(int n) : parent(n + 1), size(n + 1, 1) {
        std::iota(parent.begin(), parent.end(), 0);
        connected = false;
    }

    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return;
        if (size[x] > size[y])
            std::swap(x, y);
        parent[x] = y;
        size[y] += size[x];
        if (size[y] == parent.size()-1) connected = true;
    }
};

struct Opr
{
    int x;
    int y;
    int t;

    bool operator < (const Opr& other) {
        return t < other.t;
    }
};


int main() {
    int n, m, x, y, t;
    std::cin >> n >> m;

    std::vector<Opr> oprs(m);
    DSU dsu(n);
    for (int i=0; i<m; i++) {
        std::cin >> oprs[i].x >> oprs[i].y >> oprs[i].t;
    }
    std::sort(oprs.begin(), oprs.end());
    for (auto it : oprs) {
        dsu.merge(it.x, it.y);
        if (dsu.connected) {
            std::cout << it.t << std::endl;
            return 0;
        }
    }
    std::cout << "-1" << std::endl;
    return 0;
}
