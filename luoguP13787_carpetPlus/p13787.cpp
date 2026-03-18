#include <iostream>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int** a = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        for (int j = 0; j < n; j++){
            a[i][j] = 0;
        }
    }
    for (int i=0; i<m; i++){
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        --x1, --y1, --x2, --y2;
        ++a[x1][y1];
        if (x2 + 1 < n)
            --a[x2 + 1][y1];
        if (y2 + 1 < n)
            --a[x1][y2 + 1];
        if (x2 + 1 < n && y2 + 1 < n)
            ++a[x2 + 1][y2 + 1];
    }
    long long ans = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            a[i][j] = a[i][j] + (j - 1 >= 0 ? a[i][j - 1] : 0) + (i - 1 >= 0 ? a[i - 1][j] : 0) - (i - 1 >= 0 && j - 1 >= 0 ? a[i - 1][j - 1] : 0);
            ans += (i+j+2)^a[i][j];
        }
    }
    printf("%lld", ans);
    return 0;
}