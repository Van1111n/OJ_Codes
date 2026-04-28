#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if (8 <= a && b <= 12) {
        printf("M\n");
    } else if (13 <= a && b <= 17) {
        printf("A\n");
    } else if (18 <= a && b <= 21) {
        printf("E\n");
    } else
        printf("F\n");
    return 0;
}