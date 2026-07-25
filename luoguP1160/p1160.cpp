#include <cstdio>
#include <cstdlib>

struct Node {
    int number;
    Node* l;
    Node* r;
};

Node* insert(Node* node, int number, int pos) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->number = number;
    if (pos == 0) {
        Node* temp = node->l;
        if (temp) temp->r = newNode;
        node->l = newNode;
        newNode->l = temp;
        newNode->r = node;
    } else {
        Node* temp = node->r;
        if (temp) temp->l = newNode;
        node->r = newNode;
        newNode->l = node;
        newNode->r = temp;
    }
    return newNode;
}

void erase(Node* node) {
    if (!node)
        return;
    Node *l = node->l, *r = node->r;
    free(node);
    if(l) l->r = r;
    if(r) r->l = l;
    return;
}

int main() {
    int n;
    scanf("%d", &n);

    Node* pHead = (Node*)malloc(sizeof(Node));
    pHead->l = NULL;
    pHead->r = NULL;
    pHead->number = 1;
    Node** address = (Node**)malloc((n + 5) * sizeof(Node*));
    address[1] = pHead;

    int k, p;
    for (int i=2; i<=n; i++) {
        scanf("%d %d", &k, &p);
        address[i] = insert(address[k], i, p);
    }

    int m;
    scanf("%d", &m);
    int x;
    for (int i=0; i<m; i++) {
        scanf("%d", &x);
        erase(address[x]);
        address[x]=NULL;
    }

    Node* front = pHead;
    while (front->l) front = front->l;
    Node* it = front;
    while (it) {
        printf("%d ", it->number);
        it=it->r;
    }
    putchar('\n');

    return 0;
}