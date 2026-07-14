#include <iostream>
#include <vector>

using LLU = unsigned long long;

struct Node {
    int begin;
    int end;
    LLU intervalSum;
    LLU lazyTagAdd;
    LLU lazyTagMul;
    // 在加或者乘操作后，更新区间和和标记
    // 约定标记为先乘后加
};

class SegTree {
   public:
    std::vector<Node> nodes;
    int length;
    int mod;

    inline void memAlloc(int n) {
        nodes.resize(4 * n + 6);
    }

    void build(LLU* arr, int begin, int end, int crt) {
        nodes[crt].begin = begin;
        nodes[crt].end = end;
        nodes[crt].lazyTagAdd = 0;
        nodes[crt].lazyTagMul = 1;
        if (end - begin == 1) {
            nodes[crt].intervalSum = arr[begin];
        } else {
            build(arr, begin, (end + begin) / 2, 2 * crt + 1);
            build(arr, (begin + end) / 2, end, 2 * crt + 2);
            nodes[crt].intervalSum = (nodes[2 * crt + 1].intervalSum + nodes[2 * crt + 2].intervalSum) % mod;
        }
        return;
    }

    SegTree() {}

    SegTree(LLU* arr, int len, int mod) {
        memAlloc(len);
        this->length = len;
        this->mod = mod;
        build(arr, 0, len, 0);
    }

    void pushdown(int i) {
        Node& crt = nodes[i];
        if (crt.end - crt.begin == 1) {
            crt.lazyTagAdd = 0;
            crt.lazyTagMul = 1;
            return;
        }
        Node &lChild = nodes[2*i+1], &rChild = nodes[2*i+2];
        LLU add = crt.lazyTagAdd, mul = crt.lazyTagMul;

        lChild.intervalSum = (lChild.intervalSum * mul + (lChild.end - lChild.begin) * add) % mod;
        lChild.lazyTagMul = lChild.lazyTagMul * mul % mod;
        lChild.lazyTagAdd = (lChild.lazyTagAdd * mul + add) % mod;

        rChild.intervalSum = (rChild.intervalSum * mul + (rChild.end - rChild.begin) * add) % mod;
        rChild.lazyTagMul = rChild.lazyTagMul * mul % mod;
        rChild.lazyTagAdd = (rChild.lazyTagAdd * mul + add) % mod;

        crt.lazyTagAdd = 0;
        crt.lazyTagMul = 1;
    }

    void intervalSum(int begin, int end, int crt, LLU& sum) {
        if (begin == nodes[crt].begin && end == nodes[crt].end) {
            sum += nodes[crt].intervalSum;
            sum %= mod;
            return;
        }
        int mid = (nodes[crt].begin + nodes[crt].end) / 2;
        pushdown(crt);
        if (begin < mid) {
            intervalSum(begin, std::min(mid, end), 2 * crt + 1, sum);
            sum %= mod;
        }
        if (mid < end) {
            intervalSum(std::max(begin, mid), end, 2 * crt + 2, sum);
            sum %= mod;
        }
    }

    LLU sum(int begin, int end) {
        LLU res = 0;
        intervalSum(begin, end, 0, res);
        return res % mod;
    }

    void intervalAdd(int begin, int end, int crt, LLU add) {
        if (begin == nodes[crt].begin && end == nodes[crt].end) {
            if (nodes[crt].end - nodes[crt].begin == 1) {
                nodes[crt].intervalSum += add;
                nodes[crt].intervalSum %= mod;
            } else {
                nodes[crt].lazyTagAdd += add;
                nodes[crt].lazyTagAdd %= mod;
                nodes[crt].intervalSum += (nodes[crt].end - nodes[crt].begin) * add;
                nodes[crt].intervalSum %= mod;
            }
            return;
        }
        pushdown(crt);
        auto mid = (nodes[crt].begin + nodes[crt].end) / 2;
        if (begin < mid) {
            intervalAdd(begin, std::min(end, mid), 2 * crt + 1, add);
        }
        if (mid < end) {
            intervalAdd(std::max(mid, begin), end, 2 * crt + 2, add);
        }
        nodes[crt].intervalSum = (nodes[2 * crt + 1].intervalSum + nodes[2 * crt + 2].intervalSum) % mod;
    }

    void add(int begin, int end, LLU add) {
        intervalAdd(begin, end, 0, add);
    }

    void intervalMul(int begin, int end, int crt, LLU mul) {
        if (begin == nodes[crt].begin && end == nodes[crt].end) {
            if (nodes[crt].end - nodes[crt].begin == 1) {
                nodes[crt].intervalSum *= mul;
                nodes[crt].intervalSum %= mod;
            } else {
                nodes[crt].lazyTagMul *= mul;
                nodes[crt].lazyTagMul %= mod;
                nodes[crt].lazyTagAdd *= mul;
                nodes[crt].lazyTagAdd %= mod;
                nodes[crt].intervalSum *= mul;
                nodes[crt].intervalSum %= mod;
            }
            return;
        }
        pushdown(crt);
        int mid = (nodes[crt].begin + nodes[crt].end) / 2;
        if (begin < mid) {
            intervalMul(begin, std::min(mid, end), 2 * crt + 1, mul);
        }
        if (mid < end) {
            intervalMul(std::max(mid, begin), end, 2 * crt + 2, mul);
        }
        nodes[crt].intervalSum = (nodes[2 * crt + 1].intervalSum + nodes[2 * crt + 2].intervalSum) % mod;
    }

    void mul(int begin, int end, LLU mul) {
        intervalMul(begin, end, 0, mul);
    }
};

signed main() {
    int arrLen, oprLen, mod;
    scanf("%d %d %d", &arrLen, &oprLen, &mod);

    LLU* arr = new LLU[arrLen];
    for (int i = 0; i < arrLen; i++) {
        scanf("%llu", &arr[i]);
    }

    SegTree tree(arr, arrLen, mod);

    for (int i = 0; i < oprLen; i++) {
        int mode, x, y, k;
        scanf("%d", &mode);
        if (mode == 1) {
            scanf("%d %d %d", &x, &y, &k);
            --x;
            tree.mul(x, y, k);
        } else if (mode == 2) {
            scanf("%d %d %d", &x, &y, &k);
            --x;
            tree.add(x, y, k);
        } else if (mode == 3) {
            scanf("%d %d", &x, &y);
            --x;
            printf("%llu\n", tree.sum(x, y) % mod);
        }
    }

    return 0;
}