#include <iostream>
#include <vector>
#include <numeric>

struct DSU
{
    std::vector<int> parent;
    int block;

    explicit DSU(int size) : parent(size) {
        iota(parent.begin(), parent.end(), 0);
        block = size;
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        } else {
            parent[x] = y;
            --block;
        }
    }
};


int main() {
    int n, m, x, y;
    while (1) {
        scanf("%d", &n);
        if (n==0) break;
        scanf("%d", &m);
        DSU dsu(n);
        for (int i=0; i<m; i++) {
            scanf("%d %d", &x, &y);
            --x, --y;
            dsu.unite(x, y);
        }
        std::cout << dsu.block - 1 << std::endl;
    }
}