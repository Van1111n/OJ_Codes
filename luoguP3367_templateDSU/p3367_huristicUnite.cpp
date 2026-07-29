#include <iostream>
#include <numeric>
#include <vector>

struct DSU {
    std::vector<int> parent;  // parent[i] is the parent of node no.i
    std::vector<int> size;

    explicit DSU(int size_) : parent(size_), size(size_, 1) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        } else {
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (size[x] < size[y]) {
            parent[x] = y;
            size[x] += size[y];
        } else {
            parent[y] = x;
            size[y] += size[x];
        }
        return;
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;
    int mode, x, y;
    DSU dsu(n+1);
    for (int i=0; i<m; i++) {
        std::cin >> mode >> x >> y;
        if (mode == 1) {
            dsu.unite(x, y);
        } else {
            std::cout << (dsu.find(x) == dsu.find(y) ? 'Y' : 'N') << std::endl;
        }
    }
    return 0;
}
