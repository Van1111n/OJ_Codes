#include <bits/stdc++.h>

using namespace std;

void prt(int min) {
    if (min < 0)
        min += 1440;
    int h = min / 60 % 24;
    int m = min % 60;
    printf("%d %d\n", h, m);
}

int main() {
    int a, b, m, c, d, k;
    scanf("%d %d %d %d %d %d", &a, &b, &m, &c, &d, &k);
    int takeOffTime = a * 60 + b;
    bool crossTimeZone = false;
    int crossTimeZoneTime = c * 60 + d;
    if (crossTimeZoneTime <= takeOffTime)
        crossTimeZoneTime += 1440;
    int curTime = takeOffTime + k;
    int n=m/k;
    for(int i=0; i<n;i++) {
        if (curTime > crossTimeZoneTime && crossTimeZone == false) {
            curTime -= 60;
            crossTimeZone = true;
        }
        prt(curTime);
        curTime += k;
    }
}