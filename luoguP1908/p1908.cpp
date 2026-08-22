#include <cstring>
#include <iostream>

using llong = long long;

llong inv_pair(int* begin, int* end) {
    if (end - begin <= 1) {
        return 0;
    }
    std::size_t len = end - begin;
    int* mid = begin + len / 2;

    llong res = 0;
    res += inv_pair(begin, mid);
    res += inv_pair(mid, end);

    int *p = begin, *q = mid;
    int *reg = new int[len], *r = reg;
    while (p < mid && q < end) {
        if (*p <= *q) {
            *r = *p;
            res += q - mid;
            ++r, ++p;
        } else {
            *r = *q;
            ++r, ++q;
        }
    }
    while (p < mid) {
        *r = *p;
        res += q - mid;
        ++r, ++p;
    }
    while (q < end) {
        *r = *q;
        ++r, ++q;
    }
    memcpy(begin, reg, sizeof(int) * len);
    delete[] reg;
    return res;
}

int main() {
    int n;
    std::cin >> n;

    int* a = new int [n];
    for (std::size_t i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    llong ans = inv_pair(a, a + n);
    std::cout << ans << std::endl;

    return 0;
}