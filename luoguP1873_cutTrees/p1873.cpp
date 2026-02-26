#include <iostream>
#include <climits>

using namespace std;

int main() {
    int n, m;
    int* hs;
    int hl, hr, h;
    long long y;
    hl = INT_MAX;
    hr = INT_MIN;
    scanf("%d %d", &n, &m);
    hs = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &hs[i]);
        hl = hs[i] < hl ? hs[i] : hl;
        hr = hs[i] > hr ? hs[i] : hr;
    }
    while (hr - hl > 1) {
        h = (hl + hr) / 2;
        y = 0;
        for (int i = 0; i < n; i++) {
            y += hs[i] > h ? hs[i] - h : 0;
        }
        //printf("between:%d, %d, height:%d, length:%d\n", hl, hr, h, y);
        if (y < m) {
            hr = h - 1;
        } else if (y > m) {
            hl = h;
        } else {
            printf("%d\n", h);
            return 0;
        }
    }
    if (hl == hr) {
        printf("%d\n", hl);
        return 0;
    }
    long long z=0;
    for (int i=0; i<n; i++){
        z += hs[i] > hr ? hs[i] - hr : 0;
    }
    if (z>=m) {
        printf("%d\n", hr);
    } else {
        printf("%d\n", hl);
    }
    return 0;
}