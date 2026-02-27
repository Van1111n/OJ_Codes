#include <iostream>
#include <string>
#define LLU unsigned long long

using namespace std;

//st[0] is the size of the stack, 
//st[1, 2 ... st[0]] are data.
void push(LLU n, LLU* st) {
    st[++st[0]] = n;
    return;
}
void pop(LLU* st) {
    if (st[0]!=0) {
        --st[0];
    } else {
        printf("Empty\n");
    }
}
void query(LLU* st) {
    if (st[0]) {
        printf("%llu\n", st[st[0]]);
    } else {
        printf("Anguei!\n");
    }
}
void size(LLU* st) {
    printf("%llu\n", st[0]);
}

int main() {
    LLU* stack = new LLU [1000000];
    int t, n;
    string s;
    LLU x;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        stack[0]=0;
        for (int i = 0; i < n; i++) {
            cin >> s;
            if (s=="push"){
                scanf("%llu", &x);
                push(x,stack);
            } else if (s=="query") {
                query(stack);
            } else if (s=="size") {
                size(stack);
            } else if (s=="pop") {
                pop(stack);
            } else {
                throw "wtf";
            }
        }
    }
}