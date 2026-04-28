#include <iostream>
#define M 1000
#define N 500000

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int k[M] = {0};
    for (int i = 0; i < m; i++) {
        scanf("%d", &k[i]);
    }
    int arr[N] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        int gxk = arr[i];
        for (int j = m - 1; j >= 0; j--) {
            int b = gxk >> 6;
            int c = (gxk % 64 / 8) ^ (((b * b + k[j] * k[j]) % 8) ^ k[j]);
            int a = (gxk % 8) ^ (((c * c + k[j] * k[j]) % 8) ^ k[j]);
            gxk = c + b *8 + a * 64;
        }
        printf("%d ", gxk);
    }
    return 0;
}