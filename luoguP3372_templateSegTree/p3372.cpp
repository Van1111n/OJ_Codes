#include <iostream>
#include <cstdio>
#include <algorithm>
#define LLU unsigned long long

struct SegTreeNode {
    LLU data;
    int begin;
    int end;
    LLU lazyTag;

    int segLen() {
        return end - begin;
    }
};

// 0-based
void buildSegTreeNode(LLU* array, int arrbegin, int arrEnd, SegTreeNode* tree, int crtNode) {
    if (arrEnd - arrbegin == 1) {
        tree[crtNode].data = array[arrbegin];
        tree[crtNode].begin = arrbegin;
        tree[crtNode].end = arrEnd;
        return;
    }
    tree[crtNode].begin = arrbegin;
    tree[crtNode].end = arrEnd;
    buildSegTreeNode(array, arrbegin, (arrbegin + arrEnd) / 2, tree, 2 * crtNode + 1);
    buildSegTreeNode(array, (arrbegin + arrEnd) / 2, arrEnd, tree, 2 * crtNode + 2);
    tree[crtNode].data = tree[2 * crtNode + 1].data + tree[2 * crtNode + 2].data;
    return;
}

void prtSegTree(SegTreeNode* tree, int length) {
    for (int i = 0; i < length; i++) {
        printf("[%llu,%llu) sum:%llu tag:%llu\n", tree[i].begin, tree[i].end, tree[i].data, tree[i].lazyTag);
    }
}

void askIntervalSum(int askBegin, int askEnd, SegTreeNode* tree, int crtNode, LLU* sum) {
    // prtSegTree(tree, 4 * 5 + 3);
    // printf("%llu", *sum);
    // putchar('\n');
    if (askBegin == tree[crtNode].begin && askEnd == tree[crtNode].end) {
        (*sum) += tree[crtNode].data + tree[crtNode].segLen() * tree[crtNode].lazyTag;
        return;
    } else {
        auto mid = tree[2 * crtNode + 1].end;
        if (tree[crtNode].lazyTag != 0) {
            tree[crtNode].data += tree[crtNode].segLen() * tree[crtNode].lazyTag;
            tree[2 * crtNode + 1].lazyTag += tree[crtNode].lazyTag;
            tree[2 * crtNode + 2].lazyTag += tree[crtNode].lazyTag;
            tree[crtNode].lazyTag = 0;
        }
        if (askBegin < mid) {
            askIntervalSum(askBegin, std::min(mid, askEnd), tree, 2 * crtNode + 1, sum);
        }
        if (askEnd > mid) {
            askIntervalSum(std::max(mid, askBegin), askEnd, tree, 2 * crtNode + 2, sum);
        }
    }
}

void intervalPlus(LLU plus, int opBegin, int opEnd, SegTreeNode* tree, int crt) {
    if (opBegin == tree[crt].begin && opEnd == tree[crt].end) {
        if (tree[crt].end - tree[crt].begin == 1) {
            tree[crt].data += plus;
        } else {
            tree[crt].lazyTag += plus;
        }
    } else {
        auto mid = tree[2 * crt + 1].end;
        if (tree[crt].lazyTag != 0) {
            tree[crt].data += tree[crt].segLen() * tree[crt].lazyTag;
            tree[2 * crt + 1].lazyTag += tree[crt].lazyTag;
            tree[2 * crt + 2].lazyTag += tree[crt].lazyTag;
            tree[crt].lazyTag = 0;
        }
        if (opBegin < mid) {
            intervalPlus(plus, opBegin, std::min(mid, opEnd), tree, 2 * crt + 1);
        }
        if (opEnd > mid) {
            intervalPlus(plus, std::max(mid, opBegin), opEnd, tree, 2 * crt + 2);
        }
        tree[crt].data =
            tree[2 * crt + 1].data + tree[2 * crt + 1].lazyTag * tree[2 * crt + 1].segLen() 
            + tree[2 * crt + 2].data + tree[2 * crt + 2].lazyTag * tree[2 * crt + 2].segLen();
    }
}

signed main() {
    int numberNum, oprNum;
    LLU* array;
    scanf("%d %d", &numberNum, &oprNum);
    array = new LLU[numberNum];
    for (int i = 0; i < numberNum; i++) {
        scanf("%llu", &array[i]);
    }

    SegTreeNode* segTree = new SegTreeNode[4 * numberNum + 3]();
    buildSegTreeNode(array, 0, numberNum, segTree, 0);
    // prtSegTree(segTree, 4 * numberNum + 3);

    int mode;  // 1: add k for num in [x,y]; 2: print the sum in [x,y]
    int x, y;
    LLU k;
    for (int i = 0; i < oprNum; i++) {
        scanf("%d %d %d", &mode, &x, &y);
        --x;
        if (mode == 2) {
            LLU sum = 0;
            askIntervalSum(x, y, segTree, 0, &sum);
            // prtSegTree(segTree, 4 * numberNum + 3);
            printf("%llu\n", sum);
        } else {
            scanf("%llu", &k);
            intervalPlus(k, x, y, segTree, 0);
            // prtSegTree(segTree, 4 * numberNum + 3);
        }
    }
}