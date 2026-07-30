#include <iostream>
#include <numeric>
#include <vector>

class JMFliter {
   public:
    std::vector<int> parent, size;
    int distinct;

    explicit JMFliter(int n) : parent(2 * n), size(2 * n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i + n;
        }
        for (int i = n; i < 2 * n; i++) {
            parent[i] = i;
        }
        distinct = n;
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x != y) {
            parent[x] = y;
            size[y] += size[x];
            --distinct;
        }
    }

    void remove(int x) {
        int anc = find(x);
        if (size[anc] != 1) {
            size[anc]--;
            int n = parent.size();
            parent[x] = n;
            parent.push_back(n);
            size.push_back(1);
            ++distinct;
        }
    }
};

int main() {
    int n, m, x, y;
    int caseNo = 1;
    char mode;
    while (1) {
        std::cin >> n >> m;
        if (n==0 && m==0) {
            break;
        }
        JMFliter jmfliter(n);
        for (int i=0; i<m; i++) {
            std::cin >> mode;
            if (mode == 'M') {
                std::cin >> x >> y;
                jmfliter.merge(x, y);
            } else if (mode == 'S') {
                std::cin >> x;
                jmfliter.remove(x);
            } else {
                abort();
            }
        }
        std::cout << "Case #" << caseNo << ": " << jmfliter.distinct << std::endl;
        ++caseNo;
    }
    return 0;
}