#include <iostream>
#define LLU unsigned long long
#define P 97

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

    LLU get(LLU key) {
        Node* p = heads[f(key)];
        while (p) {
            if (p->key == key)
                return p->value;
            else
                p = p->next;
        }
        printf("Not found\n");
        return 0;
    }

    LLU add(LLU key, LLU value) {
        Node* p = heads[f(key)];
        if (p == NULL) {
            heads[f(key)] = (Node*)malloc(sizeof(Node));
            heads[f(key)]->key = key;
            heads[f(key)]->value = value;
            heads[f(key)]->next = NULL;
        } else {
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = (Node*)malloc(sizeof(Node));
            p->next->key = key;
            p->next->value = value;
            p->next->next = NULL;
        }
        return value;
    }
};

int main() {
    HashTable map;

}