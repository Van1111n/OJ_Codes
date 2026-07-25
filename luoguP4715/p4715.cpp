#include <iostream>

int main() {
    int n;
    std::cin >> n;
    n = 1 << n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int max1 = 0, max2 = 0;
    for (int i = 0; i < n / 2; i++) {
        max1 = std::max(max1, a[i]);
    }
    for (int i = n / 2; i < n; i++) {
        max2 = std::max(max2, a[i]);
    }
    int l, r;
    if (max1 < max2) {
        l = 0, r = n / 2;
    } else {
        l = n / 2, r = n;
    }
    while (r - l > 1) {
        max1 = 0, max2 = 0;
        for (int i = l; i < (r + l) / 2; i++) {
            max1 = std::max(max1, a[i]);
        }
        for (int i = (r + l) / 2; i < r; i++) {
            max2 = std::max(max2, a[i]);
        }
        if (max1 > max2) {
            r = (l + r) / 2;
        } else {
            l = (r + l) / 2;
        }
    }
    std::cout << ++l;
}