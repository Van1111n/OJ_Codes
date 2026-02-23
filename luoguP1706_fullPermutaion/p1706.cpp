#include <iostream>

using namespace std;

void permutation(int layer, bool states[10], int ans[9], int n) {
    if (layer == n) {
        for (int i = 0; i < n; i++) {
            printf("%5d", ans[i]);
        }
        printf("\n");
        states[ans[n - 1]] = false;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (states[i] != 0)
            continue;
        ans[layer] = i;
        states[i] = 1;
        permutation(layer + 1, states, ans, n);
        states[i] = 0;
    }
}

int main() {
    int n;
    bool states[10] = {0};
    int ans[9] = {0};
    scanf("%d", &n);
    permutation(0, states, ans, n);
}
