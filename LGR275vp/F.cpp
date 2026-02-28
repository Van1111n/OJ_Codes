#include <iostream>

using namespace std;

int main() {
    int n, m, d0, d;
    int l[250001];
    int count = 0;
    scanf("%d %d %d", &n, &m, &d0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &l[i % 2 == 0 ? i * m + j : i * m + m - 1 - j]);
        }
    }
    d=d0;
    for (int i = 0; i < n * m; i++) {
        if (d>0){
            d--;
            if (l[i]==1) count++;
        } else {
            if (l[i]==1) {
                d=d0;
                count++;
                d--;
            } else {
                break;
            }
        }
    }
    printf("%d", count);
    return 0;
}