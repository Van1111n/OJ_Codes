#include <climits>
#include <iostream>
#include <vector>

class BisectionTree {
    struct Node {
        int data;
        Node* lChild;
        Node* rChild;
    };

   private:
    Node* root;

    void insert(Node* node, int x) {
        if (x < node->data) {
            if (!node->lChild) {
                Node* newNode = new Node;
                newNode->lChild = nullptr, newNode->rChild = nullptr;
                newNode->data = x;
                node->lChild = newNode;
            } else {
                insert(node->lChild, x);
            }
        } else {
            if (!node->rChild) {
                Node* newNode = new Node;
                newNode->lChild = nullptr, newNode->rChild = nullptr;
                newNode->data = x;
                node->rChild = newNode;
            } else {
                insert(node->rChild, x);
            }
        }
    }

    int prev(Node* node, int x) {
        if (!node)
            return -2147483647;
        if (node->data < x) {
            return std::max(node->data, prev(node->rChild, x));
        } else {
            return prev(node->lChild, x);
        }
    }

    int next(Node* node, int x) {
        if (!node)
            return 2147483647;
        if (node->data > x) {
            return std::min(node->data, next(node->lChild, x));
        } else {
            return next(node->rChild, x);
        }
    }

    int nodeCount(Node* node) {
        if (!node)
            return 0;
        else
            return nodeCount(node->lChild) + nodeCount(node->rChild) + 1;
    }

    void toSortedVec(Node* node, std::vector<int>& vec) {
        if (!node) {
            return;
        } else {
            if (node->lChild) toSortedVec(node->lChild, vec);
            vec.push_back(node->data);
            if (node->rChild) toSortedVec(node->rChild, vec);
        }
    }

    std::vector<int> toSortedVec() {
        std::vector<int> vec;
        toSortedVec(root, vec);
        return vec;
    }

    int smallerElemCount(Node* node, int x) {
        if (!node)
            return 0;
        if (node->data < x) {
            return nodeCount(node->lChild) + 1 + smallerElemCount(node->rChild, x);
        } else if (node->data == x) {
            return nodeCount(node->lChild);
        } else {
            return smallerElemCount(node->lChild, x);
        }
    }

   public:
    BisectionTree() {
        root = nullptr;
    }

    inline void insert(int x) {
        if (!root) {
            root = new Node;
            root->lChild = root->rChild = nullptr;
            root->data = x;
        } else {
            insert(root, x);
        }
    }

    inline int prev(int x) {
        return prev(root, x);
    }

    inline int next(int x) {
        return next(root, x);
    }

    inline int nthElement(int n) {
        std::vector<int> vec = toSortedVec();
        return vec[n - 1];
    }

    inline int rank(int x) {
        return smallerElemCount(root, x)+1;
    }
};

int main() {
    int q;
    std::cin >> q;

    BisectionTree tree;
    int op, x;
    for (int i=0; i<q; i++) {
        std::cin >> op >> x;
        if (op == 1) {
            std::cout << tree.rank(x) << std::endl;
        } else if (op == 2) {
            std::cout << tree.nthElement(x) << std::endl;
        } else if (op == 3) {
            std::cout << tree.prev(x) << std::endl;
        } else if (op == 4) {
            std::cout << tree.next(x) << std::endl;
        } else {
            tree.insert(x);
        }
    }

    return 0;
}
