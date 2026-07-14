#include <iostream>
#include <stack>

struct Tower {
    int h;  // height
    int v;  // radiEnergy
};

int main() {
    int n;
    scanf("%d", &n);

    int* e = new int[n]{0};
    Tower* towers = new Tower[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &towers[i].h, &towers[i].v);
    }

    std::stack<Tower> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top().h < towers[i].h) {
            e[i] += st.top().v;
            st.pop();
        }
        st.push(towers[i]);
    }

    while (!st.empty()) {
        st.pop();
    }  // clear stack
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top().h < towers[i].h) {
            e[i]+= st.top().v;
            st.pop();
        }
        st.push(towers[i]);
    }

    int eMax = 0;
    for (int i=0; i<n; i++){
        eMax = std::max(eMax, e[i]);
    }

    printf("%d\n", eMax);
    return 0;
}