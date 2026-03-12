#include <iostream>
#include <cctype>
#define LLU unsigned long long
#define P 1000003

// fast read unsigned long long
char buf[1 << 23], *p1 = buf, *p2 = buf;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
inline unsigned long long rd() {  // 读入一个 64 位无符号整数
    unsigned long long x = 0;
    char ch = gc();
    while (!isdigit(ch))
        ch = gc();
    while (isdigit(ch))
        x = x * 10 + (ch ^ 48), ch = gc();
    return x;
}

struct HashTable {
    struct Node {
        LLU key, value;
        Node* next;
    };
    Node** heads;

    LLU f(LLU key) {
        return key % P;
    }

    void init() {
        heads = (Node**)malloc(P * sizeof(Node*));
        for (int i = 0; i < P; i++) {
            heads[i] = NULL;
        }
    }
    // search the data with key x
    // if found, return the value and update it to y
    // else add a new node with key x and value y
    LLU search(LLU x, LLU y) {
        Node* p = heads[f(x)];
        if (p == NULL) {
            heads[f(x)] = (Node*)malloc(sizeof(Node));
            heads[f(x)]->key = x;
            heads[f(x)]->value = y;
            heads[f(x)]->next = NULL;
            return 0;
        } else {
            while (1) {
                if (p->key == x) {
                    LLU temp = p->value;
                    p->value = y;
                    return temp;
                }
                if (p->next == NULL) {
                    break;
                }
                p = p->next;
            }
            p->next = (Node*)malloc(sizeof(Node));
            p->next->key = x;
            p->next->value = y;
            p->next->next = NULL;
            return 0;
        }
    }
};

int main() {
    int n;
    LLU x, y;
    LLU res = 0;
    HashTable map;
    map.init();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%llu %llu", &x, &y);
        res += (i + 1) * map.search(x, y);
    }
    printf("%llu", res);
    return 0;
}