#include <iostream>
#include <vector>

struct Node {
    int min;
    int l;
    int r;
};

void buildSegTree(Node* nodes, int crt, int* arr, int begin, int end) {
    auto& c = nodes[crt];
    c.l = begin;
    c.r = end;
    if (end - begin == 1) {
        c.min = arr[begin];
        return;
    }
    auto mid = (end + begin) / 2;
    buildSegTree(nodes, 2 * crt + 1, arr, begin, mid);
    buildSegTree(nodes, 2 * crt + 2, arr, mid, end);
    c.min = std::min(nodes[2 * crt + 1].min, nodes[2 * crt + 2].min);
}

Node* buildSegTree(int* array, int n) {
    Node* nodes = new Node[4 * n + 6];
    buildSegTree(nodes, 0, array, 0, n);
}

// TODO:
