#include <cmath>
#include <iostream>
#include <climits>

using namespace std;

int main() {
    int n, m;
    long long s;
    int *w, *v, *l, *r;
    int wMin = INT_MAX, wMax = INT_MIN;
    scanf("%d %d %lld", &n, &m, &s);
    w = (int*)malloc(n * sizeof(int));
    v = (int*)malloc(n * sizeof(int));
    l = (int*)malloc(m * sizeof(int));
    r = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &w[i], &v[i]);
        wMin = w[i] < wMin ? w[i] : wMin;
        wMax = w[i] > wMax ? w[i] : wMax;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &l[i], &r[i]);
        --l[i];
        --r[i];
    }

    int* wps;
    long long* vps;
    wps = (int*)malloc(n * sizeof(int));
    vps = (long long*)malloc(n * sizeof(long long));
    int weight;
    long long yl=0, yr=0;

    weight = wMin;
    for (int i = 0; i < n; i++) {
        wps[i] = (i > 0 ? wps[i - 1] : 0) + (w[i] >= weight ? 1 : 0);
        vps[i] = (i > 0 ? vps[i - 1] : 0) + (w[i] >= weight ? v[i] : 0);
    }
    for (int i = 0; i < m; i++) {
        yl += (wps[r[i]] - (l[i] > 0 ? wps[l[i] - 1] : 0)) * (vps[r[i]] - (l[i] > 0 ? vps[l[i] - 1] : 0));
    }
    //printf("gugugaga:%d %d\n", weight, yl);
    weight = wMax;
    for (int i = 0; i < n; i++) {
        wps[i] = (i > 0 ? wps[i - 1] : 0) + (w[i] >= weight ? 1 : 0);
        vps[i] = (i > 0 ? vps[i - 1] : 0) + (w[i] >= weight ? v[i] : 0);
    }
    for (int i = 0; i < m; i++) {
        yr += (wps[r[i]] - (l[i] > 0 ? wps[l[i] - 1] : 0)) * (vps[r[i]] - (l[i] > 0 ? vps[l[i] - 1] : 0));
    }
    //printf("gugugaga:%d %d\n", weight, yr);

    while (wMax - wMin > 1) {
        weight = (wMin + wMax) / 2;
        for (int i = 0; i < n; i++) {
            wps[i] = (i > 0 ? wps[i - 1] : 0) + (w[i] >= weight ? 1 : 0);
            vps[i] = (i > 0 ? vps[i - 1] : 0) + (w[i] >= weight ? v[i] : 0);
        }
        long long y = 0;
        for (int i = 0; i < m; i++) {
            y += (wps[r[i]] - (l[i] > 0 ? wps[l[i] - 1] : 0)) * (vps[r[i]] - (l[i] > 0 ? vps[l[i] - 1] : 0));
        }
        //printf("gugugaga:%d %d\n", weight, y);
        if (y == s) {
            printf("0");
            return 0;
        }
        if (y > s) {
            wMin = weight;
            yl = y;
        } else {
            wMax = weight;
            yr = y;
        }
    }
    printf("%lld\n", abs(yl - s) < abs(yr - s) ? abs(yl - s) : abs(yr - s));
    return 0;
}