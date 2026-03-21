#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double a[1000];
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
        sum += a[i];
    }
    double avg = (double)sum / n;
    double sqsum = 0;
    for (int i = 0; i < n; i++) {
        sqsum += ((double)a[i] - avg) * ((double)a[i] - avg);
    }
    double d = sqsum / n;
    for (int i = 0; i < n; i++) {
        a[i] = (a[i] - avg) / sqrt(d);
        printf("%lf\n", a[i]);
    }
    return 0;
}