#include <iostream>

void add(int* res, int* aa, int* bb) {
    int a[1200], b[1200], rr[1200];
    for (int i = 0; i < 1200; i++) {
        a[i] = aa[i];
        b[i] = bb[i];
        rr[i] = 0;
    }
    for (int i = 0; i < 1200; i++) {
        rr[i] += a[i] + b[i];
        if (rr[i] >= 10) {
            rr[i + 1] += rr[i] / 10;
            rr[i] %= 10;
        }
    }
    for (int i = 0; i < 1200; i++)
        res[i] = rr[i];
    return;
}

void sub(int* res, int* aa, int* bb) {
    int a[1200], b[1200], rr[1200];
    for (int i = 0; i < 1200; i++) {
        a[i] = aa[i];
        b[i] = bb[i];
        rr[i] = 0;
    }
    for (int i = 0; i < 1200; i++) {
        rr[i] += a[i] - b[i];
        while (rr[i] < 0) {
            rr[i + 1]--;
            rr[i] += 10;
        }
    }
    for (int i = 0; i < 1200; i++)
        res[i] = rr[i];
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    if (n == 2) {
        printf("2\n");
        return 0;
    }
    int a[2][2][1200] = {0};
    a[0][0][0] = a[0][1][0] = a[1][0][0] = 1;
    for (int i = 0; i < n-1; i++) {
        add(a[0][0], a[0][0], a[0][1]);
        sub(a[0][1], a[0][0], a[0][1]);
        add(a[1][0], a[1][0], a[1][1]);
        sub(a[1][1], a[1][0], a[1][1]);
        continue;
    }
    int len=1200;
    while (a[0][0][--len]==0);
    while (len>=0){
        printf("%d",a[0][0][len--]);
    }
    return 0;
}