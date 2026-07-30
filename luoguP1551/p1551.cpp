#include <iostream>
#include <numeric>
#include <vector>

class DSU {
   private:
    std::vector<int> parent;
    std::vector<int> size;

   public:
    explicit DSU(int size_) : parent(size_), size(size_, 0) {
        int value = 0;
        std::iota(parent.begin(), parent.end(), value);
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (size[x] > size[y]) {
            std::swap(x, y);
        }
        parent[x] = y;
        size[y] += size[x];
    }
};

int main() {
    int n, m, p;
    std::cin >> n >> m >> p;
    DSU dsu(n+1);
    int x, y;
    for (int i=0; i<m; i++) {
        std::cin >> x >> y;
        dsu.unite(x, y);
    }
    for (int i=0; i<p; i++) {
        std::cin >> x >> y;
        if (dsu.find(x)==dsu.find(y)) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}