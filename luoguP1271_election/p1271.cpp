#include <iostream>

int main() {
    int buckets[1000] = {0};
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int cur;
        scanf("%d", &cur);
        buckets[cur]++;
    }
    for (int i=1; i<=n; i++){
        for (int j=0; j<buckets[i]; j++){
            printf("%d ", i);
        }
    }
    return 0;
}