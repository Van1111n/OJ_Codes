#include <iostream>

using namespace std;

int main() {
    int n, k;
    int* m;
    scanf("%d %d", &n, &k);
    m = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &m[i]);
        m[i]=k-m[i];
    }
    int sum = 0;
    for (int i=0; i<n; i++){
        sum+=m[i];
    }
    int ans = max(k-sum,0);
    printf("%d", ans);
    return 0;
}